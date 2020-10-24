add_custom_command(
        OUTPUT asciitree.hpp
        DEPENDS asciitree.txt
        COMMAND xxd -i asciitree.txt asciitree.hpp
        COMMENT "Compiling asciitree.txt to header"
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
add_executable(ex02 main.cpp Bureaucrat.cpp Bureaucrat.hpp Form.cpp Form.hpp ShrubberyCreationForm.cpp ShrubberyCreationForm.hpp asciitree.hpp RobotomyRequestForm.cpp RobotomyRequestForm.hpp PresidentialPardonForm.cpp PresidentialPardonForm.hpp)