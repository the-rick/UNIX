/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:48:37 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/08 11:48:59 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		check_builtins(char **command)
{
	if (ft_strequ(command[0], "exit"))
		return (-1);
	else if (ft_strequ(command[0], "echo"))
		return (echo_builtin(command + 1));
	else if (ft_strequ(command[0], "cd"))
		return (cd_builtin(command + 1));
	else if (ft_strequ(command[0], "setenv"))
		return (setenv_builtin(command + 1));
	else if (ft_strequ(command[0], "unsetenv"))
		return (unsetenv_builtin(command + 1));
	else if (ft_strequ(command[0], "env"))
	{
		print_env();
		return (1);
	}
	return (0);
}

static int		check_permisions(char *bin_path, struct stat f, char **command)
{
	if (f.st_mode & S_IFREG)
	{
		if (f.st_mode & S_IXUSR)
			return (run_shell(bin_path, command));
		else
		{
			ft_putstr("minishell: permission denied: ");
			ft_putendl(bin_path);
		}
		free(bin_path);
		return (1);
	}
	free(bin_path);
	return (0);
}

static int		check_bins(char **command)
{
	int				i;
	char			*bin_path;
	char			**path;
	struct stat		f;

	path = ft_strsplit(get_env_var("PATH"), ':');
	i = -1;
	while (path && path[++i])
	{
		if (ft_strstartswith(command[0], path[i]))
			bin_path = ft_strdup(command[0]);
		else
			bin_path = ft_pathjoin(path[i], command[0]);
		if (lstat(bin_path, &f) == -1)
			free(bin_path);
		else
		{
			ft_freestrarr(path);
			return (check_permisions(bin_path, f, command));
		}
	}
	ft_freestrarr(path);
	return (0);
}

int				get_commands(char **command)
{
	struct stat	f;
	int			ret;

	if ((ret = check_builtins(command)) == 1 || check_bins(command))
		return (0);
	if (ret < 0)
		return (-1);
	if (lstat(command[0], &f) != -1)
	{
		if (f.st_mode & S_IFDIR)
		{
			change_dir(command[0], 0);
			return (0);
		}
		else if (f.st_mode & S_IXUSR)
			return (run_shell(ft_strdup(command[0]), command));
	}
	ft_putstr("minishell: command not found: ");
	ft_putendl(command[0]);
	return (0);
}
