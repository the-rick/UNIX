/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 09:51:48 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/04 13:57:33 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	make_arguments(char **arg, char *flag, int num)
{
	int		i;
	t_ls	*tmp;

	i = 0;
	while (arg[i])
	{
		if (i != 0 && opendir(arg[i]))
			ft_putchar('\n');
		if (num > 1 && opendir(arg[i]))
		{
			ft_putstr(arg[i]);
			ft_putstr(":\n");
		}
		tmp = ft_ls(arg[i++], flag);
	}
	if (i == 0)
		tmp = ft_ls(".", flag);
	free_list(tmp);
}

void		initialize(t_save *hey)
{
	hey->x = 1;
	hey->y = 0;
	hey->flag = ft_strdup("00000000");
}

int			main(int ac, char **av)
{
	char	*arg[ac];
	t_save	*hey;

	hey = ft_memalloc(sizeof(t_save));
	initialize(hey);
	while (ac > hey->x && check_argument(av[hey->x], hey->flag) == 0)
		(hey->x)++;
	while (ac > hey->x)
	{
		if (check_argument(av[hey->x], hey->flag) < 0)
			return (0);
		else if (check_argument(av[hey->x], "") == 0)
			(hey->x)++;
		else
			arg[(hey->y)++] = ft_strdup(av[(hey->x)++]);
	}
	arg[hey->y] = NULL;
	make_arguments(arg, hey->flag, hey->y);
	free(hey->flag);
	while (hey->y > 0)
		free(arg[(hey->y)--]);
	free(arg[hey->y]);
	free(hey);
	hey = NULL;
	return (0);
}
