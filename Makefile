# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlanette <wlanette@student.21-school.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 17:37:46 by wlanette          #+#    #+#              #
#    Updated: 2021/10/14 20:18:11 by wlanette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	 = 	./srcs/*.c	
OBJS 	 = 	$(patsubst %c,%.o,$(SRCS))
D_FILES  = 	$(patsubst %.c,%.d,$(SRCS))

NAME 	 =	libftprintf.a
LIBC 	 =	ar rcs
RM   	 =	rm -rf

CC		 = 	clang
CFLAGS   =	-Wall -Wextra -Weror
OPTFLAGS = 	-O2


$(NAME):	$(OBJS)
			$(LIBC) $(NAME) $(OBJS)

all:		$(NAME)
			
%.o : %.c
			$(CC) $(CFLAGS) $(OPTFLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean:
			$(RM) $(OBJS) $(D_FILES)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

build:
			$(CC) $(OPTFLAGS) $(SRCS) -I ./includes -o $(NAME) 

.PHONY:		all clean fclean re build $(NAME)
