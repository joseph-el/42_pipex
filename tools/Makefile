# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 15:10:48 by yoel-idr          #+#    #+#              #
#    Updated: 2023/01/06 12:21:56 by yoel-idr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := tools.a

SRCS := ft_strlcpy.c ft_putstr.c ft_putstr_fd.c ft_split.c ft_strlen.c ft_strchr.c ft_strncmp.c\
		ft_lstnew.c ft_lstadd_back.c ft_lstclear.c ft_strjoin.c get_next_line_utils.c get_next_line.c \

FLAG := -Wall -Wextra -Werror
OBJS := $(SRCS:.c=.o)
SET	 := rm -drf ../lib && mkdir ../lib
AR   := ar -rc
RM   := rm -drf
CC   := cc

RED    := \033[0;31m
GREEN  := \033[0;32m
YELLOW := \033[0;33m
BLUE   := \033[0;34m
RESET  := \033[0m

all     : $(NAME)
			@echo "\033[0;32m\n\n\n<Tools Library Created Successfully>$(RESET)"
			@echo "\nFor the students 42 who want to apply ur tests,\n"
			@echo "I want to tell u this version of the project does not handle\n"
			@echo "all tests like the version in my profile at intra 😃\n"
			@mv $(NAME) ../lib

$(NAME) : $(OBJS)
			@$(SET) && ar -rc $(NAME) $^

.c.o	:
			@printf "\033[0;33mGenerating tools.a objects... %-100.100000s\r" $@
			@$(CC) $(FLAG) -c $< -o $@	
clean	:
			@$(RM) $(OBJS)
fclean  : clean
			@$(RM) ../lib $(NAME)
		
re 	    : fclean all

.PHONY : all clean fclean