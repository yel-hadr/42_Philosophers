NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = 
OBJ = $(SRC:.c=.o)

all		: util $(NAME)

$(NAME) : $(OBJ) $(M_OBJ)
	$(CC) $(CFLAGS) -pthread -O3 $(OBJ) -o $(NAME)

util	:
	

clean	:
	@rm -f $(OBJ)

fclean	: clean
	@rm -rf $(NAME)

re		: fclean all