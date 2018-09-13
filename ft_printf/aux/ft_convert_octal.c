/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:31:03 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/07 15:07:04 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"
#include "ft_printf.h"

char	*octal(uintmax_t num, int *size)
{
	return (ft_convert_number(num, size, 8));
}
