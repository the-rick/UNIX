/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:31:47 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/07 15:15:28 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "aux.h"

int	ft_get_spaces(int attr, int size, int *len)
{
	int spaces;

	spaces = 0;
	if (attr & WIDTH && (!(attr & ZERO) || attr & MINUS || attr & PRECISION) \
			&& size > *len)
	{
		spaces += size - *len;
		*len += spaces;
	}
	return (spaces);
}
