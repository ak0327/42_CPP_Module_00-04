NAME		= a.out

CC			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS		= main.cpp
OBJS		= $(SRCS:%.cpp=%.o)

all	: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $^

$(OBJS)	: $(SRCS)
	$(CC) $(CXXFLAGS) -o $@  -c $<

clean	:
	rm -rf $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

.PYONY	: all clean fclean re
