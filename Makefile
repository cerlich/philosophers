.PHONY = all clean fclean re

NAME = philo

CC = gcc

GFLAGS = -Wall -Wextra -Werror

HEAD = philo.h 

SRCS = philo.c utils.c

OBJS =$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

$(OBJS) : %.o : %.c $(HEAD)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all