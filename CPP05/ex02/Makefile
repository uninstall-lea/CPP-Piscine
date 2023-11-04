NAME		=	bureaucrat

SRCS		=	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

INCS		=	Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp

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
				$(RM) $(OBJ) Default_shrubbery

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	clean fclean re all