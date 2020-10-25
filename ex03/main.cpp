// Created by Tom Jans on 10/22/20.

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

void tryCreateBureaucrat(const std::string &name, int grade)
{
    try
    {
        Bureaucrat bureaucrat(name, grade);
        std::cout << bureaucrat;
    }
    catch (std::exception &e)
    {
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }
}

void trySignExecuteForm(Bureaucrat *bureaucrat, Form *form)
{
    std::cout << "Try & Execute form\n---" << std::endl;
    std::cout << *bureaucrat << *form;
    bureaucrat->signForm(form);
    std::cout << *form;
    if (form->isSigned())
        bureaucrat->executeForm(*form);
    std::cout << std::endl;
    delete bureaucrat;
    delete form;
}

void testBureaucrats()
{

    tryCreateBureaucrat("The good one", 1);
    tryCreateBureaucrat("The best one", -50);
    tryCreateBureaucrat("The worst one", 160);

    Bureaucrat a("Original", 150);
    Bureaucrat b(a);
    Bureaucrat c("Never to be seen", 2);
    try
    {
        c.incGrade();
        c.incGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }
    c = b;
    std::cout << c;
    try
    {
        c.decGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }
}

int main()
{
    testBureaucrats(); // Tests from ex00
    PresidentialPardonForm templPardon("Pardonno");
    Bureaucrat gardener("The gardener", 45);
    trySignExecuteForm(new Bureaucrat("Bob", 145),
                       new ShrubberyCreationForm("garden"));
    trySignExecuteForm(new Bureaucrat("Bob", 130),
                       new ShrubberyCreationForm("garden"));
    trySignExecuteForm(new Bureaucrat("Doc Vi", 10),
                       new PresidentialPardonForm(templPardon));
    trySignExecuteForm(new Bureaucrat("The President", 1),
                       new PresidentialPardonForm(templPardon));
    trySignExecuteForm(new Bureaucrat(gardener),
                       new RobotomyRequestForm("robotomytarget"));
    gardener.executeForm(templPardon);

    Intern shittyIntern;
    Form *form;

    form = shittyIntern.makeForm("shrubbery creation", "white house");
    gardener.signForm(form);
    gardener.executeForm(*form);
    return 0;
}