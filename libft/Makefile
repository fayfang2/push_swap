# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/17 11:04:15 by fde-waal          #+#    #+#              #
#    Updated: 2025/09/22 16:03:57 by fayfang          ###   ########.fr        #
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

FILES	=	ft_atoi \
			ft_bzero \
			ft_calloc \
			ft_isalnum \
			ft_isalpha \
			ft_isascii \
			ft_isdigit \
			ft_isprint \
			ft_itoa \
			ft_lstadd_back \
			ft_lstadd_front \
			ft_lstclear \
			ft_lstdelone \
			ft_lstiter \
			ft_lstlast \
			ft_lstmap \
			ft_lstnew \
			ft_lstsize \
			ft_memchr \
			ft_memcmp \
			ft_memcpy \
			ft_memmove \
			ft_memset \
			ft_printchar \
			ft_printf \
			ft_printnbr \
			ft_putchar_fd \
			ft_putendl_fd \
			ft_putnbr_fd \
			ft_putstr_fd \
			ft_split \
			ft_strchr \
			ft_strdup \
			ft_striteri \
			ft_strjoin \
			ft_strlcat \
			ft_strlcpy \
			ft_strlen \
			ft_strmapi \
			ft_strncmp \
			ft_strnstr \
			ft_strrchr \
			ft_strtrim \
			ft_substr \
			ft_tolower \
			ft_toupper


SRC		=	$(addprefix $(SRCDIR)/, $(addsuffix .c, $(FILES)))
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