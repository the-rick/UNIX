/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 10:57:19 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/21 13:01:42 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		init_custom_conf(void)
{
	if (!(g_var.term_name = getenv("TERM")))
	{
		ft_putendl_fd("Terminal name not found.", STDERR_FILENO);
		exit(EXIT_SUCCESS);
	}
	error_handler(g_var.term_name);
	tcgetattr(STDERR_FILENO, &g_var.attr);
	tcgetattr(STDERR_FILENO, &g_var.new_attr);
	g_var.new_attr.c_lflag &= ~(ICANON | ECHO);
	g_var.new_attr.c_cc[VMIN] = 1;
	g_var.new_attr.c_cc[VTIME] = 0;
	tcsetattr(STDERR_FILENO, TCSANOW, &g_var.new_attr);
	tputs(tgetstr("ti", NULL), 1, ft_printnbr);
	tputs(tgetstr("vi", NULL), 1, ft_printnbr);
}

void		check_flags(char *flag)
{
	if ((flag[0] == 'r' && !flag[1]))
		g_var.mode = 1;
	else
	{
		ft_putstr_fd(MENU, 1);
		ft_putendl_fd("Welcome to ft_select:", STDERR_FILENO);
		ft_putendl_fd("[Normal] ./ft_select [arguments]", STDERR_FILENO);
		ft_putendl_fd("[Real] ./ft_select -r arguments", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

int			main(int ac, char **av)
{
	if (ac < 2 || (ac == 2 && av[1][0] == '-'))
	{
		ft_putstr_fd(MENU, 1);
		ft_putendl_fd("Welcome to ft_select:", STDERR_FILENO);
		ft_putendl_fd("[Normal] ./ft_select arguments", STDERR_FILENO);
		ft_putendl_fd("[Real] ./ft_select -r arguments", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (av[1][0] == '-' && av[1][1])
		check_flags(av[1] + 1);
	init_custom_conf();
	init_args((av[1][0] == '-') ? av + 2 : av + 1);
	signal_handler();
	control_keys();
	default_conf();
	print_selected_args();
	ft_putchar('\n');
	free_mem();
	return (0);
}
