// Created by Tom Jans on 10/24/20.

#include "ShrubberyCreationForm.hpp"
#include "asciitree.hpp" // Generated file!

void ShrubberyCreationForm::beExecuted(const Bureaucrat &executor) const
{
    execute(executor);
    try
    {
        std::ofstream fos(getName(), std::ofstream::out | std::ofstream::trunc);
        if (!fos.good())
        {
            fos.close();
            throw std::exception();
        }
        fos.write((const char *) asciitree_txt, asciitree_txt_len);
        fos.close();
    }
    catch (std::exception &e)
    {
        std::cout << "I/O Error! " << e.what() << std::endl;
    }
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : Form(target + "_shrubbery", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form)
    : Form(form)
{
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form)
{
    (void)form;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}
