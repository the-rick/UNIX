/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:51:30 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/08 11:51:32 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		run_shell(char *path, char **args)
{
	pid_t	pid;

	pid = fork();
	signal(SIGINT, proc_signal_handler);
	if (pid == 0)
		execve(path, args, g_envv);
	else if (pid < 0)
	{
		free(path);
		ft_putendl("failed to create a new process (sad face).");
		return (-1);
	}
	wait(&pid);
	if (path)
		free(path);
	return (1);
}
