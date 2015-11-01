#*************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Make                                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 14:48:04 by mbarbari          #+#    #+#              #
#    Updated: 2015/10/22 18:04:32 by barbare          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = stream.a

CFLAGS += -g -O0 -Wall -Wextra -Werror -I ./Include/ 

SRCS = 	Srcs/ft_stream_new.c			\
		Srcs/ft_stream_read.c			\


OBJS = $(patsubst Srcs/%.c,Objets/%.o,$(SRCS))

PINC = Include/

INC = $(PINC)ft_stream.h 

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
