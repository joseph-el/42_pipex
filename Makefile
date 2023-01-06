# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 00:47:48 by yoel-idr          #+#    #+#              #
#    Updated: 2023/01/06 12:19:44 by yoel-idr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= pipex

SRC 		:= ./src/pipex.c ./src/utils.c
SRC_BNS 	:= ./src/pipex_bonus.c ./src/herdoc.c ./src/utils.c
LIB	     	:= pipex.a
LIB_BNS		:= pipex_bonus.a
FLAGS 		:= -Wextra -Wall -Werror
CC 			:= cc
AR			:= ar -rc
RM   		:= rm -drf
OBJ			:= $(SRC:.c=.o)
OBJ_BNS		:= $(SRC_BNS:.c=.o)

GREEN     	:= \033[0;32m
RESET  	    := \033[0m
RED         := \033[0;31m


all 		: 	$(NAME)
				@echo "$(GREEN)\n <pipex Created Successfully> $(RESET)"

$(NAME) 	: 	$(LIB)
				@$(CC) $(FLAGS) ./lib/pipex.a ./lib/tools.a -o $(NAME)

$(LIB) 	: 	$(OBJ)
				@$(MAKE) -C tools
				@$(RM) $(LIB_BNS)
				@$(AR) $(LIB) $(OBJ)
				@mv $(LIB) ./lib

bonus 		:	$(LIB_BNS)
				@echo "$(GREEN)\n <pipex Created Successfully> $(RESET)"

$(LIB_BNS) 	: 	$(OBJ_BNS)
				@$(MAKE) -C tools
				@$(RM) $(LIB)
				@$(AR) $(LIB_BNS) $(OBJ_BNS)
				@mv $(LIB_BNS) ./lib
				@$(CC) $(FLAGS) ./lib/pipex_bonus.a  ./lib/tools.a -o $(NAME)
.c.o:
		@$(CC) $(FLAGS) -c $< -o $@
	
clean 		: 
				@echo "$(RED)\n <Removing objects> $(RESET)"
				@make -C tools clean
				@$(MAKE) -C tools fclean
				@$(RM) $(LIB) $(LIB_BNS) $(OBJ_BNS) $(OBJ)

fclean  	: 	clean
				@echo "$(RED)\n <Cleaning And Removing libtools Library / Executable File> $(RESET)"
				@make -C tools fclean
				@$(RM) $(NAME)

re 	    	: 	fclean all
				@echo "$(GREEN)\n < Remake Successfully> $(RESET)"

.PHONY : all bonus clean fclean















