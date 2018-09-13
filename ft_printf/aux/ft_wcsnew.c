/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 14:02:55 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/07 15:42:20 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

wchar_t		*ft_wcsnew(size_t size)
{
	wchar_t *fresh;

	fresh = ft_memalloc(sizeof(wchar_t) * size + sizeof(wchar_t));
	return (fresh);
}
