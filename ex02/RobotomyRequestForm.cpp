// Created by Tom Jans on 10/24/20.

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : Form(target, 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form)
    : Form(form)
{}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
    (void)form;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::beExecuted(const Bureaucrat &executor) const
{
    execute(executor);
    std::cout << "* Drilling noises *" << std::endl;
    if (time(NULL) % 2) // literally HALF of the time :)
        std::cout << getName() << " has been robotomized successfully!" << std::endl;
    else
        throw FailedExecutionException();
}

const char *RobotomyRequestForm::FailedExecutionException::what() const throw()
{
    return "Robotomization failed!";
}

RobotomyRequestForm::FailedExecutionException::FailedExecutionException() {}

RobotomyRequestForm::FailedExecutionException::FailedExecutionException(const RobotomyRequestForm::FailedExecutionException &exception)
{
    *this = exception;
}

RobotomyRequestForm::FailedExecutionException &
RobotomyRequestForm::FailedExecutionException::operator=(const RobotomyRequestForm::FailedExecutionException &exception)
{
    (void)exception;
    return *this;
}

RobotomyRequestForm::FailedExecutionException::~FailedExecutionException()
_NOEXCEPT {}
