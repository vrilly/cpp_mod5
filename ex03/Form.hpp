// Created by Tom Jans on 10/22/20.

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    std::string name;
    bool formSigned;
    int gradeTresholdSigning;
    int gradeTresholdExecute;
protected:
    Form();
    void execute(const Bureaucrat &executor) const;
public:
    Form(const std::string &name,
         int gradeTresholdSigning,
         int gradeTresholdExecute);
    Form(const Form &form);
    Form &operator=(const Form &form);
    virtual ~Form();
    const std::string &getName() const;
    bool isSigned() const;
    int getGradeTresholdSigning() const;
    int getGradeTresholdExecute() const;
    void beSigned(const Bureaucrat &bureaucrat);
    virtual void beExecuted(const Bureaucrat &executor) const = 0;

    class GradeTooHighException: public std::exception
    {
    public:
        GradeTooHighException();
        GradeTooHighException(const GradeTooHighException &exception);
        GradeTooHighException &
        operator=(const GradeTooHighException &exception);
        virtual ~GradeTooHighException() _NOEXCEPT;
        virtual const char *what() const _NOEXCEPT;
    };

    class GradeTooLowException: public std::exception
    {
    public:
        GradeTooLowException();
        GradeTooLowException(const GradeTooLowException &exception);
        GradeTooLowException &operator=(const GradeTooLowException &exception);
        virtual ~GradeTooLowException() _NOEXCEPT;
        virtual const char *what() const _NOEXCEPT;
    };

    class FormNotSignedException: public std::exception
    {
    public:
        FormNotSignedException();
        FormNotSignedException(const FormNotSignedException &exception);
        FormNotSignedException &
        operator=(const FormNotSignedException &exception);
        virtual ~FormNotSignedException() _NOEXCEPT;
        virtual const char *what() const _NOEXCEPT;
    };
};

std::ostream &operator<<(std::ostream &ostream, const Form &form);

#endif //FORM_HPP
