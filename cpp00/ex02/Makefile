CC			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -MP

NAME		= account

SRCS		= Account.cpp \
			  tests.cpp

OBJ_DIR		= objs
OBJ			= $(SRCS:%.cpp=%.o)
OBJS		= $(addprefix $(OBJ_DIR)/, $(OBJ))

DEPS		= $(SRCS:%.cpp=%.d)


all	: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o	: %.cpp
	@mkdir -p $$(dirname $@)
	$(CC) $(CXXFLAGS) -c $< -o $@

clean	:
	rm -rf $(OBJ_DIR)

fclean	: clean
	rm $(NAME)

re		: fclean all

run		: all
	./$(NAME)

.PHONY	: all clean fclean re run

-include $(DEPS)