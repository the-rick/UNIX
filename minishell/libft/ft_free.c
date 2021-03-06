/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:06:38 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/28 14:06:41 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **ptr)
{
	int	i;

	if (!ptr)
		return ;
	i = -1;
	while (ptr[++i])
	{
		free(ptr[i]);
	}
	free(ptr);
	ptr = NULL;
}
