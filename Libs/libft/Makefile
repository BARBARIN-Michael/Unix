#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Make                                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 14:48:04 by mbarbari          #+#    #+#              #
#    Updated: 2015/06/09 12:17:30 by mbarbari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

CFLAGS += -O3 -Wall -Wextra -Werror -I ./Include/ -I ./../libftprintf/Include

SRCS = 	Srcs/ft_bzero.c			\
		Srcs/ft_memcpy.c		\
		Srcs/ft_memccpy.c		\
		Srcs/ft_memmove.c		\
		Srcs/ft_memchr.c		\
		Srcs/ft_memcmp.c		\
		Srcs/ft_strlen.c		\
		Srcs/ft_strdup.c		\
		Srcs/ft_strcpy.c		\
		Srcs/ft_strncpy.c		\
		Srcs/ft_strcat.c		\
		Srcs/ft_strncat.c		\
		Srcs/ft_strlcat.c		\
		Srcs/ft_strchr.c		\
		Srcs/ft_findchr.c		\
		Srcs/ft_strrchr.c		\
		Srcs/ft_strstr.c		\
		Srcs/ft_strchange.c		\
		Srcs/ft_strcmp.c		\
		Srcs/ft_strncmp.c		\
		Srcs/ft_strnew.c		\
		Srcs/ft_strdel.c		\
		Srcs/ft_strclr.c		\
		Srcs/ft_striter.c		\
		Srcs/ft_striteri.c		\
		Srcs/ft_strmap.c		\
		Srcs/ft_strmapi.c		\
		Srcs/ft_strequ.c		\
		Srcs/ft_strnequ.c		\
		Srcs/ft_strsub.c		\
		Srcs/ft_strjoin.c		\
		Srcs/ft_strjoin_free.c	\
		Srcs/ft_strtrim.c		\
		Srcs/ft_strsplit.c		\
		Srcs/ft_ptrsplit.c		\
		Srcs/ft_strtol.c		\
		Srcs/ft_atoi.c			\
		Srcs/ft_isalpha.c		\
		Srcs/ft_isdigit.c		\
		Srcs/ft_isalnum.c		\
		Srcs/ft_isascii.c		\
		Srcs/ft_isprint.c		\
		Srcs/ft_strisuporlow.c	\
		Srcs/ft_toupper.c		\
		Srcs/ft_tolower.c		\
		Srcs/ft_count_carac.c	\
		Srcs/ft_memalloc.c		\
		Srcs/ft_memdel.c		\
		Srcs/ft_memset.c		\
		Srcs/ft_realloc.c		\
		Srcs/ft_itoa.c			\
		Srcs/ft_putchar.c		\
		Srcs/ft_putstr.c		\
		Srcs/ft_putstr_c.c		\
		Srcs/ft_putendl.c		\
		Srcs/ft_putnbr.c		\
		Srcs/ft_putchar_fd.c	\
		Srcs/ft_putstr_fd.c		\
		Srcs/ft_putendl_fd.c	\
		Srcs/ft_lstnew.c		\
		Srcs/ft_lstdelone.c		\
		Srcs/ft_lstdel.c		\
		Srcs/ft_lstadd.c		\
		Srcs/ft_lstadd_back.c	\
		Srcs/ft_lstiter.c		\
		Srcs/ft_lstmap.c		\
		Srcs/ft_lstnew.c		\
		Srcs/ft_replace.c		\
		Srcs/ft_round.c			\
		Srcs/ft_insert.c		\
		Srcs/get_nbr_line.c		\
		Srcs/get_next_line.c	\
		Srcs/ft_array_count.c	\
		Srcs/ft_pow.c			\
		Srcs/ft_ntoa.c			\
		Srcs/ft_strset.c		\
		Srcs/ft_wtoa.c			\
		Srcs/ft_tabcpy.c		\
		Srcs/ft_strisempty.c


OBJS = $(patsubst Srcs/%.c,Objets/%.o,$(SRCS))

PINC = Include/

INC = $(PINC)def.h $(PINC)ft_checking.h $(PINC)get_next_line.h $(PINC)libft.h

RM = rm -f


all: $(NAME)

Objets:
	@mkdir -p $@

Objets/%.o: Srcs/%.c $(INC)
	@printf "\r\033[33;32mCompiling $<\033[33;0m\n"
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(NAME): $(OBJS)
	@printf "\r\033[33;40mCreate Library $(NAME)\033[33;0m\n"
	@$(AR) -rsc $(NAME) $?

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

fcleanall: fclean
	@$(RM) $(EXE)

re: fclean Objets all

.PHONY: fclean Objets all fcleanall clean
