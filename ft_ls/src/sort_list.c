/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 08:51:27 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/04 11:00:29 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*filename(char *str, int err)
{
	int	len;

	if (err == 20)
		return (str);
	if (!ft_strchr(str, '/'))
		return (str);
	len = ft_strlen(str);
	len--;
	if (str[len] == '/')
		len--;
	while (str[len] != '/')
		len--;
	len++;
	return (&str[len]);
}

void		time_sort(t_ls *ptr, char *d_name, char *flag, struct stat s)
{
	while (ptr->next && T_SECN >= TV_SEC)
	{
		if (T_SECN > TV_SEC)
			ptr = ptr->next;
		else if (T_SECN == TV_SEC)
		{
			TV_NSEC = s.st_mtimespec.tv_nsec;
			if (T_NSECN > TV_NSEC)
				ptr = ptr->next;
			else if (ptr->next && T_NSECN == TV_NSEC \
					&& ft_strcmp(ptr->next->d_name, d_name) < 0)
				ptr = ptr->next;
			else
				break ;
		}
	}
	if (ptr)
		push_back(&ptr, d_name, flag);
}

void		handle_time(t_ls **list, char *d_name, char *flag)
{
	t_ls		*ptr;
	struct stat	s;

	ptr = *list;
	lstat(d_name, &s);
	TV_SEC = s.st_mtimespec.tv_sec;
	if (ptr && T_SEC <= TV_SEC)
	{
		if (T_SEC < TV_SEC)
		{
			push_front(&list, d_name, flag);
			return ;
		}
		else if (T_SEC == TV_SEC)
		{
			TV_NSEC = s.st_mtimespec.tv_nsec;
			if (T_NSEC < TV_NSEC || (ptr->next && T_NSEC == TV_NSEC &&\
					ft_strcmp(ptr->next->d_name, d_name) >= 0))
			{
				push_front(&list, d_name, flag);
				return ;
			}
		}
	}
	time_sort(ptr, d_name, flag, s);
}

void		sort_list(t_ls **list, char *d_name, char *flag)
{
	t_ls	*ptr;

	ptr = *list;
	if (TIME == '1' && LOW_R == '0')
		handle_time(list, d_name, flag);
	else if (LOW_R == '1')
		reverse_sort(list, d_name, flag);
	else
	{
		if (ptr && ft_strcmp(filename(ptr->d_name, 0), \
					filename(d_name, 0)) >= 0)
		{
			push_front(&list, d_name, flag);
			return ;
		}
		while (ptr->next && ft_strcmp(filename(ptr->next->d_name, 0), \
				filename(d_name, 0)) < 0)
		{
			ptr = ptr->next;
		}
		if (ptr)
			push_back(&ptr, d_name, flag);
	}
}
