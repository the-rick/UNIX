/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:34:45 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/07 15:31:55 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

char	*ft_strrev(char *str)
{
	char *tmp1;
	char *tmp2;

	if (!str || !*str)
		return (str);
	tmp1 = str;
	tmp2 = str + ft_strlen(str) - 1;
	while (tmp2 > tmp1)
	{
		*tmp1 ^= *tmp2;
		*tmp2 ^= *tmp1;
		*tmp1 ^= *tmp2;
		++tmp1;
		--tmp2;
	}
	return (str);
}
