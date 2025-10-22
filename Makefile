# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 13:49:50 by fayfang           #+#    #+#              #
#    Updated: 2025/10/22 17:28:19 by fayfang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
HEADER	=	include/push_swap.h
SRCDIR	=	src
OBJDIR	=	obj

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -Iinclude -Ilibft/include
RM		=	rm -rf

FILES	=	chunks_utils \
			chunks \
			error \
			instructions \
			main \
			move \
			operations \
			parse_utils \
			parse \
			print \
			queue_utils \
			queue \
			sort_small \
			sort_utils

SRC		=	$(addprefix $(SRCDIR)/, $(addsuffix .c, $(FILES)))
OBJ		=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

LIBFT	=	libft
LIB		=	$(LIBFT)/libft.a
# LIBSRC	=	$(addprefix $(LIBFT)/$(SRCDIR)/, $(addsuffix .c, $(LIBFILES)))

all:		$(NAME)

$(NAME):	$(OBJ) 
	@make -C $(LIBFT)
	$(CC) $(OBJ) -o $(NAME) $(LIB)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR)
	@make -C $(LIBFT) clean

fclean: 	clean
	@$(RM) $(NAME)
	@make -C $(LIBFT) fclean

re:			fclean all

.PHONY:		all clean fclean re