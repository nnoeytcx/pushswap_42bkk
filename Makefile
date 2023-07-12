# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/04 22:43:09 by tpoungla          #+#    #+#              #
#    Updated: 2023/07/12 20:48:38 by tpoungla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
CFLAGS = -Wall -Wextra -Werror -g 

CC = gcc

FILES = main.c lst_prop1.c lst_prop2.c tools1.c tools2.c tools3.c \
push_swap.c ft_p_action.c ft_r_action.c ft_rr_action.c ft_s_action.c \

OBJ	:= $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "complied done!"

norm:
	norminette -R checkforbiddensourceheader $(FILES)
	norminette -R checkdefine push_swap.h
clean:
	@rm -f $(OBJ)
	@echo "yep, cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "tidy -- totally cleaned!"

re: fclean all

.PHONY: clean fclean all re norm