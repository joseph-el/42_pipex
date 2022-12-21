# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 00:47:48 by yoel-idr          #+#    #+#              #
#    Updated: 2022/12/19 09:11:33 by yoel-idr         ###   ########.fr        #
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

GREEN  	:= \033[1;32m
RESET  	:= \033[0m

all 		: 	$(NAME)
				@echo "$(GREEN)\n <U CAN USE PIPEX> $(RESET)"

$(NAME) 	: 	$(LIB)
				@$(CC) $(FLAGS) ./lib/pipex.a ./lib/tools.a -o $(NAME)

$(LIB) 	: 	$(OBJ)
				@$(MAKE) -C tools
				@$(RM) $(LIB_BNS)
				@$(AR) $(LIB) $(OBJ)
				@mv $(LIB) ./lib

bonus 		:	$(LIB_BNS)
				@echo "$(GREEN)\n <U CAN USE PIPEX_BONUS> $(RESET)"

$(LIB_BNS) 	: 	$(OBJ_BNS)
				@$(MAKE) -C tools
				@$(RM) $(LIB)
				@$(AR) $(LIB_BNS) $(OBJ_BNS)
				@mv $(LIB_BNS) ./lib
				@$(CC) $(FLAGS) ./lib/pipex_bonus.a  ./lib/tools.a -o $(NAME)
.c.o:
		@$(CC) $(FLAGS) -c $< -o $@
	
clean 		: 
				@echo "$(GREEN)\n <REMOVING OBJS> $(RESET)"
				@make -C tools clean
				@$(MAKE) -C tools fclean
				@$(RM) $(LIB) $(LIB_BNS) $(OBJ_BNS) $(OBJ)

fclean  	: 	clean
				@echo "$(GREEN)\n <CLEANING AND REMOVING libtools LIBRARYS / EXECUTABLE FILE> $(RESET)"
				@make -C tools fclean
				@$(RM) $(NAME)

re 	    	: 	fclean all
				@echo "$(GREEN)\n < ALL CLEAN SUCCESSFULLY> $(RESET)"

.PHONY : all bonus clean fclean
















