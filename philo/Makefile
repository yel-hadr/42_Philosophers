NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = Philosophers.c check_arg.c creating_the_fork.c creat_info.c start_the_philo.c\
		 utile_routine.c util_time.c ft_exit.c parcing_util.c ft_check_death.c
OBJ = $(SRC:.c=.o)

all		: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -O3 -lpthread $(OBJ) -o $(NAME)

clean	:
	@rm -f $(OBJ)

fclean	: clean
	@rm -rf $(NAME)

re		: fclean all