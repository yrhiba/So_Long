/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba@student.1337.ma <yrhiba>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:09:52 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/26 01:55:31 by yrhiba@stud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "my_list.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
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
	char		**visited;
	size_t		width;
	size_t		height;
	size_t		walls;
	size_t		collectibles;
	size_t		free_space;

}				t_map;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;

}				t_mlx_data;

typedef struct s_so_long
{
	t_mlx_data	mlx;
	t_map		map;
	t_dir		dir;

}				t_so_long;

// parsing functions
int				so_long_init(t_so_long **so_long);
int				check_map(t_so_long *so_long, int ac, char **av);

// get function
size_t			get_line_width(char *line);

// clear functions
void			map_clear(t_so_long *so_long);
void			map_clear_failed_malloc(char **map);

#endif
