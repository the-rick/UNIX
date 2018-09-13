/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 10:36:02 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/07 15:45:36 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

static int	code_to_utf8(wchar_t wc, char *encode)
{
	int size;

	size = 0;
	if (wc <= 0xFF)
		encode[size++] = wc;
	else if (wc < 0x0800)
	{
		encode[size++] = ((wc >> 6) & 0x1F) | 0xC0;
		encode[size++] = ((wc >> 0) & 0x3F) | 0x80;
	}
	else if (wc < 0x010000)
	{
		encode[size++] = ((wc >> 12) & 0x0F) | 0xE0;
		encode[size++] = ((wc >> 6) & 0x3F) | 0x80;
		encode[size++] = ((wc >> 0) & 0x3F) | 0x80;
	}
	else if (wc < 0x110000)
	{
		encode[size++] = ((wc >> 18) & 0x07) | 0xF0;
		encode[size++] = ((wc >> 12) & 0x3F) | 0x80;
		encode[size++] = ((wc >> 6) & 0x3F) | 0x80;
		encode[size++] = ((wc >> 0) & 0x3F) | 0x80;
	}
	return (size);
}

int			ft_putwchar(wchar_t wc)
{
	int		len;
	char	encoded[4];

	len = code_to_utf8(wc, encoded);
	write(1, encoded, len);
	return (len);
}
