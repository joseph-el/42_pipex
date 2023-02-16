# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 15:42:42 by yoel-idr          #+#    #+#              #
#    Updated: 2023/02/16 15:52:57 by yoel-idr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex

SRC   				:=  /src
INC	  				:=  include/
FILES				:=  pipex.c \
						utils.c \
						herdoc.c
FILES 				:= $(addprefix $(SRC), $(FILES))


OBJS   				:= $(FILES:%.c=%.o)
GC_MEMORY_PATH		:= gc_memory/
GC_MEMORY			:= $(addprefix $(GC_MEMORY_PATH), gc_memory.a)

all : $(NAME)
		
$(NAME) : $(GC_MEMORY) $(OBJS)
		$(CC) $(FLAG) $^ -o $@

$(GC_MEMORY)    	:  	$(addprefix $(GC_MEMORY_PATH), include/gc_memory.h)
							@make -C $(GC_MEMORY_PATH) all

.c.o		 		:	$(INC)
						@$(CC) $(FLAGS) -c $< -o $@ -I $(INC) -I $(addprefix $(GC_MEMORY_PATH), include)

clean 				: 
					rm -rf $(NAME)



