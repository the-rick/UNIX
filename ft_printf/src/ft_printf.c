/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:41:31 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/10 11:44:59 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"
#include "ft_printf.h"

static int		no_specifier(char c, t_printf *ptr)
{
	int len;

	len = 0;
	if (!(ptr->flags & MINUS))
		len = get_spaces(ptr->width, sizeof(char), ptr->flags);
	ft_putchar(c);
	if (ptr->flags & MINUS)
		len = get_spaces(ptr->width, sizeof(char), ptr->flags);
	return (len);
}

static int		print_specifier(char format, va_list arg, t_printf *ptr, int i)
{
	int print;

	print = 0;
	if (i == LOW_S)
		print = handle_strings(arg, ptr);
	else if (i == UPPER_S)
		print = handle_wide_strings(arg, ptr);
	else if ((i == LOW_D || i == UPPER_D || i == LOW_I) \
			|| (i == LOW_U || i == UPPER_U))
		print = handle_decimal(arg, ptr);
	else if (i == LOW_O || i == UPPER_O)
		print = handle_octal(arg, ptr);
	else if (i == LOW_P || i == LOW_X || i == UPPER_X)
		print = handle_hexadecimal(arg, ptr);
	else if (i == LOW_C)
		print = handle_characters(arg, ptr);
	else if (i == UPPER_C)
		print = handle_wide_chars(arg, ptr);
	else if (i == LOW_B)
		print = handle_binary(arg, ptr);
	else
		print = no_specifier(format, ptr);
	return (print);
}

static int		std_out(const char **format, va_list arg)
{
	int			specifier;
	t_printf	member;

	member.flags = 0;
	member.width = 0;
	member.precision = 0;
	specifier = 0;
	specifier = return_specifier(arg, (char**)format, &member);
	if (!**format)
		return (FAIL);
	return (print_specifier((char)**format, arg, &member, specifier));
}

int				ft_printf(const char *format, ...)
{
	int			len;
	int			i;
	va_list		arg;

	len = 0;
	i = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format += 1;
			if ((i = std_out(&format, arg)) == FAIL)
				break ;
			len += i;
		}
		else
		{
			ft_putchar(*format);
			len += 1;
		}
		format += 1;
	}
	va_end(arg);
	return (len);
}
