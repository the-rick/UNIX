/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 10:01:21 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/04 10:41:45 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		sort_time_reverse(t_ls *ptr, char *d_name, \
		char *flag, struct stat s)
{
	while (ptr->next && T_SECN <= TV_SEC)
	{
		if (T_SECN < TV_SEC)
			ptr = ptr->next;
		else if (T_SECN == TV_SEC)
		{
			TV_NSEC = s.st_mtimespec.tv_nsec;
			if (T_NSECN < TV_NSEC)
				ptr = ptr->next;
			else if (ptr->next && T_NSECN == TV_NSEC && \
				ft_strcmp(ptr->next->d_name, d_name) > 0)
				ptr = ptr->next;
			else
				break ;
		}
	}
	if (ptr)
		push_back(&ptr, d_name, flag);
}

void		reverse_time(t_ls **list, char *d_name, char *flag)
{
	t_ls		*ptr;
	struct stat	s;

	ptr = *list;
	lstat(d_name, &s);
	TV_SEC = s.st_mtimespec.tv_sec;
	if (ptr && T_SEC >= TV_SEC)
	{
		if (T_SEC > TV_SEC)
		{
			push_front(&list, d_name, flag);
			return ;
		}
		else if (T_SEC == TV_SEC)
		{
			TV_NSEC = s.st_mtimespec.tv_nsec;
			if (T_NSEC > TV_NSEC || (T_NSEC == TV_NSEC && \
				(ft_strcmp(ptr->d_name, d_name) <= 0)))
			{
				push_front(&list, d_name, flag);
				return ;
			}
		}
	}
	sort_time_reverse(ptr, d_name, flag, s);
}

void		reverse_sort(t_ls **list, char *d_name, char *flag)
{
	t_ls	*ptr;

	ptr = *list;
	if (LOW_R == '1' && TIME == '0')
	{
		if (ptr && ft_strcmp(filename(ptr->d_name, 0), \
					filename(d_name, 0)) <= 0)
		{
			push_front(&list, d_name, flag);
			return ;
		}
		while (ptr->next && ft_strcmp(filename(ptr->next->d_name, 0), \
				filename(d_name, 0)) > 0)
			ptr = ptr->next;
		if (ptr)
			push_back(&ptr, d_name, flag);
	}
	if (LOW_R == '1' && TIME == '1')
		reverse_time(list, d_name, flag);
}
