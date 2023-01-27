/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:16:04 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/28 00:39:44 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	parse_so_long(int ac, char **av, t_so_long **so_long)
{
	if (check_map(*so_long, ac, av) == -1)
		return (-1);
	if (check_tiles(*so_long) == -1)
		return (-1);
	if (check_paths(*so_long) == -1)
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	t_so_long	*so_long;

	if (so_long_init(&so_long) == -1)
		return (ft_printf(ERR), 0);
	if (parse_so_long(ac, av, &so_long) == -1)
		return (sl_clear(&so_long), ft_printf(ERR), 0);
	return (sl_clear(&so_long), 0);
}
