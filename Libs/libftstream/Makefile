#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Make                                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 14:48:04 by mbarbari          #+#    #+#              #
#    Updated: 2015/10/22 12:50:22 by barbare          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftstream.a

OBJDIR = ./Objets

LIBS = -L../libft/ -lft 
INC =  -I ../libft/Include/

CFLAGS += -g -O0 -Wall -Wextra -Werror -I ./Include/ $(INC)

SRCS = 	Srcs/ft_stream_new.c			\
	Srcs/ft_stream_read.c			\

LIBFT_PATH ?= ../libft/

OBJS = $(patsubst Srcs/%.c,Objets/%.o,$(SRCS))

CP = cp

RM = rm -f

all: $(NAME)

$(OBJS): | Objets

Objets:
	@mkdir -p $@

Objets/%.o: Srcs/%.c
	@printf "\r\033[33;32mCompiling $<\n\033[33;0m"
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(LIBFT_PATH)/libft.a:
	@$(MAKE) -C $(LIBFT_PATH)/libft

$(NAME): $(LIBFT_PATH)/libft.a $(OBJS) 
	@printf "\r\033[33;40mCreate Library $(NAME)\n\033[33;0m"
	@$(CP) $(LIBFT_PATH)/libft.a $(NAME)
	@$(AR) -rcs $(NAME) $^

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re
