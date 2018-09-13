/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 13:39:03 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/07 15:23:00 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

int		ft_putwstr(wchar_t *wstr)
{
	int len;

	len = 0;
	while (*wstr)
	{
		ft_putwchar(*wstr);
		len += ft_wclen(*wstr);
		wstr += 1;
	}
	return (len);
}
