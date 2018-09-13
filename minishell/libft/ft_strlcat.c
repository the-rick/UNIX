/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 12:43:21 by nmandlan          #+#    #+#             */
/*   Updated: 2018/05/24 15:53:03 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t dstlen;
	size_t srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize <= dstlen)
	{
		return (srclen + dstsize);
	}
	i = 0;
	while (dst[i] && i < (dstsize - 1))
	{
		i++;
	}
	while (*src && i < (dstsize - 1))
	{
		dst[i] = *src++;
		i++;
	}
	dst[i] = '\0';
	return (dstlen + srclen);
}
