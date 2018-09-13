/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 09:53:34 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/29 15:17:34 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	check_option(char c, char *flag)
{
	if (c == 'n' || c == 'o' || c == 'g')
	{
		flag[0] = '1';
		if (c == 'n')
			flag[5] = '1';
		if (c == 'o')
			flag[6] = '1';
		if (c == 'g')
			flag[7] = '1';
	}
}

static void	check_flag(char *str, char *flag)
{
	if (str[0] == '-')
	{
		str++;
		while (*str && (*str == 'l' || *str == 'R' || *str == 'r' \
					|| *str == 'a' || *str == 't' || *str == 'n' || *str == 'o'\
					|| *str == 'g'))
		{
			if (*str == 'l')
				flag[0] = '1';
			if (*str == 'R')
				flag[1] = '1';
			if (*str == 'r')
				flag[2] = '1';
			if (*str == 'a')
				flag[3] = '1';
			if (*str == 't')
				flag[4] = '1';
			check_option(*str, flag);
			str++;
		}
	}
}

int			check_argument(char *str, char *flag)
{
	char	*tmp;

	tmp = str;
	if (tmp[0] != '-' || (tmp[0] == '-' && !tmp[1]))
		return (1);
	if (tmp[0] == '-' && tmp[1] == '-' && !tmp[2])
		return (0);
	if (tmp[0] == '-')
	{
		tmp++;
		while (*tmp == 'l' || *tmp == 'R' || *tmp == 'r' || *tmp == 'a'\
				|| *tmp == 't' || *tmp == 'n' || *tmp == 'o' || *tmp == 'g')
			tmp++;
		if (*tmp)
		{
			ft_putstr("ls: invalid option --");
			ft_putchar(*tmp);
			ft_putstr("\nUse: ls [ - ] [alrtnogR] [file ..]\n");
			exit(0);
		}
	}
	if (flag[0] != '\0')
		check_flag(str, flag);
	return (0);
}
