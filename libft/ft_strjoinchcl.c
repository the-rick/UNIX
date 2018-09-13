/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchcl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:04:37 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/28 14:04:40 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinchcl(char *s1, char c)
{
	char	*new;

	if (!(new = ft_strjoinch(s1, c)))
		return (NULL);
	free(s1);
	s1 = NULL;
	return (new);
}
