.PHONY = all clean fclean re

NAME = philo

CC = gcc

GFLAGS = -Wall -Wextra -Werror -pthread

HEAD = philo.h 

SRCS = philo.c utils.c parse_args.c

OBJS =$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(GFLAGS) $(SRCS) -o $(NAME)

$(OBJS) : %.o : %.c $(HEAD)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all