/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:47:18 by nmandlan          #+#    #+#             */
/*   Updated: 2018/08/07 15:00:46 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "aux.h"

static int		find_specifier(char c, char *spec)
{
	int i;

	i = 0;
	while (spec[i])
	{
		if (c == spec[i])
			return (i);
		i += 1;
	}
	return (FAIL);
}

static int		get_specifier(char c, t_printf *ptr, char *spec)
{
	int	*index;
	int	found;

	index = ft_memalloc(sizeof(int) * ft_strlen(SPECIFIER));
	index[LOW_S] = LOW_S_BIT;
	index[UPPER_S] = UPP_S_BIT;
	index[LOW_P] = LOW_P_BIT;
	index[LOW_D] = LOW_D_BIT;
	index[UPPER_D] = UPP_D_BIT;
	index[LOW_I] = LOW_I_BIT;
	index[LOW_O] = LOW_O_BIT;
	index[UPPER_O] = UPP_O_BIT;
	index[LOW_U] = LOW_U_BIT;
	index[UPPER_U] = UPP_U_BIT;
	index[LOW_X] = LOW_X_BIT;
	index[UPPER_X] = UPP_X_BIT;
	index[LOW_C] = LOW_C_BIT;
	index[UPPER_C] = UPP_C_BIT;
	index[LOW_B] = LOW_B_BIT;
	if (((found = find_specifier(c, spec)) != FAIL) && c)
		ptr->flags |= index[found];
	free(index);
	return (found);
}

int				return_specifier(va_list arg, char **format, t_printf *ptr)
{
	int		spec;
	int		ret;
	char	*index;

	ptr->flags = 0;
	if (!(index = (char*)malloc(sizeof(char) * ft_strlen(SPECIFIER))))
		return (0);
	index = ft_strncpy(index, SPECIFIER, ft_strlen(SPECIFIER));
	spec = FAIL;
	while (**format)
	{
		if ((find_specifier(**format, index) != FAIL) \
				&& (spec = get_specifier(**format, ptr, index)))
			break ;
		if (!(ret = parse_attributes(format, arg, ptr)))
			break ;
	}
	free(index);
	return (spec);
}
