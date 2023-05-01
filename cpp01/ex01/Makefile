NAME		= a.out

CC			= g++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -MP

SRCS		= main.cpp \
			  Zombie.cpp
OBJ_DIR		= objs
OBJ			= $(SRCS:%.cpp=%.o)
OBJS		= $(addprefix $(OBJ_DIR)/, $(OBJ))

DEPS		= $(OBJS:%.o=%.d)


all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@


$(OBJ_DIR)/%.o	: %.cpp
	@mkdir -p $$(dirname $@)
	$(CC) $(CXXFLAGS) -c $< -o $@

clean	:
	rm -rf $(OBJ_DIR)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re

-include $(DEPS)