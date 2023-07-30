####################################################
# COMPILE
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic


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
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJS)	: $(SRCS)
	$(CXX) $(CXXFLAGS) -c $(SRCS)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re