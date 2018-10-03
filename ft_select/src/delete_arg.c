/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:04:47 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/21 12:59:45 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	fn(const char *fpath, const struct stat *sb, \
		int flag, struct FTW *ftwbuf)
{
	int del;

	(void)sb;
	(void)flag;
	(void)ftwbuf;
	del = remove(fpath);
	return (del);
}

static void	remove_arg(char *path)
{
	struct stat	s;

	if (lstat(path, &s) == -1)
		return ;
	if (S_ISDIR(s.st_mode))
		nftw(path, fn, 64, FTW_DEPTH | FTW_PHYS);
	else
		remove(path);
}

void		delete_arg(void)
{
	t_arg		*selected;

	if (!g_var.current)
		return ;
	selected = *g_var.current;
	if (g_var.args == selected)
		g_var.args = (selected->next == selected) ? NULL : selected->next;
	else
		g_var.current = &selected->next;
	selected->next->prev = selected->prev;
	selected->prev->next = selected->next;
	if (g_var.mode)
		remove_arg(selected->value);
	g_var.argc--;
	free(selected->value);
	selected->value = NULL;
	free(selected);
	selected = NULL;
	if (!g_var.argc)
		kill_signals();
}
