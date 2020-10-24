// Created by Tom Jans on 10/24/20.

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
    ShrubberyCreationForm();
public:
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &form);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &form);
    virtual ~ShrubberyCreationForm();
    void beExecuted(const Bureaucrat &executor) const;
};

#endif //SHRUBBERYCREATIONFORM_HPP