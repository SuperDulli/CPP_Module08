CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -Wshadow -pedantic-errors

NAME	= mutant_stack
TMPLATES= MutantStack.hpp displayContainer.hpp
HEADERS	= $(patsubst %.cpp,%.hpp,$(CLASSES)) $(TMPLATES)
SRCS	= main.cpp $(CLASSES)
OBJDIR	= obj
OBJS	= $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS))

NAMELIST= list
STACKOUT= stackout.txt
LISTOUT	= listout.txt

all: $(NAME) $(NAMELIST)

clean:
	rm -rf $(OBJDIR)
	rm -rf $(NAME).dSYM
	rm -rf $(NAMELIST).dSYM

fclean: clean
	rm -f $(NAME)
	rm -f $(NAMELIST)
	rm -f $(STACKOUT)
	rm -f $(LISTOUT)

re: fclean
	make all

show:
	@echo HEADERS=$(HEADERS)
	@echo SRCS=$(SRCS)
	@echo OBJS=$(OBJS)

debug: fclean
debug: CXXFLAGS := $(CXXFLAGS) -g
debug: all

leaks: $(NAME)
	leaks --atExit -- ./$(NAME)

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

test: $(NAME)
	./$(NAME)

compare: all
	./$(NAME) > $(STACKOUT)
	./$(NAMELIST) > $(LISTOUT)
	diff --side-by-side $(STACKOUT) $(LISTOUT)

$(NAME): $(OBJS) $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJDIR)/%.o: %.cpp $(TMPLATES) | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)

$(NAMELIST): $(patsubst main.cpp, main_list.cpp, $(SRCS)) $(HEADERS) $(TMPLATES)
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: all clean fclean re show debug leaks test valgrind
