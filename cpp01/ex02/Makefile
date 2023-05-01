NAME		= a.out

CC			= g++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= main.cpp
OBJS		= $(SRCS:%.cpp=%.o)

all	: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@

$(OBJS)	: $(SRCS)
	$(CC) $(CXXFLAGS) -c $< -o $@

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

.PYONY	: all clean fclean re
