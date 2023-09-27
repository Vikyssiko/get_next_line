# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkozlova <vkozlova@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 09:29:49 by vkozlova          #+#    #+#              #
#    Updated: 2023/05/31 11:24:55 by vkozlova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	get_next_line.a

SRCS		=	get_next_line.c \
				get_next_line_utils.c

BONUS_SRC	=	get_next_line_bonus.c \
				get_next_line_utils_bonus.c

BONUS_OBJ	=	get_next_line_bonus.o \
				get_next_line_utils_bonus.o

OBJS		=	get_next_line.o \
				get_next_line_utils.o

CFLAGS		+=	-Wall \
				-Wextra \
				-Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar vrcs $(NAME) $(OBJS)

clean: 
	rm -f $(OBJS) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY:	re fclean clean all bonus

bonus:	$(OBJS) $(BONUS_OBJ)
	@ar rc $(NAME) $(OBJS) $(BONUS_OBJ)