NAME = ex02

OBJS =	main.o Bureaucrat.o Form.o \
		PresidentialPardonForm.o \
		RobotomyRequestForm.o \
		ShrubberyCreationForm.o \
		Intern.o
HDRS = Bureaucrat.hpp Form.hpp \
		PresidentialPardonForm.hpp \
		RobotomyRequestForm.hpp \
		ShrubberyCreationForm.hpp \
		Intern.hpp
GENHDRS = asciitree.hpp

CXXFLAGS := $(CXXFLAGS) -Wall -Wextra -Werror -std=c++98

%.o : %.cpp $(HDRS) $(GENHDRS)
	clang++ $(CXXFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	clang++ $(LDFLAGS) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS) $(GENHDRS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

asciitree.hpp : asciitree.txt
	xxd -i asciitree.txt asciitree.hpp
