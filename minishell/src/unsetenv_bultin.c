/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv_bultin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:49:53 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/08 11:53:41 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			print_env(void)
{
	int		i;

	i = -1;
	while (g_envv[++i])
		ft_putendl(g_envv[i]);
}

static int		envv_len(char **envv)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (envv[++i])
		count++;
	return (count);
}

void			init_envv(int ac, char **av, char **envv)
{
	int		i;

	(void)ac;
	(void)av;
	g_envv = (char **)ft_memalloc(sizeof(char *) * (envv_len(envv) + 1));
	i = -1;
	while (envv[++i])
	{
		if (!(g_envv[i] = ft_strdup(envv[i])))
			exit_shell();
	}
}

static void		remove_env_var(int i)
{
	int		var_count;

	free(g_envv[i]);
	g_envv[i] = NULL;
	var_count = i + 1;
	while (g_envv[i + 1])
	{
		g_envv[i] = ft_strdup(g_envv[i + 1]);
		free(g_envv[i + 1]);
		i++;
		var_count++;
	}
	g_envv = realloc_envv(var_count - 1);
}

int				unsetenv_builtin(char **args)
{
	int			i;
	int			var_pos;

	if (!args[0])
	{
		ft_putendl("unsetenv: Too few arguments.");
		return (1);
	}
	i = -1;
	while (args[++i])
	{
		var_pos = find_env_var(args[i]);
		if (g_envv[var_pos])
			remove_env_var(var_pos);
	}
	return (1);
}
