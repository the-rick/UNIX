/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:58:51 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/08 11:58:53 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t prev_size, size_t new_size)
{
	void	*new;

	if (!ptr)
		return (NULL);
	if (!(new = ft_memalloc(new_size)))
	{
		printf("realloc");
		free(ptr);
		return (NULL);
	}
	printf("realloc 2");
	ft_memcpy(new, ptr, prev_size < new_size ? prev_size : new_size);
	printf("realloc 3");
	free(ptr);
	return (new);
}
