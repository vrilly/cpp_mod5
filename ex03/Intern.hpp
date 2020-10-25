// Created by Tom Jans on 10/25/20.

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"

class Intern
{
    struct formLookupTableEntry
    {
        std::string refName;
        Form *(*constructor)(const std::string &target);
    };

    static const formLookupTableEntry formLookupTable[3];
public:
    Intern();
    Intern(const Intern &intern);
    Intern &operator=(const Intern &intern);
    ~Intern();

    Form *makeForm(const std::string &form, const std::string &target) const;
};

#endif //INTERN_HPP
