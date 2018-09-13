/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 12:52:46 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/10 12:36:21 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"
#include "ft_printf.h"

static int			get_length(char *conversion, t_printf *ptr)
{
	int	len;

	len = 0;
	while (conversion[len] == 'h' || conversion[len] == 'l' \
			|| conversion[len] == 'j' || conversion[len] == 'z')
	{
		if (conversion[len] == 'h')
			conversion[len + 1] == 'h' \
				? (ptr->flags |= HH) : (ptr->flags |= H);
		if (conversion[len] == 'l')
			conversion[len + 1] == 'l' \
				? (ptr->flags |= LL) : (ptr->flags |= L);
		if (ptr->flags == HH || ptr->flags == LL)
			len += 1;
		if (conversion[len] == 'j')
			ptr->flags |= J;
		if (conversion[len] == 'z')
			ptr->flags |= Z;
		len += 1;
	}
	return (len);
}

static int			get_width(va_list arg, char *format, t_printf *ptr)
{
	int		width;
	char	*num;

	width = 0;
	if (format[width] == '*')
	{
		ptr->width = va_arg(arg, int);
		if (ptr->width < 0)
		{
			ptr->width *= -1;
			ptr->flags |= MINUS;
		}
		width = 1;
	}
	else
	{
		while (ft_isdigit(format[width]))
			width += 1;
		if (!width || !(num = ft_strsub(format, 0, width)))
			return (0);
		ptr->width = ft_atoi(num);
		free(num);
	}
	return (width);
}

static int			get_precision(va_list arg, char *format, t_printf *ptr)
{
	int		precision;
	char	*num;

	precision = 0;
	if (format[0] == '.')
	{
		precision = 1;
		if (format[precision] == '*')
		{
			ptr->precision = va_arg(arg, int);
			precision += 1;
		}
		else
		{
			while (ft_isdigit(format[precision]))
				precision += 1;
			if (!(num = ft_strsub(format, 1, precision)))
				return (0);
			ptr->precision = (precision != 1) ? ft_atoi(num) : 0;
			free(num);
		}
	}
	return (precision);
}

static int			get_flags(char flg, t_printf *ptr)
{
	flg == '#' ? ptr->flags |= HASH : 0;
	flg == '0' ? ptr->flags |= ZERO : 0;
	flg == '-' ? ptr->flags |= MINUS : 0;
	flg == ' ' ? ptr->flags |= SPACE : 0;
	flg == '+' ? ptr->flags |= PLUS : 0;
	return (flg == '#' || flg == '0' || flg == '-' || flg == ' ' || flg == '+');
}

int					parse_attributes(char **format, va_list arg, t_printf *ptr)
{
	char	*start;
	int		width;

	width = 0;
	start = *format;
	while (get_flags(**format, ptr))
		(*format)++;
	while ((width = get_width(arg, *format, ptr)))
	{
		ptr->flags |= WIDTH;
		(*format) += width;
	}
	while ((width = get_precision(arg, *format, ptr)))
	{
		if (ptr->precision >= 0)
			ptr->flags |= PRECISION;
		(*format) += width;
	}
	while ((width = get_length(*format, ptr)))
		(*format) += width;
	return (*format > start);
}
