/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 10:10:21 by nmandlan          #+#    #+#             */
/*   Updated: 2018/05/29 11:25:11 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*fresh;

	if (!s)
	{
		return (NULL);
	}
	fresh = (char*)malloc(sizeof(char) * (len + 1));
	if (!fresh)
	{
		return (NULL);
	}
	i = 0;
	while (i < len && s[start] != '\0')
	{
		fresh[i] = s[start];
		start++;
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
