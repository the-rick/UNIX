/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:42:58 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/07 15:00:05 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "aux.h"

int		get_spaces(int width, int len, int attr)
{
	while ((width - len) > 0)
	{
		ft_putchar(((attr & ZERO) && !(attr & MINUS)) ? '0' : ' ');
		len += 1;
	}
	return (len);
}

int		handle_wide_strings(va_list arg, t_printf *ptr)
{
	int		len;
	wchar_t	*str;
	wchar_t	*copy;

	if (!(str = va_arg(arg, wchar_t*)))
		str = ft_wcsdup(L"(null)");
	if (ptr->flags & PRECISION)
	{
		copy = ft_wcsnew(ptr->precision);
		if (str)
			copy = ft_wcsncpy(copy, str, ptr->precision);
		str = copy;
	}
	len = ft_wcslen(str);
	if (!(ptr->flags & MINUS))
		len = get_spaces(ptr->width, len, ptr->flags);
	ft_putwstr(str);
	if (ptr->flags & MINUS)
		len = get_spaces(ptr->width, len, ptr->flags);
	return (len);
}

int		handle_wide_chars(va_list arg, t_printf *ptr)
{
	int		len;
	wchar_t	c;

	c = va_arg(arg, wint_t);
	len = ft_wclen(c);
	if (!(ptr->flags & MINUS))
		len = get_spaces(ptr->width, len, ptr->flags);
	ft_putwchar(c);
	if (ptr->flags & MINUS)
		len = get_spaces(ptr->width, len, ptr->flags);
	return (len);
}

int		handle_strings(va_list arg, t_printf *ptr)
{
	int		len;
	char	*str;
	char	*copy;

	if (ptr->flags & L)
		return (handle_wide_strings(arg, ptr));
	if (!(str = va_arg(arg, char*)))
		str = ft_strdup("(null)");
	if (ptr->flags & PRECISION)
	{
		if (!(copy = (char*)malloc(sizeof(char) * ptr->precision)))
			return (0);
		copy = ft_strncpy(copy, str, ptr->precision);
		str = copy;
	}
	len = ft_strlen(str);
	if (!(ptr->flags & MINUS))
		len = get_spaces(ptr->width, len, ptr->flags);
	ft_putstr(str);
	if (ptr->flags & MINUS)
		len = get_spaces(ptr->width, len, ptr->flags);
	return (len);
}

int		handle_characters(va_list arg, t_printf *ptr)
{
	int		len;
	char	c;

	if (ptr->flags & L)
		return (handle_wide_chars(arg, ptr));
	c = va_arg(arg, int);
	len = sizeof(char);
	if (!(ptr->flags & MINUS))
		len = get_spaces(ptr->width, len, ptr->flags);
	ft_putchar(c);
	if (ptr->flags & MINUS)
		len = get_spaces(ptr->width, len, ptr->flags);
	return (len);
}
