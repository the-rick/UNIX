/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:02:06 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/21 11:02:54 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	window_size(int size)
{
	struct winsize	ws;

	ioctl(STDERR_FILENO, TIOCGWINSZ, &ws);
	return ((size) ? ws.ws_col : ws.ws_row);
}

int			count_columns(void)
{
	int cols;

	cols = window_size(1) / (count_max_arg_len() + 1);
	if (!cols)
		cols = 1;
	if ((count_max_arg_len() + 1) * g_var.argc < window_size(1))
		cols = g_var.argc;
	return (cols);
}

void		display_value(t_arg *arg, int fd)
{
	if (arg->type == DOT_C && fd == STDERR_FILENO)
		ft_putstr_fd(C_COLOR, fd);
	else if (arg->type == DOT_O && fd == STDERR_FILENO)
		ft_putstr_fd(O_COLOR, fd);
	else if (arg->type == DOT_H && fd == STDERR_FILENO)
		ft_putstr_fd(H_COLOR, fd);
	else if (arg->type == MAKEFILE && fd == STDERR_FILENO)
		ft_putstr_fd(MAKEFILE_COLOR, fd);
	else if (arg->type == DOT_T && fd == STDERR_FILENO)
		ft_putstr_fd(DOT_COLOR, fd);
	ft_putstr_fd(arg->value, fd);
	if (fd == STDERR_FILENO)
		ft_putstr_fd(DEFAULT_COLOR, fd);
}

static void	display_args(t_arg *args, t_arg *first, int rows, int cols)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (++j < cols)
		{
			if (args == (*g_var.current))
				ft_putstr_fd(UNDERLINED, STDERR_FILENO);
			if (args->is_selected)
				ft_putstr_fd(REVERSE_VIDEO_COLOR, STDERR_FILENO);
			display_value(args, STDERR_FILENO);
			len = ft_strlen(args->value);
			while (len++ <= count_max_arg_len())
				ft_putstr_fd(" ", STDERR_FILENO);
			if (args->next == first)
				break ;
			args = args->next;
		}
		ft_putstr_fd("\n", STDERR_FILENO);
	}
}

void		column_display(void)
{
	int		cols;
	int		rows;

	if (!g_var.args || count_max_arg_len() > window_size(1))
		return ;
	tputs(tgetstr("cl", NULL), 1, ft_printnbr);
	cols = count_columns();
	rows = g_var.argc / cols;
	if (rows > window_size(0))
		return ;
	if (g_var.argc % cols)
		++rows;
	display_args(g_var.args, g_var.args, rows, cols);
}
