# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrhiba@student.1337.ma <yrhiba>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 22:24:25 by yrhiba            #+#    #+#              #
#    Updated: 2023/01/25 00:02:28 by yrhiba@stud      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	so_long.c \
		parse/my_so_long_init.c

INCS = so_long.h libft/libft.h

OBJDIR = obj/
OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))

COMPILER = cc

OBJFLAGS = -Wall -Wextra #-Werror
OBJIFLAGS = -I libft -I libmylist -I .

LIBFLAGS = -Llibft -lft -Llibmylist -lmylist -lmlx -lm -framework OpenGL -framework AppKit

$(NAME) : $(OBJS)
	make -C libft
	make -C libmylist
	$(COMPILER) $(OBJS) $(LIBFLAGS) -o $(NAME)

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
