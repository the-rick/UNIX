/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_odir_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:28:17 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/21 14:13:50 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdir(char *o_dir, char *d_name)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	len = ft_strlen(o_dir) + ft_strlen(d_name) + 1;
	str = (char*)malloc(sizeof(char) + (len + 1));
	while (o_dir && o_dir[i])
	{
		str[i] = o_dir[i];
		i++;
	}
	if (o_dir[0] != '\0')
	{
		str[i] = '/';
		i++;
	}
	while (d_name && d_name[j])
		str[i++] = d_name[j++];
	str[i] = '\0';
	return (str);
}
