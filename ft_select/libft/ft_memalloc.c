/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 08:26:56 by nmandlan          #+#    #+#             */
/*   Updated: 2018/05/28 14:57:06 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memry;
	size_t	i;

	i = 0;
	memry = NULL;
	if ((memry = ((void *)malloc(size))) == NULL)
	{
		return (NULL);
	}
	while (i < size)
	{
		((unsigned char*)memry)[i] = 0;
		i++;
	}
	return (memry);
}
