/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:43:12 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/07 14:58:40 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "aux.h"

int			handle_decimal(va_list arg, t_printf *ptr)
{
	int		len;

	len = 0;
	if (ptr->flags & LOW_D_BIT || ptr->flags & LOW_I_BIT || \
			ptr->flags & UPP_D_BIT)
		len = ft_signed_number(arg, ptr);
	if (ptr->flags & LOW_U_BIT || ptr->flags & UPP_U_BIT)
		len = ft_unsigned_number(arg, ptr);
	return (len);
}

int			handle_octal(va_list arg, t_printf *ptr)
{
	int len;

	len = 0;
	if (ptr->flags & J)
		len = ft_unsigned_format(va_arg(arg, uintmax_t), ptr, &octal);
	else if (ptr->flags & Z)
		len = ft_unsigned_format(va_arg(arg, size_t), ptr, &octal);
	else if (ptr->flags & LL)
		len = ft_unsigned_format(va_arg(arg, unsigned long long), ptr, \
				&octal);
	else if (ptr->flags & L || ptr->flags & UPP_O_BIT)
		len = ft_unsigned_format(va_arg(arg, unsigned long), ptr, &octal);
	else if (ptr->flags & H)
		len = ft_unsigned_format((unsigned short)va_arg(arg, unsigned int), \
				ptr, &octal);
	else if (ptr->flags & HH)
		len = ft_unsigned_format((unsigned char)va_arg(arg, unsigned int), \
				ptr, &octal);
	else
		len = ft_unsigned_format(va_arg(arg, unsigned int), ptr, &octal);
	return (len);
}

int			handle_binary(va_list arg, t_printf *ptr)
{
	int len;

	len = 0;
	if (ptr->flags & J)
		len = ft_unsigned_format(va_arg(arg, uintmax_t), ptr, &binary);
	else if (ptr->flags & Z)
		len = ft_unsigned_format(va_arg(arg, size_t), ptr, &binary);
	else if (ptr->flags & LL)
		len = ft_unsigned_format(va_arg(arg, unsigned long long), ptr, \
				&binary);
	else if (ptr->flags & L || ptr->flags & UPP_O_BIT)
		len = ft_unsigned_format(va_arg(arg, unsigned long), ptr, &binary);
	else if (ptr->flags & H)
		len = ft_unsigned_format((unsigned short)va_arg(arg, unsigned int), \
				ptr, &binary);
	else if (ptr->flags & HH)
		len = ft_unsigned_format((unsigned char)va_arg(arg, unsigned int), \
				ptr, &binary);
	else
		len = ft_unsigned_format(va_arg(arg, unsigned int), ptr, &binary);
	return (len);
}

int			handle_hexadecimal(va_list arg, t_printf *ptr)
{
	int len;

	len = 0;
	if (ptr->flags & LOW_P_BIT)
		len = ft_unsigned_format((uintmax_t)va_arg(arg, void*), ptr, &hex);
	else if (ptr->flags & J)
		len = ft_unsigned_format(va_arg(arg, uintmax_t), ptr, &hex);
	else if (ptr->flags & Z)
		len = ft_unsigned_format(va_arg(arg, size_t), ptr, &hex);
	else if (ptr->flags & LL)
		len = ft_unsigned_format(va_arg(arg, unsigned long long), ptr, &hex);
	else if (ptr->flags & L)
		len = ft_unsigned_format(va_arg(arg, unsigned long), ptr, &hex);
	else if (ptr->flags & H)
		len = ft_unsigned_format((unsigned short)va_arg(arg, unsigned int), \
				ptr, &hex);
	else if (ptr->flags & HH)
		len = ft_unsigned_format((unsigned char)va_arg(arg, unsigned int), \
				ptr, &hex);
	else
		len = ft_unsigned_format(va_arg(arg, unsigned int), ptr, &hex);
	return (len);
}
