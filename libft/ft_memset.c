/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 09:20:20 by nmandlan          #+#    #+#             */
/*   Updated: 2018/05/22 09:59:23 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str_in, int data, size_t len)
{
	unsigned char *tmp;

	tmp = (unsigned char*)str_in;
	while (len > 0)
	{
		*tmp++ = (unsigned char)data;
		len--;
	}
	return (str_in);
}
