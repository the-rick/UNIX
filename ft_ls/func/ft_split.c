/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:28:17 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/21 14:19:33 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_split(char const *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			j++;
			i++;
			while (str[i] == c)
				i++;
		}
		i++;
	}
	j++;
	return (j);
}

static char	**create_tab(char **tab, const char *str, int len, char c)
{
	int	i;
	int	j;

	i = 0;
	while (*str)
	{
		j = 0;
		if (!(tab[i] = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (*str != c && len > 0)
		{
			tab[i][j++] = (char)*str;
			str++;
			len--;
		}
		while (*str == c && len > 0)
		{
			str++;
			len--;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char		**ft_split(char *str, char c)
{
	int		i;
	int		len;
	char	**split;

	str = ft_strtrim_c(str, c);
	len = ft_strlen(str);
	i = char_split(str, c);
	split = (char**)malloc(sizeof(char*) * (i + 1));
	if (split == NULL || !str || !c || !len)
		return (NULL);
	split = create_tab(split, str, len, c);
	return (split);
}
