# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/17 11:04:15 by fde-waal          #+#    #+#              #
#    Updated: 2025/08/09 10:57:39 by fayfang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
HEADER	=	include/libft.h
SRCDIR	=	src
OBJDIR	=	obj

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -Iinclude
AR		=	ar -rcs
RM		=	rm -rf

SRC		=	$(wildcard $(SRCDIR)/*.c)
OBJ		=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

RED		=	\033[1;31m
GREEN	=	\033[1:32m
YELLOW	=	\033[1;33m
BLUE	=	\033[1;34m
OFF		=	\033[0m

all:		$(NAME)

$(NAME):	$(OBJ)
	@echo "$(YELLOW) Creating library. $(OFF)"
	@$(AR) $@ $(OBJ)

$(OBJDIR):
	@echo "$(YELLOW) Creating objects directory. $(OFF)"
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@echo "$(YELLOW) Compiling $< into $@. $(OFF)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW) Removing objects directory and files. $(OFF)"
	@$(RM) $(OBJDIR)

fclean:		clean
	@echo "$(YELLOW) Removing program file. $(OFF)"
	@$(RM) $(NAME)
	@$(RM) bonus

re:			fclean all

.PHONY:		all clean fclean re