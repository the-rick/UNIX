/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:06:47 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/28 14:07:24 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_search_replace(char *str, char *find, char *new)
{
	int		i;
	int		j;
	char	*new_path;

	if (!ft_strstr(str, find))
		return (NULL);
	new_path = ft_strnew(1);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (ft_strstartswith(str + i, find) && !j)
		{
			new_path = ft_strjoincl(new_path, new, 0);
			i += ft_strlen(find);
			if (!str[i])
				break ;
			new_path = ft_strjoinchcl(new_path, str[i]);
			j = 1;
		}
		else
			new_path = ft_strjoinchcl(new_path, str[i]);
	}
	return (new_path);
}
