/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 11:22:55 by nmandlan          #+#    #+#             */
/*   Updated: 2018/05/28 11:18:53 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *str1;
	char *str2;

	str1 = (char*)dst;
	str2 = (char*)src;
	if (str2 < str1)
	{
		while (len--)
		{
			str1[len] = str2[len];
		}
	}
	else
	{
		ft_memcpy(str1, str2, len);
	}
	return (str1);
}
