/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:03:01 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/21 11:04:04 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_type	arg_type(char *str)
{
	char	*name;

	name = ft_strrchr(str, '/') ? ft_strrchr(str, '/') + 1 : str;
	if (ft_strendswith(name, ".c"))
		return (DOT_C);
	if (ft_strendswith(name, ".o"))
		return (DOT_O);
	if (ft_strendswith(name, ".h"))
		return (DOT_H);
	if (ft_strendswith(name, ".a"))
		return (DOT_A);
	if (ft_strequ(name, "Makefile"))
		return (MAKEFILE);
	if (name[0] == '.')
		return (DOT_T);
	return (UNKNOWN_T);
}

void			put_arg(char *data)
{
	t_arg		*new;
	t_arg		*last;

	new = (t_arg *)ft_memalloc(sizeof(t_arg));
	new->value = ft_strdup(data);
	new->type = arg_type(data);
	g_var.argc++;
	if (!g_var.args)
	{
		new->prev = new;
		new->next = new;
		g_var.args = new;
		g_var.current = &g_var.args;
		return ;
	}
	last = g_var.args->prev;
	new->next = g_var.args;
	g_var.args->prev = new;
	new->prev = last;
	last->next = new;
}

void			init_args(char **av)
{
	int		i;

	i = -1;
	g_var.argc = 0;
	while (av[++i])
		put_arg(av[i]);
	g_var.selected_count = 0;
}
