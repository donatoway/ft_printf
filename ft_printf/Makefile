# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/13 17:21:58 by dlanzilo          #+#    #+#              #
#    Updated: 2021/02/13 17:23:31 by dlanzilo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = analyze_options.c conversion.c ft_printf.c ft_string.c ft_utils.c ft_utils2.c hex.c int.c  ifpercent.c ft_char.c ft_pointer.c ft_utils3.c ft_undecimal.c if_padding_int.c ft_utils4.c

OBJ = $(SRC:.c=.o)

SRCDIR = srcs
OBJDIR = objs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))
HEADER = -I includes

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror

NAME = libftprintf.a

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@/bin/mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(HEADER) $< -o $@

$(NAME): $(OBJS)
	@ar rcs $@ $^
	@ranlib $@
	@echo "   Ben Fatto BOMBER   !!!!!"
clean:
	@/bin/rm -rf $(OBJDIR)
	@echo "[ft_printf - clean]"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "[fclean eseguito con successo]"

re: fclean all
