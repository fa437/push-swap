# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 15:29:21 by fasare            #+#    #+#              #
#    Updated: 2024/01/01 06:03:40 by fasare           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

SRCS			= checks.c clear.c \
				  list_opt_utils.c list_optimisation.c list_utils.c  ll_operations.c \
 				  push_swap.c \
				  operations.c \
				  utils.c
				  
OBJS			= $(SRCS:.c=.o)

CC				= cc
RM 				= rm -rf

CFLAGS			= -Wall -Wextra -Werror -O3

LIBFT_DIR =		./libft/
LIBFT	  =		$(LIBFT_DIR)/libft.a

FSANITIZE 		= -fsanitize=address -g3

all:			$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@


$(NAME):		$(OBJS) $(LIBFT)
				$(CC) $(OBJS) $(CFLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

				
clean:			
	$(RM) $(OBJS)
	make clean -C $(LIBFT_DIR)
			
						
fclean: clean			
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re