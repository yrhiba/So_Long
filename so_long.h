/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba@student.1337.ma <yrhiba>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:09:52 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/24 21:59:51 by yrhiba@stud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include "my_list.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <unistd.h>

typedef struct s_dir
{
	int			dr[4];
	int			dc[4];

}				t_dir;

typedef struct s_map
{
	char		**map;
	size_t		width;
	size_t		height;
	size_t		walls;
	size_t		collectibles;
	size_t		free_space;

}				t_map;

typedef struct s_so_long
{
	t_my_list	*gc;
	t_dir		dir;
	t_map		map;

}				t_so_long;

#endif

/*

	gc : garbage collector
	dr : rows direction
	dc : columns direction

*/
