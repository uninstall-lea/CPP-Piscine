NAME		=	base

SRCS		=	main.cpp

INCS		=	Base.hpp

CC			=	c++

CFLAGS		=	-Wall -Werror -Wextra -std=c++98 -g3

RM			=	rm -f

OBJ			=	$(SRCS:.cpp=.o)

all			:	$(NAME)

%.o : %.cpp
				$(CC) $(CFLAGS) -o $@ -c $< 

$(NAME)		:	$(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 
		
clean		:	
				$(RM) $(OBJ) *_shrubbery

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	clean fclean re all