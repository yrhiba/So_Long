# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrhiba@student.1337.ma <yrhiba>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 22:24:25 by yrhiba            #+#    #+#              #
#    Updated: 2023/01/24 21:59:42 by yrhiba@stud      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long.c

INCS = so_long.h libft/libft.h mlx/mlx.h

OBJDIR = obj/
OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))

COMPILER = cc

OBJFLAGS = -Wall -Wextra -Werror
OBJIFLAGS = -I libft -I mlx -I libmylist -I .

LIBFLAGS = -Llibft -lft -Llibmylist -lmylist -Lmlx -lmlx -framework OpenGL -framework AppKit

$(NAME) : $(OBJS)
	make -C libft
	make -C libmylist
	make -C mlx
	$(COMPILER) $(OBJS) $(LIBFLAGS) -o $(NAME)

all : $(NAME)

$(OBJDIR)%.o : %.c $(INCS)
	@mkdir -p $(dir $@)
	$(COMPILER) $(OBJFLAGS) $(OBJIFLAGS) -c $< -o $@

clean :
	make fclean -C libft
	make fclean -C libmylist
	make clean -C mlx
	rm -rf $(OBJDIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus : all

.PHONEY : all clean fclean re bonus
