/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 08:51:27 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/04 10:41:06 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_link(t_ls *ptr)
{
	struct stat	get;
	char		*buf;

	buf = (char*)malloc(sizeof(char) * 1024);
	if (lstat(ptr->d_name, &get) != 0)
		return ;
	if (S_ISLNK(get.st_mode))
	{
		readlink(ptr->d_name, buf, 1024);
		ft_putstr(" -> ");
		ft_putstr(buf);
	}
}

int			ft_print_error(char *o_dir)
{
	ft_putstr("ls: ");
	if (o_dir[0] == '\0')
		ft_putstr("fts_open: ");
	else
		ft_putstr(o_dir);
	perror("");
	return (1);
}

static void	print_blocks(t_ls *lst, int error)
{
	struct stat		get;
	t_ls			*ptr;
	unsigned long	block;

	ptr = lst;
	block = 0;
	while (ptr)
	{
		if (lstat(ptr->d_name, &get))
			return ;
		block += get.st_blocks;
		ptr = ptr->next;
	}
	if (!get.st_mode || S_ISLNK(get.st_mode) == 1 || error == 20)
		return ;
	ft_putstr("total ");
	ft_putnbr1(block);
	ft_putchar('\n');
}

static int	print_error(t_ls *ptr, char *flag, int err)
{
	int	error;

	error = 0;
	if (!err || err == 20 || err == 13 || err == 2)
		error = print_file_info(ptr, flag);
	if (error || (err && err != 20 && err != 13 && err == 2))
		ft_putstr("ls:");
	ft_putchar(' ');
	if (err && err != 20 && err != 13 && err == 2)
		return (err);
	return (error);
}

void		print_list(t_ls *lst, char *flag, int err)
{
	t_ls	*ptr;
	int		error;

	ptr = lst;
	error = 0;
	if (LIST == '1' && !err)
		print_blocks(lst, err);
	while (ptr)
	{
		if (ptr->d_name)
		{
			if (LIST == '1')
				error = print_error(ptr, flag, err);
			ft_putstr(filename(ptr->d_name, err));
			if (error || (err && err != 20 && err != 13 && err != 2))
			{
				ft_putchar(' ');
				ft_putstr(strerror(error ? error : err));
			}
			if (LIST == '1' && !error && !err)
				print_link(ptr);
			ft_putchar('\n');
		}
		ptr = ptr->next;
	}
}
