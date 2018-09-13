/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_promt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:46:46 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/08 11:46:48 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(void)
{
	ft_freestrarr(g_envv);
	write(1, "\n", 1);
	exit(0);
}

char	*parse_home_path(char *path, int reverse_parse)
{
	char	*home_path;
	char	*new;

	if (!path)
		return (NULL);
	home_path = get_env_var("HOME");
	if (!ft_strstartswith(path, reverse_parse ? "~" : home_path))
		return (ft_strdup(path));
	if (reverse_parse)
		new = ft_pathjoin(home_path, path + 1);
	else
	{
		if (*(path + ft_strlen(home_path)) == '\0')
			new = ft_strdup("~");
		else
			new = ft_pathjoin("~", path + ft_strlen(home_path));
	}
	return (new);
}

void	display_prompt_msg(void)
{
	ft_putstr_fd(COLOR, 1);
	ft_putstr(" minishell:~$ ");
}
