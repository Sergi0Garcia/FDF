# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 11:05:56 by segarcia          #+#    #+#              #
#    Updated: 2022/09/22 11:48:51 by segarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAEMWORKS = -framework OpenGL -framework AppKit
FLAGS = -Werror -Wextra -Wall
NAME = fdf
SRC = src/*.c
INCLUDES	=	ft_libft/ft_bonus/libft_ft_bonus.a 			\
				ft_libft/ft_extra/libft_ft_extra.a 			\
 				ft_libft/ft_func/libft_ft_func.a 			\
				ft_libft/ft_printf/libftprintf.a			\
				ft_libft/get_next_line/get_next_line.a 		\
				minilibx_macos/libmlx.a
all:
	@make -C ft_libft/ all
	@make -C minilibx_macos/ all
	gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAEMWORKS)

clean:
	@make -C ft_libft/ clean
	@make -C minilibx_macos/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C ft_libft/ fclean

re: fclean all