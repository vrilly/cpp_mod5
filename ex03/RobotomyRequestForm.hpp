// Created by Tom Jans on 10/24/20.

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <ctime>
#include "Form.hpp"

class RobotomyRequestForm: public Form
{
    RobotomyRequestForm();
public:
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &form);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &form);
    virtual ~RobotomyRequestForm();
    void beExecuted(const Bureaucrat &executor) const;
    static Form *constructor(const std::string &target);

    class FailedExecutionException: public std::exception
    {
    public:
        FailedExecutionException();
        FailedExecutionException(const FailedExecutionException &exception);
        FailedExecutionException &
        operator=(const FailedExecutionException &exception);
        virtual ~FailedExecutionException() _NOEXCEPT;
        virtual const char *what() const _NOEXCEPT;
    };
};


#endif //ROBOTOMYREQUESTFORM_HPP
