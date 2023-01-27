# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 22:24:25 by yrhiba            #+#    #+#              #
#    Updated: 2023/01/28 00:31:01 by yrhiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	so_long.c \
		parse/so_long_init.c \
		parse/check_map.c \
		parse/check_tiles.c \
		parse/check_paths.c \
		get_funcs/get_line_width.c \
		utils/tiledup.c \
		utils/map_visited_init.c \
		utils/bfs_init_data.c \
		clear/map_clear.c \
		clear/sl_clear.c

INCS = so_long.h libft/libft.h libmylist/my_list.h

OBJDIR = obj/
OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))

COMPILER = cc

OBJFLAGS = -Wall -Wextra #-Werror
OBJIFLAGS = -I libft -I libmylist -I .

LIBFLAGS = -Llibft -lft -Llibmylist -lmylist -lmlx -lm -framework OpenGL -framework AppKit

$(NAME) : $(OBJS)
	make -C libft
	make -C libmylist
	$(COMPILER) $(OBJS) $(LIBFLAGS) -o $(NAME) -fsanitize=address

all : $(NAME)

$(OBJDIR)%.o : %.c $(INCS)
	@mkdir -p $(dir $@)
	$(COMPILER) $(OBJFLAGS) $(OBJIFLAGS) -c $< -o $@

clean :
	make fclean -C libft
	make fclean -C libmylist
	rm -rf $(OBJDIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus : all

.PHONEY : all clean fclean re bonus
