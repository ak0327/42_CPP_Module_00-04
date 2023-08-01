NAME		= a.out

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -MP

ifdef WITH_SANITIZE
	CXXFLAGS += -g -fsanitize=address
endif

SRCS		= main.cpp \
			  Animal.cpp \
			  Cat.cpp \
			  Dog.cpp \
			  Brain.cpp

OBJ_DIR		= objs
OBJ			= $(SRCS:%.cpp=%.o)
OBJS		= $(addprefix $(OBJ_DIR)/, $(OBJ))

DEPS		= $(OBJS:%.o=%.d)


all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $$(dirname $@)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean	:
	rm -rf $(OBJ_DIR)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

sani	:
	make all WITH_SANITIZE=1

run		: re
	./$(NAME)

srun	:
	make sani
	./$(NAME)

.PHONY	: all clean fclean re run sani sran

-include $(DEPS)