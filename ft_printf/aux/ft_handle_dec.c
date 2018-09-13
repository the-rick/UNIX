/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:32:16 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/07 15:16:47 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "aux.h"

static char		*ft_convert_dec(uintmax_t num, int *size)
{
	return (ft_convert_number(num, size, 10));
}

int				ft_signed_number(va_list arg, t_printf *ptr)
{
	int len;

	len = 0;
	if (ptr->flags & J || ptr->flags & Z)
		len = ft_signed_format(va_arg(arg, intmax_t), ptr);
	else if (ptr->flags & LL)
		len = ft_signed_format(va_arg(arg, long long), ptr);
	else if (ptr->flags & L || ptr->flags & UPP_D_BIT)
		len = ft_signed_format(va_arg(arg, long), ptr);
	else if (ptr->flags & HH)
		len = ft_signed_format((char)va_arg(arg, int), ptr);
	else if (ptr->flags & H)
		len = ft_signed_format((short)va_arg(arg, int), ptr);
	else
		len = ft_signed_format(va_arg(arg, int), ptr);
	return (len);
}

int				ft_unsigned_number(va_list arg, t_printf *ptr)
{
	int len;

	len = 0;
	if (ptr->flags & J)
		len = ft_unsigned_format(va_arg(arg, uintmax_t), ptr, &ft_convert_dec);
	else if (ptr->flags & Z)
		len = ft_unsigned_format(va_arg(arg, size_t), ptr, &ft_convert_dec);
	else if (ptr->flags & LL)
		len = ft_unsigned_format(va_arg(arg, unsigned long long), ptr,
				&ft_convert_dec);
	else if (ptr->flags & L || ptr->flags & UPP_U_BIT)
		len = ft_unsigned_format(va_arg(arg, unsigned long), ptr, \
				&ft_convert_dec);
	else if (ptr->flags & HH)
		len = ft_unsigned_format((unsigned char)va_arg(arg, unsigned int), \
				ptr, &ft_convert_dec);
	else if (ptr->flags & H)
		len = ft_unsigned_format((unsigned short)va_arg(arg, unsigned int), \
				ptr, &ft_convert_dec);
	else
		len = ft_unsigned_format(va_arg(arg, unsigned int), ptr, \
				&ft_convert_dec);
	return (len);
}
