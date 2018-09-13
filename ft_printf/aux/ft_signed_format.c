/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:33:07 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/07 15:26:42 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "aux.h"

static int		digit_size(intmax_t num)
{
	int len;

	if (!num)
		return (1);
	len = num < 0 ? 1 : 0;
	while (num)
	{
		num /= 10;
		len += 1;
	}
	return (len);
}

static void		put_sign(intmax_t num, int attr)
{
	char sign;

	sign = 0;
	if (num < 0)
		sign = '-';
	else if (num >= 0)
	{
		if (attr & PLUS)
			sign = '+';
		else if (attr & SPACE)
			sign = ' ';
	}
	if (sign)
		ft_putchar(sign);
}

int				ft_signed_format(intmax_t num, t_printf *ptr)
{
	int	len;
	int	sign;
	int	zeroes;
	int	spaces;

	len = 0;
	sign = (num >= 0 && (ptr->flags & PLUS || ptr->flags & SPACE)) ? 1 : 0;
	if (!(ptr->flags & PRECISION) || ptr->precision || num)
		len = digit_size(num);
	len += sign;
	zeroes = ft_get_zeroes(ptr, &len, (num < 0 || sign));
	spaces = ft_get_spaces(ptr->flags, ptr->width, &len);
	!(ptr->flags & MINUS) ? ft_putnchar(' ', spaces) : 0;
	put_sign(num, ptr->flags);
	ft_putnchar('0', zeroes);
	if (!(ptr->flags & PRECISION && !ptr->precision && !num))
		ft_putnbr((num < 0) ? (-num) : (num));
	(ptr->flags & MINUS) ? ft_putnchar(' ', spaces) : 0;
	return (len);
}
