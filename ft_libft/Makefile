# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 12:49:46 by segarcia          #+#    #+#              #
#    Updated: 2022/09/22 11:44:54 by segarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= 	libft.a

all:
	@make -C ft_bonus/ all
	@make -C ft_extra/ all
	@make -C ft_func/ all
	@make -C ft_printf/ all
	@make -C get_next_line/ all

clean:
	@make -C ft_bonus/ clean
	@make -C ft_extra/ clean
	@make -C ft_func/ clean
	@make -C ft_printf/ clean
	@make -C get_next_line/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C ft_bonus/ fclean
	@make -C ft_extra/ fclean
	@make -C ft_func/ fclean
	@make -C ft_printf/ fclean
	@make -C get_next_line/ fclean

re: fclean all