// Created by Tom Jans on 10/22/20.

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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

    Bureaucrat barry("Barry", 135);
    Bureaucrat henk("Henk", 5);

    Form complaint("Complaint", 50, 25);
    std::cout << complaint;
    barry.signForm(&complaint);
    henk.signForm(&complaint);
    std::cout << complaint;
    Form copy = Form(complaint);
    std::cout << copy;

    try {
        Form invalid("Invalid", 0, -5);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}