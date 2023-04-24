NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = check_arg_bonus.c philo.c creat_the_philo.c util_time_bonus.c utile_routine_bonus.c \
		start_the_routine.c check_death.c
OBJ = $(SRC:.c=.o)

all		: util $(NAME)

$(NAME) : $(OBJ) $(M_OBJ)
	$(CC) $(CFLAGS) -O3 $(OBJ) -o $(NAME)

util	:
	

clean	:
	@rm -f $(OBJ)

fclean	: clean
	@rm -rf $(NAME)

re		: fclean all