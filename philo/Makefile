NAME = philo

OBJ = $(SRC:.c=.o)
CC = cc 
CFLAGS = -Wextra -Werror -Wall -g -I./includes -pthread -fsanitize=thread
RM = rm -f 

SRC =	./src/ft_actions.c				\
		./src/ft_init_structs.c			\
		./src/ft_can_continue.c			\
		./src/ft_routine.c				\
		./src/ft_get_time.c 			\
		./src/ft_atoi.c					\
		./src/ft_print_msg.c			\
		./src/ft_destroy_all.c			\
		./src/utils.c 					\
		./src/ft_check_args.c			\
		./src/main.c					\

all: $(NAME) 

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean: 
	$(RM) $(OBJ)

fclean: clean 
	$(RM) $(NAME)

re: clean all