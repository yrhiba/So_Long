# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 22:24:25 by yrhiba            #+#    #+#              #
#    Updated: 2023/01/29 04:49:51 by yrhiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	so_long.c \
		my_mlx/my_mlx_init.c \
		parse/so_long_init.c \
		parse/check_av.c \
		parse/check_map.c \
		parse/check_tiles.c \
		parse/check_paths.c \
		get_funcs/get_line_width.c \
		utils/tiledup.c \
		utils/map_visited_init.c \
		utils/bfs_init_data.c \
		utils/calc_win_wh.c \
		clear/map_clear.c \
		clear/sl_clear.c

LIBFT_SRCS =	ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
				ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove \
				ft_strlcpy ft_strlcat ft_strchr ft_strrchr ft_strncmp \
				ft_memchr ft_memcmp ft_strnstr ft_calloc ft_strdup \
				ft_tolower ft_atoi  ft_toupper ft_substr ft_strjoin \
				ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_strtrim \
				ft_split ft_itoa ft_strmapi ft_striteri ft_putnbr_fd \
				ft_printf ft_sprintf ft_format ft_init_tab \
				ft_addchar ft_addstr \
				ft_converthex ft_itoa ft_isnum \
				ft_miniatoi \
				ft_check_format ft_check_flags ft_check_flags_utils \
				ft_format_c ft_format_s ft_format_s_utils \
				ft_format_d ft_format_u ft_format_x ft_format_x_utils \
				ft_format_p ft_lstnew ft_lstadd_front ft_lstsize \
				ft_lstlast ft_lstadd_back ft_lstdelone \
				ft_lstclear ft_lstiter ft_lstmap \
				get_next_line get_next_line_utils \
				ft_intdup ft_isint ft_strcmp

LIBFT_DIR = libft/
LIBFT_FILES = $(addprefix $(LIBFT_DIR), $(LIBFT_SRCS:=.c))


LIBMYLIST_SRCS =	my_list_init.c \
					my_list_clear.c \
					my_list_new_elem.c \
					my_list_push_back.c \
					my_list_push_front.c \
					my_list_front.c \
					my_list_back.c \
					my_list_empty.c \
					my_list_size.c \
					my_list_pop_front.c \
					my_list_pop_back.c \
					my_list_get.c \
					my_list_erase.c \
					my_list_insert.c

LIBMYLIST_DIR = libmylist/
LIBMYLIST_FILES = $(addprefix $(LIBMYLIST_DIR), $(LIBMYLIST_SRCS))

INCS = so_long.h libft/libft.h libmylist/my_list.h

OBJDIR = obj/
OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))

COMPILER = cc

OBJFLAGS = -Wall -Wextra -Werror
OBJIFLAGS = -I libft -I libmylist -I .

LIBFLAGS = -Llibft -lft -Llibmylist -lmylist -lmlx -lm -framework OpenGL -framework AppKit

$(NAME) : $(OBJS) $(LIBFT_FILES) $(LIBMYLIST_FILES)
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
