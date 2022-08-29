# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 11:05:56 by segarcia          #+#    #+#              #
#    Updated: 2022/08/29 12:36:20 by segarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAEMWORKS=-framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall
NAME=fdf
SRC=src/*.c
INCLUDES	=	ft_libft/libft.a \
 				ft_libft/get_next_line/get_next_line.a \
				ft_libft/ft_printf/libftprintf.a \
				minilibx_macos/libmlx.a

all:
	@make -C ft_libft/ all
	@make -C ft_libft/ft_printf all
	@make -C ft_libft/get_next_line all
	@make -C minilibx_macos/ all
	gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAEMWORKS)

clean:
	@make -C ft_libft/ clean
	@make -C ft_libft/ft_printf clean
	@make -C ft_libft/get_next_line clean
	@make -C minilibx_macos/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C ft_libft/ fclean
	@make -C ft_libft/ft_printf fclean
	@make -C ft_libft/get_next_line fclean

re: fclean all