/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 09:55:55 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/04 11:11:21 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static int	check_point(char *str)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	len--;
	while (str[len] != '/' && str[len] != '.')
		len--;
	while (str[len] != '/' && str[len] == '.')
	{
		i++;
		len--;
	}
	if (i == 1 || i == 2)
	{
		if ((ft_strlen(str)) - 3 <= len)
			return (1);
	}
	return (0);
}

static void	handle_recursive_ls(t_ls *list, char *flag)
{
	struct stat	s;

	if (list)
	{
		while (list)
		{
			if (lstat(list->d_name, &s) != 0)
				return ;
			if (S_ISDIR(s.st_mode) == 1)
			{
				if (check_point(list->d_name) == 0)
				{
					ft_putchar('\n');
					ft_putstr(list->d_name);
					ft_putchar(':');
					ft_putchar('\n');
					ft_ls(list->d_name, flag);
				}
			}
			list = list->next;
		}
	}
}

static t_ls	*create_ls(char *d_name, char *flag, char *o_dir, t_ls *list)
{
	if (ALL == '1')
	{
		if (!list)
		{
			list = create_list(ft_strdir(o_dir, d_name), flag);
		}
		else
			sort_list(&list, ft_strdir(o_dir, d_name), flag);
	}
	else if (ft_strncmp(d_name, ".", 1) != 0 && ft_strcmp(d_name, "..") != 0)
	{
		if (!list)
			list = create_list(ft_strdir(o_dir, d_name), flag);
		else
			sort_list(&list, ft_strdir(o_dir, d_name), flag);
	}
	return (list);
}

static int	check_list(t_ls **list, char *o_dir, char *flag)
{
	struct stat	s;

	if (LIST == '1' && lstat(o_dir, &s) == 0 && S_ISLNK(s.st_mode) == 1 &&\
			stat(o_dir, &s) == 0)
	{
		*list = create_list(o_dir, flag);
		free(o_dir);
		return (1);
	}
	return (0);
}

t_ls		*ft_ls(char *o_dir, char *flag)
{
	DIR				*dir;
	struct dirent	*start;
	struct stat		s;
	t_ls			*list;
	int				error;

	list = NULL;
	error = errno;
	dir = opendir(o_dir);
	if (((!dir && (lstat(o_dir, &s) != 0)) \
				|| (!dir && errno == 13)) && ft_print_error(o_dir))
		return (NULL);
	if (dir && check_list(&list, o_dir, flag) == 0)
	{
		while ((start = readdir(dir)))
			list = create_ls(start->d_name, flag, o_dir, list);
	}
	if (lstat(o_dir, &s) == 0 && !dir)
		list = create_ls(o_dir, flag, "", list);
	print_list(list, flag, error);
	if (R == '1' && error != 20)
		handle_recursive_ls(list, flag);
	if (dir && (closedir(dir) < 0))
		return (NULL);
	return (list);
}
