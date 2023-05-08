NAME		= a.out

CC			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -MP -g -fsanitize=address

SRCS		= main.cpp \
			  FileHandler.cpp \
              ReplaceHandler.cpp

OBJ_DIR		= objs
OBJ			= $(SRCS:%.cpp=%.o)
OBJS		= $(addprefix $(OBJ_DIR)/, $(OBJ))

DEPS		= $(OBJS:%.o=%.d)

all	: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o	: %.cpp
	@mkdir -p $$(dirname $@)
	$(CC) $(CXXFLAGS) -o $@ -c $<

clean	:
	rm -rf $(OBJ_DIR)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

run		: re
	./$(NAME)

.PHONY	: all clean fclean re

-include $(DEPS)