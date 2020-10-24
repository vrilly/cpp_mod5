// Created by Tom Jans on 10/22/20.

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    std::string name;
    int grade;
    Bureaucrat();
public:
    Bureaucrat(const std::string &name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &bureaucrat);
    Bureaucrat &operator=(const Bureaucrat &bureaucrat);
    const std::string &getName() const;
    int getGrade() const;
    void incGrade();
    void decGrade();
    void signForm(Form *form);
    void executeForm(const Form &form);

    class GradeTooHighException: public std::exception
    {
    public:
        GradeTooHighException();
        virtual ~GradeTooHighException() _NOEXCEPT;
        GradeTooHighException(const GradeTooHighException &gradeTooHighException);
        GradeTooHighException &
        operator=(const GradeTooHighException &gradeTooHighException);
        const char *what() const _NOEXCEPT;
    };

    class GradeTooLowException: public std::exception
    {
    public:
        GradeTooLowException();
        virtual ~GradeTooLowException() _NOEXCEPT;
        GradeTooLowException(const GradeTooLowException &gradeTooLowException);
        GradeTooLowException &
        operator=(const GradeTooLowException &gradeTooLowException);
        const char *what() const _NOEXCEPT;
    };
};

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat);

#endif //BUREAUCRAT_HPP
