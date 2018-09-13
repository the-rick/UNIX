/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:52:04 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/07 15:28:38 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

char	*ft_strdup(const char *str)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	tmp = (char*)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!tmp)
	{
		return (NULL);
	}
	while (str[i])
	{
		tmp[i] = str[i];
		i += 1;
	}
	tmp[i] = '\0';
	return (tmp);
}
