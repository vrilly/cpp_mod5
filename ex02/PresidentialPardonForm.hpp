// Created by Tom Jans on 10/24/20.

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP


#include "Form.hpp"

class PresidentialPardonForm : public Form
{
    PresidentialPardonForm();
public:
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &form);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &form);
    virtual ~PresidentialPardonForm();
    void beExecuted(const Bureaucrat &executor) const;
};


#endif //PRESIDENTIALPARDONFORM_HPP
