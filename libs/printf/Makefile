# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 15:10:30 by miguelhenri       #+#    #+#              #
#    Updated: 2025/03/10 14:46:58 by mpitta-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = ft_printf.c ft_print_format.c ft_putchar.c \
	ft_putstr.c ft_putnbr.c ft_putunbr.c ft_puthexa.c ft_putptr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo "$(NAME) created"

cc: $(CFLAGS) $(SRCS)

clean:
	@$(RM) $(OBJS)
	@echo "objects deleted"

fclean: clean
	@$(RM) $(NAME)
	@echo "ft_printf deleted"

re: clean all

.PHONY: all clean fclean re
