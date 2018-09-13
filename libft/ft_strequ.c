/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 09:28:18 by nmandlan          #+#    #+#             */
/*   Updated: 2018/05/31 14:33:18 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 == NULL && s2 == NULL)
	{
		return (1);
	}
	if (s1 == NULL || s2 == NULL)
	{
		return (0);
	}
	if (ft_strcmp(s1, s2) == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
