/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 10:41:33 by nmandlan          #+#    #+#             */
/*   Updated: 2018/05/31 10:49:06 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t n)
{
	void *tmp;

	if (!src)
	{
		return (NULL);
	}
	tmp = (void*)malloc(n);
	if (!tmp)
	{
		return (NULL);
	}
	tmp = ft_memcpy(tmp, src, n);
	return (tmp);
}
