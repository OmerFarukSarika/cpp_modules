/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:59:11 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/19 16:25:26 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _signGrade(150), _execGrade(150)
{
    print("AForm Default Constructor Called.", 70, 53, 177);
}

AForm::~AForm()
{
    print("AForm Destructor Called.", 70, 53, 177);
}

AForm::AForm(const std::string &name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
    print("AForm Parameter Constructor Called.", 70, 53, 177);
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
    *this = copy;
    print("AForm Copy Constructor Called.", 70, 53, 177);
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    print("AForm Assignation Operator Called.", 70, 53, 177);
    return *this;
}

const std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::getSigned() const
{
    return this->_signed;
}

int AForm::getSignGrade() const
{
    return this->_signGrade;
}

int AForm::getExecGrade() const
{
    return this->_execGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_signGrade)
        throw AForm::GradeTooLowException();
    this->_signed = true;
}

void AForm::print(const std::string& message, int r, int g, int b) const
{
    std::cout << "\033[38;2;" << r << ";" << g << ";" << b << "m" << message 
              << "\033[0m" << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return (RED "Grade is too high!" RESET);
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return (RED "Grade is too low!" RESET);
}

const char *AForm::FormIsNotSigned::what() const throw()
{
    return (RED "Form is Not Signed!" RESET);
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
    out << YELLOW << "AForm " << form.getName() << " is " << (form.getSigned() ? "signed" : "not signed") << " and requires grade " << form.getSignGrade() << " to sign and grade " << form.getExecGrade() << " to execute." << RESET;
    return out;
}
