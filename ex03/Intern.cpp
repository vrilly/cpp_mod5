// Created by Tom Jans on 10/25/20.

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const Intern::formLookupTableEntry Intern::formLookupTable[3] =
    {{"robotomy request", RobotomyRequestForm::constructor},
     {"shrubbery creation", ShrubberyCreationForm::constructor},
     {"presidential pardon", PresidentialPardonForm::constructor}};

Intern::Intern() {}

Intern::Intern(const Intern &intern)
{
    *this = intern;
}

Intern &Intern::operator=(const Intern &intern)
{
    (void) intern;
    return *this;
}

Intern::~Intern() {}

Form *Intern::makeForm(const std::string &form, const std::string &target) const
{
    for (int i = 0; i < 3; i++)
    {
        if (form == Intern::formLookupTable[i].refName)
        {
            std::cout << "Intern creates " << target << std::endl;
            return Intern::formLookupTable[i].constructor(target);
        }
    }
    std::cout << "Invalid form input! got: " << form;
    return NULL;
}
