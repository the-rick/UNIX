/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:30:37 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/10 11:39:20 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"
#include "ft_printf.h"

char	*hex(uintmax_t num, int *num_digits)
{
	char	*hex_num;
	char	*hex_str;

	*num_digits = ft_hex_digits(num);
	hex_num = NULL;
	if (!(hex_num = ft_memalloc(sizeof(char) * (*num_digits) + 1)))
		return (NULL);
	*hex_num = '0';
	if (!(hex_str = ft_strdup("0123456789ABCDEF")))
		return (NULL);
	hex_num = ft_get_hex(num, hex_num, hex_str);
	free(hex_str);
	return (hex_num);
}
