/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:04:11 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/21 13:02:07 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		default_conf(void)
{
	tcsetattr(STDERR_FILENO, TCSANOW, &g_var.attr);
	tputs(tgetstr("ve", NULL), 1, ft_printnbr);
	tputs(tgetstr("te", NULL), 1, ft_printnbr);
}

static void	stop_signals(void)
{
	default_conf();
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}

void		kill_signals(void)
{
	default_conf();
	free_mem();
	exit(EXIT_SUCCESS);
}

void		proc_signals(int signo)
{
	if (signo == SIGTSTP)
		stop_signals();
	else if (signo == SIGINT || signo == SIGABRT || signo == SIGSTOP
			|| signo == SIGKILL || signo == SIGQUIT)
		kill_signals();
	else if (signo == SIGCONT)
	{
		init_custom_conf();
		signal_handler();
		column_display();
	}
	else if (signo == WINCH)
		column_display();
}

void		signal_handler(void)
{
	signal(WINCH, proc_signals);
	signal(SIGQUIT, proc_signals);
	signal(SIGKILL, proc_signals);
	signal(SIGTSTP, proc_signals);
	signal(SIGCONT, proc_signals);
	signal(SIGSTOP, proc_signals);
	signal(SIGINT, proc_signals);
	signal(SIGABRT, proc_signals);
}
