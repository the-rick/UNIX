/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:31:25 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/07 15:08:40 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

char	*ft_get_hex(uintmax_t num, char *hex, char *str)
{
	int i;
	int len;

	i = 0;
	len = !num ? 1 : 0;
	while (num)
	{
		hex[len++] = str[num & 0xF];
		num >>= 4;
	}
	while (i < (len / 2))
	{
		hex[i] ^= hex[len - i - 1];
		hex[len - i - 1] ^= hex[i];
		hex[i] ^= hex[len - i - 1];
		i += 1;
	}
	return (hex);
}
