/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:33:24 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/07 15:37:00 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "aux.h"

int	ft_unsigned_format(uintmax_t num, t_printf *ptr, \
		char *(*convert)(uintmax_t, int*))
{
	int		len;
	int		sign;
	int		zeroes;
	int		spaces;
	char	*ret;

	ret = convert(num, &len);
	sign = ft_decimal_type(num, ptr->flags, ptr->precision);
	if (ptr->flags & LOW_X_BIT || ptr->flags & LOW_P_BIT)
		ft_tolower(ret);
	(ptr->flags & PRECISION && !ptr->precision && !num) ? len = 0 : len;
	len += sign;
	zeroes = ft_get_zeroes(ptr, &len, (sign == 2) ? 2 : 0);
	spaces = ft_get_spaces(ptr->flags, ptr->width, &len);
	!(ptr->flags & MINUS) ? ft_putnchar(' ', spaces) : 0;
	ft_decimal_type(num, ptr->flags, ptr->precision) ? ft_putchar('0') : 0;
	if (ft_decimal_type(num, ptr->flags, ptr->precision) > 1)
		ptr->flags & UPP_X_BIT ? ft_putchar('X') : ft_putchar('x');
	ft_putnchar('0', zeroes);
	if (!(ptr->flags & PRECISION && !ptr->precision && !num))
		ft_putstr(ret);
	free(ret);
	(ptr->flags & MINUS) ? ft_putnchar(' ', spaces) : 0;
	return (len);
}
