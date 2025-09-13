# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 13:49:50 by fayfang           #+#    #+#              #
#    Updated: 2025/08/10 15:49:20 by fayfang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
HEADER	=	include/push_swap.h
SRCDIR	=	src
OBJDIR	=	obj

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -Iinclude -Ilibft/include
RM		=	rm -rf

SRC		=	$(wildcard $(SRCDIR)/*.c)
OBJ		=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

LIBFT	=	libft
LIB		=	$(LIBFT)/libft.a
LIBSRC	=	$(wildcard $(LIBFT)/$(SRCDIR)/*.c)

all:		$(NAME)

$(NAME):	$(OBJ) $(LIBSRC)
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