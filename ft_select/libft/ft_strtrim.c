/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:28:17 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/21 14:17:01 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_c(char *str, char c)
{
	int		i;
	int		j;
	int		len;
	char	*trim;

	i = 0;
	j = 0;
	while (str[i] && str[i] == c)
		i++;
	len = ft_strlen(str) - 1;
	if (i <= len)
	{
		while (str[len] && str[len] == c)
			len--;
	}
	if (!(trim = (char*)malloc(sizeof(char) * ((len - i) + 2))))
		return (NULL);
	while (i <= len)
		trim[j++] = str[i++];
	trim[j] = '\0';
	return (trim);
}
