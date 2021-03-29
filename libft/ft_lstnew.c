/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 10:19:56 by nmandlan          #+#    #+#             */
/*   Updated: 2018/05/31 11:47:06 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *fresh_link;

	fresh_link = (t_list*)malloc(sizeof(t_list));
	if (!fresh_link)
	{
		return (NULL);
	}
	if (content == NULL)
	{
		fresh_link->content = NULL;
		fresh_link->content_size = 0;
	}
	else
	{
		fresh_link->content = ft_memdup(content, content_size);
		fresh_link->content_size = content_size;
	}
	fresh_link->next = NULL;
	return (fresh_link);
}
