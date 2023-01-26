/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba@student.1337.ma <yrhiba>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:16:04 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/26 18:59:06 by yrhiba@stud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leaks(void)
{
	system("leaks so_long");
}

int	main(int ac, char **av)
{
	t_so_long	*so_long;

	atexit(leaks);
	if (so_long_init(&so_long) == -1)
		return (perror("error<1>"), errno);
	if (check_map(so_long, ac, av) == -1)
		return (map_clear(so_long), free(so_long), ft_printf("Error\n"), 0);
	if (check_tiles(so_long) == -1)
		return (map_clear(so_long), free(so_long), ft_printf("Error\n"), 0);
	return (map_clear(so_long), free(so_long), 0);
}
