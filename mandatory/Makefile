NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
SRC = Philosophers.c check_arg.c philo_init.c event.c utile_philo.c
OBJ = $(SRC:.c=.o)

all		: util $(NAME)

$(NAME) : $(OBJ) $(M_OBJ)
	$(CC) $(CFLAGS) -lpthread -pthread -g3 $(OBJ) -o $(NAME)

util	:
	

clean	:
	@rm -f $(OBJ)

fclean	: clean
	@rm -rf $(NAME)

re		: fclean all