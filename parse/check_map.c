/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba@student.1337.ma <yrhiba>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:55:14 by yrhiba@stud       #+#    #+#             */
/*   Updated: 2023/01/27 16:52:53 by yrhiba@stud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	read_lines(t_my_list **lines, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (my_list_push_back(lines, my_list_new_elem((void *)line)) == -1)
			return (my_list_clear(lines), -1);
		line = get_next_line(fd);
	}
	return (0);
}

static int	check_map_width_height(t_so_long *so_long, t_my_list *it)
{
	int		f;
	size_t	tmp;

	f = 0;
	while (it)
	{
		if (f == 0)
		{
			(so_long->map).width = get_line_width((char *)it->data);
			tmp = (so_long->map).width;
			f = 1;
		}
		else
		{
			tmp = get_line_width((char *)it->data);
			if (tmp != (so_long->map).width)
				return (-1);
		}
		(so_long->map).height++;
		it = it->next;
	}
	return (0);
}

static void	parse_line(char *from, char **to, size_t width)
{
	size_t	i;

	i = 0;
	while (i < width)
	{
		(*to)[i] = from[i];
		i++;
	}
}

static int	parse_map(t_so_long *so_long, t_my_list *it)
{
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * (so_long->map).height);
	if (!map)
		return (-1);
	i = 0;
	while (it)
	{
		map[i] = (char *)malloc(sizeof(char) * (so_long->map).width);
		if (!(map[i]))
			return (map_clear_failed_malloc(map), -1);
		parse_line((char *)it->data, &(map[i]), (so_long->map).width);
		i++;
		it = it->next;
	}
	return ((so_long->map).map = map, 0);
}

int	check_map(t_so_long *so_long, int ac, char **av)
{
	t_my_list	*lines;
	int			fd;

	my_list_init(&lines);
	if (ac != 2)
		return (-1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	if (read_lines(&lines, fd) == -1)
		return (close(fd), -1);
	close(fd);
	if (check_map_width_height(so_long, lines) == -1)
		return (my_list_clear(&lines), -1);
	if (parse_map(so_long, lines) == -1)
		return (my_list_clear(&lines), -1);
	return (my_list_clear(&lines), 0);
}
