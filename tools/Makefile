# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 15:10:48 by yoel-idr          #+#    #+#              #
#    Updated: 2022/12/18 13:57:16 by yoel-idr         ###   ########.fr        #
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

RED    := \033[1;31m
GREEN  := \033[1;32m
YELLOW := \033[1;33m
BLUE   := \033[1;34m
RESET  := \033[0m

all     : $(NAME)
			@echo "$(RED)\n <TOOLS LIBRARY CREATED SUCCESSFULLY> $(RESET)"
			@mv $(NAME) ../lib

$(NAME) : $(OBJS)
			@$(SET) && ar -rc $(NAME) $^

.c.o	:
			@echo " COMPILING SOURCE FILES :  $(YELLOW) $< ... $(RESET)"
			@$(CC) $(FLAG) -c $< -o $@	
clean	:
			@$(RM) $(OBJS)
fclean  : clean
			@$(RM) ../lib $(NAME)
		
re 	    : fclean all

.PHONY : all clean fclean