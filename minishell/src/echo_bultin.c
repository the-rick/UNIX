/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_bultin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:48:05 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/08 11:54:20 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			find_quotes(char a)
{
	return (a == '"' || a == '\'');
}

static void			print_echo(char **str, int pos)
{
	int		begin;
	int		end;
	int		len;

	begin = find_quotes(str[pos][0]);
	len = ft_strlen(str[pos]);
	end = find_quotes(str[pos][len - 1]);
	if (end && begin)
		ft_putnstr(str[pos] + 1, -1);
	else if (end)
		ft_putnstr(str[pos], -1);
	else if (begin)
		ft_putstr(str[pos] + 1);
	else
		ft_putstr(str[pos]);
	if (str[pos + 1])
		ft_putchar(' ');
}

int					echo_builtin(char **args)
{
	int		i;
	int		n_flag;

	n_flag = 0;
	if (!args[0])
	{
		write(1, "\n", 1);
		return (1);
	}
	else if (args[0][0] == '-' && args[0][1] == 'n' && args[0][2] == '\0')
		n_flag = 1;
	i = -1;
	if (n_flag)
		++i;
	while (args[++i])
	{
		print_echo(args, i);
		if (!args[i + 1] && !n_flag)
			ft_putchar('\n');
	}
	return (1);
}
