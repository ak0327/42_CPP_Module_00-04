CXX			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -MP -pedantic

NAME		= phonebook

SRCS		= PhoneBook.cpp \
			  Contact.cpp \
			  main.cpp

OBJ_DIR		= objs
OBJ			= $(SRCS:%.cpp=%.o)
OBJS		= $(addprefix $(OBJ_DIR)/, $(OBJ))

DEPS		= $(SRCS:%.cpp=%.d)


all	: $(NAME)

$(NAME)	: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $$(dirname $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean	:
	rm -rf $(OBJ_DIR)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

run		: all
	./$(NAME)

.PHONY	: all clean fclean re

-include $(DEPS)