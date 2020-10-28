NAME = ex01

OBJS = main.o Bureaucrat.o Form.o
HDRS = Bureaucrat.hpp Form.hpp

CXXFLAGS := $(CXXFLAGS) -Wall -Wextra -Werror -std=c++98

%.o : %.cpp $(HDRS)
	clang++ $(CXXFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	clang++ $(LDFLAGS) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
