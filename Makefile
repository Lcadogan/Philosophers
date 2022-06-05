NAME	= philo

HEADER	= includes/philo.h

SRC		= src/philo.c\
			src/cr_philo.c\
			src/parse.c\
			src/simulation.c\
			src/utils.c\
			src/ft_atoi.c\

CC		= gcc

RM		= rm -f

MAKE	= make

FLAGS	= -Wall -Wextra -Werror

.c.o:	
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

OBJ	= $(SRC:.c=.o)

all:	$(NAME)
 
$(NAME):	$(OBJ) $(HEADER)
			${CC} $(FLAGS) -o ${NAME} ${SRC}

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
