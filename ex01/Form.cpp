// Created by Tom Jans on 10/22/20.

#include "Form.hpp"

const std::string &Form::getName() const
{
    return name;
}

bool Form::isSigned() const
{
    return formSigned;
}

int Form::getGradeTresholdSigning() const
{
    return gradeTresholdSigning;
}

int Form::getGradeTresholdExecute() const
{
    return gradeTresholdExecute;
}

Form::Form(const std::string &name,
           int gradeTresholdSigning,
           int gradeTresholdExecute)
    : name(name), formSigned(false),
      gradeTresholdSigning(gradeTresholdSigning),
      gradeTresholdExecute(gradeTresholdExecute)
{
    if (gradeTresholdExecute > 150 || gradeTresholdSigning > 150)
        throw GradeTooLowException();
    if (gradeTresholdExecute < 1 || gradeTresholdSigning < 1)
        throw GradeTooHighException();
}

Form::Form()
{

}

Form::Form(const Form &form)
{
    *this = form;
}

Form &Form::operator=(const Form &form)
{
    if (this == &form)
        return *this;
    name = form.getName();
    formSigned = form.isSigned();
    gradeTresholdSigning = form.getGradeTresholdSigning();
    gradeTresholdExecute = form.getGradeTresholdExecute();
    return *this;
}

Form::~Form()
{

}

Form::GradeTooHighException::GradeTooHighException()
{

}

Form::GradeTooHighException::GradeTooHighException(const Form::GradeTooHighException &exception)
{
    *this = exception;
}

Form::GradeTooHighException &
Form::GradeTooHighException::operator=(const Form::GradeTooHighException &exception)
{
    (void) exception;
    return *this;
}

Form::GradeTooHighException::~GradeTooHighException() _NOEXCEPT
{

}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

Form::GradeTooLowException::GradeTooLowException()
{

}

Form::GradeTooLowException::GradeTooLowException(const Form::GradeTooLowException &exception)
{
    *this = exception;
}

Form::GradeTooLowException &
Form::GradeTooLowException::operator=(const Form::GradeTooLowException &exception)
{
    (void) exception;
    return *this;
}

Form::GradeTooLowException::~GradeTooLowException() _NOEXCEPT
{

}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

std::ostream &operator<<(std::ostream &ostream, const Form &form)
{
    ostream << "Form \"" << form.getName() << "\":\n\t";
    ostream << ((form.isSigned()) ? "Form is signed\n\t"
                                  : "Form is NOT signed\n\t");
    ostream << "Form needs a grade of at least "
            << form.getGradeTresholdSigning() << " to get signed\n\t";
    ostream << "Form needs a grade of at least "
            << form.getGradeTresholdExecute() << " to get executed\n";
    return ostream;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (gradeTresholdSigning < bureaucrat.getGrade())
        throw GradeTooLowException();
    formSigned = true;
}
