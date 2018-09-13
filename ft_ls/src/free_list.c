/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:28:17 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/22 15:25:35 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_list(t_ls *ptr)
{
	t_ls	*hold;
	t_ls	*tmp;

	hold = ptr;
	while (hold)
	{
		tmp = hold->next;
		ft_memdel((void*)&hold->stat);
		ft_strdel(&hold->d_name);
		free(hold);
		hold = tmp;
	}
}
