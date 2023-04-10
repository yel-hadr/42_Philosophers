NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
SRC = Philosophers.c check_arg.c creating_the_fork.c craet_info.c start_the_philo.c utile_philo.c
OBJ = $(SRC:.c=.o)

all		: util $(NAME)

$(NAME) : $(OBJ) $(M_OBJ)
	$(CC) $(CFLAGS) -lpthread $(OBJ) -o $(NAME)

util	:
	

clean	:
	@rm -f $(OBJ)

fclean	: clean
	@rm -rf $(NAME)

re		: fclean all