/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:09:52 by yrhiba            #+#    #+#             */
/*   Updated: 2023/01/29 06:06:25 by yrhiba           ###   ########.fr       */
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

# define WIN_TITLE "so long"

# define ERR "Error\n"

#define DOWN 3
#define UP 2
#define RIGHT 1
#define LEFT 0

# define ES '0'
# define WL '1'
# define CO 'C'
# define EX 'E'
# define PS 'P'
# define OP 'X'

# define TILE_SIZE 100

# define PLAYER_PATH "textures/player.xpm"
# define EXIT_CLOSE_PATH "textures/exit_close.xpm"
# define EXIT_OPEN_PATH "textures/exit_open.xpm"
# define COLLECTIBLE_PATH "textures/collectible.xpm"
# define FREE_SPACE_PATH "textures/free_space.xpm"
# define WALL_PATH "textures/wall.xpm"
# define ENEMY_PATH "textures/enemy.xpm"

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define ESC 53

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
	int			tile_size;
	size_t		width;
	size_t		height;
	size_t		walls;
	size_t		collectibles;
	size_t		free_space;
	size_t		map_exit;
	size_t		player_start;
	size_t		enemy;

}				t_map;

typedef struct s_imgs
{
	void		*col;
	void		*player;
	void		*exit_close;
	void		*exit_open;
	void		*wall;
	void		*free_space;
	void		*enemy;
}				t_imgs;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
	int			widht;
	int			height;
	t_imgs		imgs;

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
int				check_av(int ac, char **av);
int				check_map(t_so_long *so_long, int ac, char **av);
int				check_tiles(t_so_long *so_long);
int				check_paths(t_so_long *so_long);

// moves
int				go_up(t_so_long *sl);
int				go_down(t_so_long *sl);
int				go_left(t_so_long *sl);
int				go_right(t_so_long *sl);

// my mlx functions
int				my_mlx_init(t_so_long *so_long, void **mlx);
int				my_mlx_put_frame(t_so_long *sl);

// get function
size_t			get_line_width(char *line);

// utils
int				map_visited_init(t_so_long *so_long);
void			map_visited_init_val(t_so_long *so_long);
int				bfs_init_data(t_so_long *so_long);
void			*tiledup(size_t r, size_t c);
void			calc_win_wh(t_so_long *so_long);
void			put_frame(t_so_long *so_long);

// clear functions
void			map_clear(t_so_long *so_long);
void			map_visited_clear(t_so_long *so_long);
void			map_clear_failed_malloc(char **map);
void			sl_clear(t_so_long **so_long);

#endif
