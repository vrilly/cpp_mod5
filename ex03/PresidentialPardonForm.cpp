// Created by Tom Jans on 10/24/20.

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : Form(target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form)
    : Form(form)
{

}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
    (void) form;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void PresidentialPardonForm::beExecuted(const Bureaucrat &executor) const
{
    execute(executor);
    std::cout << getName() << " has been pardoned by Zagod Beeblebrox"
              << std::endl;
}

Form *PresidentialPardonForm::constructor(const std::string &target)
{
    Form *form = new PresidentialPardonForm(target);
    return form;
}
