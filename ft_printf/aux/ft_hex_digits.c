/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_digits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:32:33 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/07 15:17:25 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "aux.h"

int	ft_hex_digits(uintmax_t num)
{
	int len;

	len = !num ? 1 : 0;
	while (num)
	{
		len += 1;
		num >>= 4;
	}
	return (len);
}
