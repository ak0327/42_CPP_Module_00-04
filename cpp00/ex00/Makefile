####################################################
# COMPILE
CC			= g++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98


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
	$(CC) $(CPPFLAGS) $^ -o $@

$(OBJS)	: $(SRCS)
	$(CC) $(CPPFLAGS) -c $(SRCS)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re