# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 22:24:25 by yrhiba            #+#    #+#              #
#    Updated: 2022/12/27 23:35:43 by yrhiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long.c

INCS = so_long.h libft/libft.h mlx/mlx.h

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	make -C libft
	make -C mlx
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all : $(NAME)

%.o : %.c $(INCS)
	$(CC) -Wall -Wextra -Werror -I libft -I mlx -c $< -o $@

clean :
	make clean -C mlx
	make fclean -C libft
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONEY : all clean fclean re
 