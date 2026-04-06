/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay < osarikay@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:32:40 by osarikay          #+#    #+#             */
/*   Updated: 2025/03/16 21:50:30 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
    print("Bureaucrat Default Constructor Called.", 128, 157, 60);
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
    print("Bureaucrat Parameter Constructor Called.", 128, 157, 60);
    if (grade < 1)
        throw (GradeTooHighException());
    if (grade > 150)
        throw (GradeTooLowException());
    _grade = grade;
}

Bureaucrat::~Bureaucrat()
{
    print("Bureaucrat Destructor Called.", 116, 9, 56);
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name)
{
    *this = copy;
    print("Bureaucrat Copy Constructor Called.", 128, 157, 60);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->_grade = other._grade;
    }
    print("Bureaucrat Assignation Operator Called.", 128, 157, 60);
    return *this;
}

const std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::incrementGrade()
{
    this->_grade--;
    if (_grade == 0)
    {
        _grade = 1;
        throw (GradeTooHighException());
    }
}

void Bureaucrat::decrementGrade()
{
    this->_grade++;
    if (_grade == 151)
    {
        _grade = 150;
        throw (GradeTooLowException());
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << BLUE << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << RESET;
    return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return (RED "Grade is too high" RESET);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return (RED "Grade is too low" RESET);
}

void Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        print("Form " + form.getName() + " signed by " + this->getName(), 128, 157, 60);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception caught: " << e.what() << std::endl << RESET;
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        print("Form " + form.getName() + " executed by " + this->getName(), 128, 157, 60);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception caught: " << e.what() << std::endl << RESET;
    }    
}

void Bureaucrat::print(const std::string& message, int r, int g, int b) 
{
    std::cout << "\033[38;2;" << r << ";" << g << ";" << b << "m" << message 
              << "\033[0m" << std::endl;
}
