/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:30:54 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/07 15:04:12 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

char		*ft_convert_number(uintmax_t num, int *digits, int base)
{
	int			i;
	char		*str;
	uintmax_t	tmp;

	tmp = num;
	*digits = (!num) ? 1 : 0;
	while (tmp)
	{
		tmp /= base;
		*digits += 1;
	}
	if (!(str = (char*)malloc(sizeof(char) * (*digits))))
		return (NULL);
	*str = '0';
	i = (!num) ? 1 : 0;
	while (num)
	{
		tmp = num % base;
		num /= base;
		str[i++] = tmp + '0';
	}
	str[i] = '\0';
	str = ft_strrev(str);
	return (str);
}
