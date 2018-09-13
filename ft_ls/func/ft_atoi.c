/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 08:20:54 by nmandlan          #+#    #+#             */
/*   Updated: 2018/06/11 15:44:47 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int sign;
	int num;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == ' ') ||
			(str[i] == '\r') || (str[i] == '\v') ||
			(str[i] == '\f'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + ((int)str[i] - '0');
		i++;
	}
	return (num * sign);
}
