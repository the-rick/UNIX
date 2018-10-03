/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 10:58:36 by nmandlan          #+#    #+#             */
/*   Updated: 2018/10/03 17:01:13 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	error_handler(char *entry_name)
{
	int		res;
	char	buf[1024];

	if (!isatty(STDERR_FILENO))
	{
		ft_putendl_fd("Not a terminal.", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if ((res = tgetent(buf, entry_name)) < 1)
	{
		if (res == -1)
			ft_putendl_fd("Terminfo database not found.", STDERR_FILENO);
		else if (res == 0)
			ft_putendl_fd("No such entry.", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	print_selected_args(void)
{
	t_arg	*args;
	t_arg	*first;
	int		i;

	args = g_var.args;
	first = args;
	i = 1;
	while (args)
	{
		if (args->is_selected)
		{
			display_value(args, STDOUT_FILENO);
			i++;
			ft_putchar(' ');
		}
		if (args->next == first)
			break ;
		args = args->next;
	}
}
