/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 10:06:23 by nmandlan          #+#    #+#             */
/*   Updated: 2018/06/25 15:23:12 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_for_new_line(char **store, char **line)
{
	char	*tmp_store;
	char	*tmp;
	char	*new_line;
	int		i;

	i = 0;
	new_line = *store;
	while (new_line[i] != '\n')
		if (!new_line[i++])
			return (0);
	tmp_store = &new_line[i];
	*tmp_store = '\0';
	*line = ft_strdup(*store);
	tmp = *store;
	*store = ft_strdup(tmp_store + 1);
	free(tmp);
	return (1);
}

static int	read_file(int fd, char *heap, char **stack, char **line)
{
	char		*tmp_stack;
	int			ret;

	while ((ret = read(fd, heap, BUFF_SIZE)) > 0)
	{
		heap[ret] = '\0';
		if (*stack)
		{
			tmp_stack = *stack;
			*stack = ft_strjoin(tmp_stack, heap);
			free(tmp_stack);
			tmp_stack = NULL;
		}
		else
			*stack = ft_strdup(heap);
		if (check_for_new_line(stack, line))
			break ;
	}
	return (RET(ret));
}

int			get_next_line(int const fd, char **line)
{
	static char	*stack[MAX_FD];
	char		*heap;
	int			ret;
	int			i;

	if (!line || (fd < 0 || fd > MAX_FD) || (read(fd, stack[fd], 0) < 0) \
		|| !(heap = (char*)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	if (stack[fd])
		if (check_for_new_line(&stack[fd], line))
			return (1);
	i = 0;
	while (i < BUFF_SIZE)
		heap[i++] = '\0';
	ret = read_file(fd, heap, &stack[fd], line);
	free(heap);
	if (ret != 0 || stack[fd] == NULL || stack[fd][0] == '\0')
	{
		if (!ret && *line)
			*line = NULL;
		return (ret);
	}
	*line = stack[fd];
	stack[fd] = NULL;
	return (1);
}
