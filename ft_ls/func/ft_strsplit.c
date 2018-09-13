/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:58:00 by nmandlan          #+#    #+#             */
/*   Updated: 2018/06/11 15:40:25 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	nb_words;
	char	**tab;

	i = 0;
	tab = NULL;
	nb_words = 0;
	if (s && (tab = (char **)malloc(sizeof(*tab) * ft_strlen(s))))
	{
		while (i < ft_strlen(s))
		{
			while (s[i] == c && s[i])
				i++;
			start = i;
			while (s[i] != c && s[i])
				i++;
			end = i;
			if ((end - start) > 0)
				tab[nb_words++] = ft_strsub(s, start, end - start);
		}
		tab[nb_words] = 0;
	}
	return (tab);
}
