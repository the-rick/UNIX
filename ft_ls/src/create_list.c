/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 08:51:27 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/29 14:48:11 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls		*create_list(char *d_name, char *flag)
{
	struct stat	s;
	t_ls		*ptr;

	ptr = (t_ls*)malloc(sizeof(t_ls));
	if (ptr)
	{
		ptr->d_name = d_name;
		ptr->stat = (t_stat*)malloc(sizeof(t_stat));
		if (TIME == '1' || LIST == '1')
		{
			stat(ptr->d_name, &s);
			T_SEC = s.st_mtimespec.tv_sec;
			T_NSEC = s.st_mtimespec.tv_nsec;
		}
		ptr->next = NULL;
	}
	return (ptr);
}

void		push_front(t_ls ***start, char *d_name, char *flag)
{
	t_ls	*new_data;

	new_data = create_list(d_name, flag);
	if (**start != NULL)
		new_data->next = **start;
	**start = new_data;
}

void		push_back(t_ls **end, char *d_name, char *flag)
{
	t_ls	*new_data;
	t_ls	*tmp;

	tmp = *end;
	if (tmp != NULL)
	{
		new_data = create_list(d_name, flag);
		new_data->next = tmp->next;
		tmp->next = new_data;
	}
	else
		tmp->next = create_list(d_name, flag);
}
