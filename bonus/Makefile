NAME1 = client_bonus
NAME2 = server_bonus

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f


SRCS1 =  client_bonus.c ft_strlen.c

SRCS2 =  server_bonus.c

OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)


%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
all: $(NAME1) $(NAME2) 

$(NAME1): $(OBJS1)
	$(CC) $(FLAGS) -o $@ $^
$(NAME2): $(OBJS2)
	$(CC) $(FLAGS) -o $@ $^

clean:
	$(RM) $(OBJS1) $(OBJS2)	

fclean: clean
	$(RM) $(NAME1) $(NAME2)

re: fclean all