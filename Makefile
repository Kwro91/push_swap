# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besalort <besalort@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 16:14:38 by besalort          #+#    #+#              #
#    Updated: 2023/10/09 13:19:15 by besalort         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAMEB = checker

SRC = ./src/push_swap.c \
	./src/swap.c \
	./src/reverse_rotate.c \
	./src/rotate.c \
	./src/push.c \
	./src/load.c \
	./src/verif.c \
	./src/printpile.c \
	./src/algo.c \
	./src/algo_bis.c \
	./src/algo_re-order.c \
	./src/algo_sort_element.c \
	./src/algo_use_r.c \
	./src/algo_sort_indice.c \
	./src/algo_update.c \
	./src/update_indice.c \
	./src/mediane.c \
	./src/free_all.c \
	
SRCB = ./bonus/checker_bonus.c \
	./bonus/do_cmds_bonus.c \
	./bonus/free_all_bonus.c \
	./bonus/is_sort_bonus.c \
	./bonus/load_bonus.c \
	./bonus/push_bonus.c \
	./bonus/read_all_bonus.c \
	./bonus/reverse_rotate_bonus.c \
	./bonus/rotate_bonus.c \
	./bonus/swap_bonus.c \
	./bonus/verif_bonus.c \
	./bonus/error_bonus.c \

LIBFT_PATH = ./src/libft/

LIBFT = $(LIBFT_PATH)libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

AR =  ar rcs

.c.o:	
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

$(NAME)	:	${OBJ}
		make -C $(LIBFT_PATH)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(NAMEB)	:	${OBJB}
		make -C $(LIBFT_PATH)
		$(CC) $(CFLAGS) $(OBJB) $(LIBFT) -o $(NAMEB)

all	:	$(NAME)

bonus : $(NAMEB)

clean :
		rm -rf $(OBJ) $(OBJB)
		make clean -C $(LIBFT_PATH)

fclean :	clean
		rm -rf $(NAME) $(NAMEB)
		make fclean -C $(LIBFT_PATH)

re : fclean all

.PHONY : all clean fclean re