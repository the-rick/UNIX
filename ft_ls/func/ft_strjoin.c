/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:26:00 by nmandlan          #+#    #+#             */
/*   Updated: 2018/05/31 14:34:57 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len;
	char	*fresh;

	i = 0;
	if (s1 == NULL || s2 == NULL)
	{
		return (NULL);
	}
	len = (ft_strlen((char*)s1) + ft_strlen((char*)s2));
	fresh = (char*)malloc(sizeof(fresh) * len);
	if (!fresh)
	{
		return (NULL);
	}
	while (*s1)
	{
		fresh[i++] = *s1++;
	}
	while (*s2)
	{
		fresh[i++] = *s2++;
	}
	fresh[i] = '\0';
	return (fresh);
}
