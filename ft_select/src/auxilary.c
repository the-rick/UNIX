/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxilary.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 10:57:57 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/21 10:58:29 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_printnbr(int nbr)
{
	return (write(STDERR_FILENO, &nbr, 1));
}

int		count_max_arg_len(void)
{
	int		max;
	int		curr_len;
	t_arg	*first;
	t_arg	*tmp;

	if (!g_var.args || !g_var.args->value)
		return (0);
	max = 0;
	tmp = g_var.args;
	first = tmp;
	while (tmp)
	{
		curr_len = ft_strlen(tmp->value);
		if (curr_len > max)
			max = curr_len;
		if (tmp->next == first)
			break ;
		tmp = tmp->next;
	}
	return (max);
}
