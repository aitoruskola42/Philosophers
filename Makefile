NAME=philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c functions.c functions2.c ft_strlen.c ft_atoi.c\
					ft_isdigit.c ft_itoa.c

HEADER = philo.h  

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 
#	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -> si fuera un ejecutable
##	ar rc $(NAME) $(OBJS) $(BONUS_OBJS) >  ar rc para hacer libreria
$(OBJS): $(SRC) philo.h
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -f $(OBJS)   

fclean:
	rm -f *.o
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re  