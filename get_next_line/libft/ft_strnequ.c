/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 09:51:18 by nmandlan          #+#    #+#             */
/*   Updated: 2018/05/31 14:20:58 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if ((s1 == NULL && s2 == NULL) || n == 0)
	{
		return (1);
	}
	if (s1 == NULL || s2 == NULL)
	{
		return (0);
	}
	if (ft_strncmp(s1, s2, n) == 0)
	{
		return (1);
	}
	return (0);
}
