/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:01:46 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/21 13:02:00 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		toggle_selection(void)
{
	(*g_var.current)->is_selected = !(*g_var.current)->is_selected;
	g_var.selected_count += ((*g_var.current)->is_selected) ? 1 : -1;
	if ((*g_var.current)->is_selected)
		g_var.current = &(*g_var.current)->next;
}

void		toggle_all_args(long key)
{
	t_arg		*args;
	t_arg		*first;

	args = g_var.args;
	first = args;
	while (args)
	{
		args->is_selected = (key == STAR_KEY) ? 1 : 0;
		g_var.selected_count += (key == STAR_KEY) ? 1 : -1;
		if (args->next == first)
			break ;
		args = args->next;
	}
}
