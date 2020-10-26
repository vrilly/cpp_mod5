// Created by Tom Jans on 10/22/20.

#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, const int grade)
    : name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

const std::string &Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
    *this = bureaucrat;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
    this->name = bureaucrat.getName();
    this->grade = bureaucrat.getGrade();
    return *this;
}

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat)
{
    ostream << bureaucrat.getName() << ", bureaucrat grade <"
            << bureaucrat.getGrade() << ">" << std::endl;
    return ostream;
}

void Bureaucrat::incGrade()
{
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decGrade()
{
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

Bureaucrat::GradeTooHighException::GradeTooHighException() {}

Bureaucrat::GradeTooHighException::~GradeTooHighException() _NOEXCEPT {}

Bureaucrat::GradeTooHighException::GradeTooHighException(const Bureaucrat::GradeTooHighException &gradeTooHighException)
{
    *this = gradeTooHighException;
}

Bureaucrat::GradeTooHighException &
Bureaucrat::GradeTooHighException::operator=(const Bureaucrat::GradeTooHighException &gradeTooHighException)
{
    (void) gradeTooHighException;
    return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too High!";
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() _NOEXCEPT {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const Bureaucrat::GradeTooLowException &gradeTooLowException)
{
    *this = gradeTooLowException;
}

Bureaucrat::GradeTooLowException &
Bureaucrat::GradeTooLowException::operator=(const Bureaucrat::GradeTooLowException &gradeTooLowException)
{
    (void) gradeTooLowException;
    return *this;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}
