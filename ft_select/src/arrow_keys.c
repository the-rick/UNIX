/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 10:54:21 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/21 10:56:22 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	up_arrow(void)
{
	int		i;
	t_arg	*tmp;
	int		count;

	i = 0;
	tmp = *g_var.current;
	count = count_columns();
	while (++i < count)
		tmp = tmp->prev;
	g_var.current = &tmp->prev;
}

static void	down_arrow(void)
{
	int		i;
	t_arg	*tmp;
	int		count;

	i = 0;
	tmp = *g_var.current;
	count = count_columns();
	while (++i < count)
		tmp = tmp->next;
	g_var.current = &tmp->next;
}

void		move_curs(t_key key)
{
	t_arg		*tmp;

	tmp = *g_var.current;
	if (key == RIGHT_ARROW)
		g_var.current = &tmp->next;
	else if (key == LEFT_ARROW)
		g_var.current = &tmp->prev;
	else if (key == UP_ARROW)
		up_arrow();
	else if (key == DOWN_ARROW)
		down_arrow();
}
