CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -Wshadow -pedantic-errors

NAME	= easyfind
# CLASSES	=
TMPLATES= displayContainer.hpp easyfind.hpp
HEADERS	= $(patsubst %.cpp,%.hpp,$(CLASSES)) $(TMPLATES)
SRCS	= main.cpp $(CLASSES)
OBJDIR	= obj
OBJS	= $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS))

all: $(NAME)

clean:
	rm -rf $(OBJDIR)
	rm -rf $(NAME).dSYM

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

show:
	@echo HEADERS=$(HEADERS)
	@echo SRCS=$(SRCS)
	@echo OBJS=$(OBJS)

debug: fclean
debug: CXXFLAGS := $(CXXFLAGS) -g
debug: all

leaks: all
	leaks --atExit -- ./$(NAME)

valgrind: debug
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

test: all
	./$(NAME)

$(NAME): $(OBJS) $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJDIR)/%.o: %.cpp $(TMPLATES) | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)

.PHONY: all clean fclean re show debug leaks test valgrind
