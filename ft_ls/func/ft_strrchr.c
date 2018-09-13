/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:50:06 by nmandlan          #+#    #+#             */
/*   Updated: 2018/05/28 15:03:21 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	if (s)
	{
		while (s[i] != (char)c && i >= 0)
		{
			i--;
		}
		if (s[i] == (char)c)
		{
			return ((char*)&s[i]);
		}
	}
	return (NULL);
}
