/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_zeroes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:31:58 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/07 15:13:18 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "aux.h"

int	ft_get_zeroes(t_printf *ptr, int *len, int sign)
{
	int zeroes;

	zeroes = 0;
	if (ptr->flags & PRECISION && ptr->precision > *len - sign)
	{
		zeroes += ptr->precision - *len + sign;
		*len += zeroes;
	}
	if (ptr->flags & WIDTH && ptr->flags & ZERO && !(ptr->flags & MINUS) \
			&& !(ptr->flags & PRECISION) && ptr->width > *len)
	{
		zeroes += ptr->width - *len;
		*len += zeroes;
	}
	return (zeroes);
}
