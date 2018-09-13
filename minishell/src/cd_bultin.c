/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_bultin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:46:34 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/08 11:53:06 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		print_file_path(char *path)
{
	char	*parsed_home;

	parsed_home = parse_home_path(path, 0);
	ft_putstr(parsed_home);
	free(parsed_home);
}

void			change_dir(char *path, int print_path)
{
	char	*cwd;
	char	buff[4097];

	cwd = getcwd(buff, 4096);
	if (!chdir(path))
	{
		if (print_path)
		{
			print_file_path(path);
			ft_putchar('\n');
		}
		set_env_var("OLDPWD", cwd);
	}
	else
	{
		ft_putstr("cd: ");
		if (access(path, F_OK) == -1)
			ft_putstr("no such file or directory: ");
		else if (access(path, R_OK) == -1)
			ft_putstr("permission denied: ");
		else
			ft_putstr("not a directory: ");
		ft_putendl(path);
	}
}

static int		count_arguments(char **args)
{
	char	*cwd;
	char	buff[4096 + 1];
	char	*tmp;

	if (args[1])
	{
		if (args[2])
		{
			ft_putendl("cd: too many arguments");
			return (1);
		}
		cwd = getcwd(buff, 4096);
		if (!(tmp = ft_strreplace(cwd, args[0], args[1])))
		{
			ft_putstr("cd: string not in pwd: ");
			ft_putendl(args[0]);
			free(tmp);
			return (1);
		}
		change_dir(tmp, 1);
		free(tmp);
		return (1);
	}
	return (0);
}

int				cd_builtin(char **cd)
{
	char	*home_path;

	home_path = get_env_var("HOME");
	if (!cd[0])
	{
		change_dir(home_path, 0);
		return (1);
	}
	if (count_arguments(cd))
		return (1);
	else
	{
		if (ft_strequ(cd[0], "--"))
		{
			change_dir(home_path, 0);
			return (1);
		}
		else if (cd[0][0] == '-' && !cd[0][2])
		{
			change_dir(get_env_var("OLDPWD"), 1);
			return (1);
		}
		change_dir(cd[0], 0);
	}
	return (1);
}
