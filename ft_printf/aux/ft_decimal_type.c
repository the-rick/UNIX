/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:31:13 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/07 15:18:26 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "aux.h"

int	ft_decimal_type(uintmax_t num, int attr, int prec)
{
	if ((attr & LOW_O_BIT || attr & UPP_O_BIT) && attr & HASH \
			&& (num || (!num && attr & PRECISION && !prec)))
		return (1);
	if (((attr & LOW_X_BIT || attr & UPP_X_BIT) && attr & HASH && num) \
			|| attr & LOW_P_BIT)
		return (2);
	return (0);
}
