/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 14:16:40 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/07 10:25:20 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/aux.h"

wchar_t		*ft_wcsncpy(wchar_t *dst, const wchar_t *src, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (j < n)
	{
		j += ft_wclen(src[i]);
		if (j > n)
			break ;
		dst[i] = src[i];
		dst[++i] = L'\0';
	}
	return (dst);
}
