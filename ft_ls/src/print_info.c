/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 08:51:27 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/04 14:22:26 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	handle_rights(int mode)
{
	char	*index;

	if (!(index = malloc(sizeof(char) * 10)))
		return ;
	index[0] = ((mode & S_IRUSR) != 0) ? 'r' : '-';
	index[1] = ((mode & S_IWUSR) != 0) ? 'w' : '-';
	index[2] = ((mode & S_IXUSR) != 0) ? 'x' : '-';
	index[3] = ((mode & S_IRGRP) != 0) ? 'r' : '-';
	index[4] = ((mode & S_IWGRP) != 0) ? 'w' : '-';
	index[5] = ((mode & S_IXGRP) != 0) ? 'x' : '-';
	index[6] = ((mode & S_IROTH) != 0) ? 'r' : '-';
	index[7] = ((mode & S_IWOTH) != 0) ? 'w' : '-';
	index[8] = ((mode & S_IXOTH) != 0) ? 'x' : '-';
	index[9] = '\0';
	if (mode & S_ISUID)
		index[2] = (mode & S_IXUSR) ? 's' : 'S';
	if (mode & S_ISGID)
		index[5] = (mode & S_IXGRP) ? 's' : 'S';
	if (mode & S_ISVTX)
		index[8] = (mode & S_IXOTH) ? 't' : 'T';
	ft_putstr(index);
	free(index);
}

static void	handle_date(t_ls *ptr)
{
	char	**date;

	date = ft_split(ctime(&T_SEC), ' ');
	ft_putstr(date[1]);
	ft_putchar(' ');
	!date[2][1] ? ft_putchar(' ') : 0;
	ft_putchar(' ');
	ft_putstr(date[2]);
	ft_putchar(' ');
	date[3][5] = '\0';
	date[4][4] = '\0';
	if (time(0) - 15552000 >= T_SEC)
	{
		ft_putchar(' ');
		ft_putstr(date[4]);
	}
	else
		ft_putstr(date[3]);
	free(date);
}

static void	handle_groups(struct stat *ptr, char *flag)
{
	struct group	*group;
	int				i;

	i = 0;
	group = getgrgid(ptr->st_gid);
	if (group && N == '0' && O == '0' && group->gr_name)
		ft_putstr(group->gr_name);
	else if (group && O == '0')
		ft_putnbr1(ptr->st_gid);
	ft_putchar(' ');
	if (S_ISBLK(ptr->st_mode) || S_ISCHR(ptr->st_mode))
	{
		ft_putchar(' ');
		ft_putnbr1(major(ptr->st_rdev));
		ft_putstr(", ");
		ft_putnbr1(minor(ptr->st_rdev));
	}
	else
	{
		while (i++ + ft_strlen(ft_itoa(ptr->st_size)) < 5)
			ft_putchar(' ');
		ft_putnbr1(ptr->st_size);
	}
	ft_putchar(' ');
}

static int	handle_usi(t_ls *ptr, char *flag)
{
	struct stat		*user;
	struct passwd	*parent;

	user = (struct stat*)malloc(sizeof(struct stat));
	ft_putchar(' ');
	if (lstat(ptr->d_name, user) != 0)
		return (errno);
	if (user->st_nlink < 10)
		ft_putchar(' ');
	ft_putnbr1(user->st_nlink);
	ft_putchar(' ');
	parent = getpwuid(user->st_uid);
	if (parent && N == '0' && G == '0' && parent->pw_name)
		ft_putstr(parent->pw_name);
	else if (parent && G == '0')
		ft_putnbr1(user->st_uid);
	ft_putstr("  ");
	handle_groups(user, flag);
	handle_date(ptr);
	free(user);
	return (0);
}

int			print_file_info(t_ls *ptr, char *flag)
{
	struct stat	s;
	int			fail;

	if (lstat(ptr->d_name, &s) != 0)
		return (errno);
	if (S_ISREG(s.st_mode))
		ft_putchar('-');
	else if (S_ISDIR(s.st_mode))
		ft_putchar('d');
	else if (S_ISBLK(s.st_mode))
		ft_putchar('b');
	else if (S_ISCHR(s.st_mode))
		ft_putchar('c');
	else if (S_ISFIFO(s.st_mode))
		ft_putchar('p');
	else if (S_ISLNK(s.st_mode))
		ft_putchar('l');
	else if (S_ISSOCK(s.st_mode))
		ft_putchar('s');
	else
		ft_putchar('?');
	handle_rights(s.st_mode);
	if ((fail = handle_usi(ptr, flag) != 0))
		return (fail);
	return (0);
}
