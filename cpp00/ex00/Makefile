####################################################
# COMPILE
CC			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98


####################################################
# PROGRAM NAME
NAME 		= megaphone

####################################################
# SRC/OBJ FILES
SRCS		= megaphone.cpp

OBJS		= $(SRCS:%.cpp=%.o)


####################################################
# RULES
all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@

$(OBJS)	: $(SRCS)
	$(CC) $(CXXFLAGS) -c $(SRCS)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re