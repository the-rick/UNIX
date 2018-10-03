/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:08:30 by nmandlan          #+#    #+#             */
/*   Updated: 2018/05/30 14:49:59 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (*s2 == '\0')
	{
		return ((char*)s1);
	}
	i = 0;
	while (*s1 && n)
	{
		if (*s1 == s2[i])
		{
			i++;
		}
		if (s2[i] == '\0')
		{
			return ((char*)s1 - i + 1);
		}
		s1++;
		n--;
	}
	return (NULL);
}
