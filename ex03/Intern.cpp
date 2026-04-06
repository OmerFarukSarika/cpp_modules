/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay < osarikay@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 00:05:49 by osarikay          #+#    #+#             */
/*   Updated: 2025/03/17 00:16:26 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

Intern::Intern()
{
    
}

Intern::~Intern()
{

}

Intern::Intern(const Intern &copy)
{
    *this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
    (void)copy;
    return *this;
}

static AForm* makeShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* makePardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

static AForm* makeRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
    static const std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    typedef AForm* (*Maker)(const std::string&);
    static const Maker makeForms[] = {
        makeShrubbery,
        makeRobotomy,
        makePardon
    };

    for (size_t i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << GREEN << "Intern creates form : " << RED << formName << RESET << std::endl;
            return makeForms[i](target);
        }
    }
    throw InvalidForm();
}
const char *Intern::InvalidForm::what() const throw()
{
    return ("Form Not Found!");
}

