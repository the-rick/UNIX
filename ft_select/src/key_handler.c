/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:05:33 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/21 11:05:39 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_key	get_direction(long key)
{
	if (key == UP_KEY)
		return (UP_ARROW);
	else if (key == DOWN_KEY)
		return (DOWN_ARROW);
	else if (key == RIGHT_KEY)
		return (RIGHT_ARROW);
	else if (key == LEFT_KEY)
		return (LEFT_ARROW);
	else
		return (DEFAULT);
}

void			control_keys(void)
{
	long		key;

	while (1)
	{
		column_display();
		key = 0;
		read(STDERR_FILENO, &key, 8);
		if (key == ENTER)
			break ;
		else if (key == SPACE)
			toggle_selection();
		else if (key == ESC)
			kill_signals();
		else if (key == BACKSPACE || key == DELETE)
			delete_arg();
		else if (key == STAR_KEY || key == MINUS_KEY)
			toggle_all_args(key);
		else
			move_curs(get_direction(key));
	}
}
