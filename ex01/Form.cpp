/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:59:11 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/19 16:25:26 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _signGrade(150), _execGrade(150)
{
    print("Form Default Constructor Called.", 70, 53, 177);
}

Form::~Form()
{
    print("Form Destructor Called.", 70, 53, 177);
}

Form::Form(const std::string &name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
    print("Form Parameter Constructor Called.", 70, 53, 177);
    if (signGrade < 1 || execGrade < 1)
        throw Form::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
    *this = copy;
    print("Form Copy Constructor Called.", 70, 53, 177);
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    print("Form Assignation Operator Called.", 70, 53, 177);
    return *this;
}

const std::string Form::getName() const
{
    return this->_name;
}

bool Form::getSigned() const
{
    return this->_signed;
}

int Form::getSignGrade() const
{
    return this->_signGrade;
}

int Form::getExecGrade() const
{
    return this->_execGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_signGrade)
        throw Form::GradeTooLowException();
    this->_signed = true;
}

void Form::print(const std::string& message, int r, int g, int b) 
{
    std::cout << "\033[38;2;" << r << ";" << g << ";" << b << "m" << message 
              << "\033[0m" << std::endl;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return (RED "Grade is too high!" RESET);
}

const char *Form::GradeTooLowException::what() const throw()
{
    return (RED "Grade is too low!" RESET);
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << YELLOW << "Form " << form.getName() << " is " << (form.getSigned() ? "signed" : "not signed") << " and requires grade " << form.getSignGrade() << " to sign and grade " << form.getExecGrade() << " to execute." << RESET;
    return out;
}
