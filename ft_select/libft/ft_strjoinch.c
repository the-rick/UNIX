/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:04:15 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/28 14:04:18 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinch(char const *s1, char c)
{
	size_t	i;
	size_t	len;
	char	*new_str;

	if (!s1 || !c)
		return (NULL);
	len = ft_strlen(s1);
	new_str = ft_strnew(len + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < len)
		*(new_str + i) = *(s1 + i);
	*(new_str + i) = c;
	return (new_str);
}
