/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:09:52 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/27 22:19:49 by yrhiba           ###   ########.fr       */
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

# define ERR "Error\n"

# define ES '0'
# define WL '1'
# define CO 'C'
# define EX 'E'
# define PS 'P'

typedef struct s_tile
{
	size_t		r;
	size_t		c;

}				t_tile;

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
	size_t		map_exit;
	size_t		player_start;

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
	t_tile		player;
	t_tile		enemy;
	t_dir		dir;
	size_t		moves;
	t_my_list	*qrc;

}				t_so_long;

// parsing functions
int				so_long_init(t_so_long **so_long);
int				check_map(t_so_long *so_long, int ac, char **av);
int				check_tiles(t_so_long *so_long);
int				check_paths(t_so_long *so_long);

// get function
size_t			get_line_width(char *line);

// utils
int				map_visited_init(t_so_long *so_long);
int				bfs_init_data(t_so_long *so_long);
void			*tiledup(size_t r, size_t c);

// clear functions
void			map_clear(t_so_long *so_long);
void			map_visited_clear(t_so_long *so_long);
void			map_clear_failed_malloc(char **map);
void			sl_clear(t_so_long **so_long);

#endif
