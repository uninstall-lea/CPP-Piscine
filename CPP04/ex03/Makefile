NAME		=	AMateria

SRCS		=	main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp

INCS		=	AMateria.hpp ICharacter.hpp Character.hpp Cure.hpp Ice.hpp IMateriaSoucre.hpp MateriaSource.hpp

CC			=	c++

CFLAGS		=	-Wall -Werror -Wextra -Wshadow -Wno-shadow -std=c++98 -g3

RM			=	rm -f

OBJ			=	$(SRCS:.cpp=.o)

all			:	$(NAME)

%.o : %.cpp
				$(CC) $(CFLAGS) -o $@ -c $< 

$(NAME)		:	$(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 
		
clean		:	
				$(RM) $(OBJ)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	clean fclean re all