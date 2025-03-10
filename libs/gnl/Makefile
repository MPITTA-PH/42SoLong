# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpitta-p <mpitta-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 16:03:18 by mpitta-p          #+#    #+#              #
#    Updated: 2025/03/10 16:04:52 by mpitta-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = get_next_line.c get_next_line_utils.c
BONUS_SOURCES = bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c

OBJ = $(SOURCES:.c=.o)
BONUS_OBJ = $(BONUS_SOURCES:.c=.o)
RM = rm -f
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME) $(BONUS_OBJ)
	@$(AR) $(NAME) $(BONUS_OBJ)

clean:
	@$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus