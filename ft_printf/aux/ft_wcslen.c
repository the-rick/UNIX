/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 13:53:17 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/07 15:41:30 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

size_t		ft_wcslen(wchar_t *wstr)
{
	size_t len;

	len = 0;
	while (*wstr)
	{
		len += ft_wclen(*wstr);
		wstr += 1;
	}
	return (len);
}
