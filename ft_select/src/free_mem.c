/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 10:56:53 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/21 13:00:02 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			free_mem(void)
{
	t_arg		*first;
	t_arg		*active;

	first = g_var.args;
	while (g_var.args)
	{
		active = g_var.args;
		free(g_var.args->value);
		g_var.args->value = NULL;
		g_var.argc--;
		if (g_var.args->next == first)
			break ;
		g_var.args = g_var.args->next;
		free(active);
		active = NULL;
	}
	if (active)
	{
		free(active);
		active = NULL;
	}
	g_var.args = NULL;
}
