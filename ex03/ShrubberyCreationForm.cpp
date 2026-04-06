/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay < osarikay@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:18:12 by osarikay          #+#    #+#             */
/*   Updated: 2025/03/16 22:11:01 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
    
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
    
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    if (this != &copy)
    {
        this->_target = copy._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    else if (getSigned())
    {
        std::string filename = _target + "_shrubbery";
        std::ofstream outputFile(filename.c_str(), std::ofstream::trunc);

        if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create the output file." << std::endl;
        throw AForm::GradeTooLowException();
        }

        outputFile << "       _-_" << std::endl;
        outputFile << "    /~~   ~~\\" << std::endl;
        outputFile << " /~~         ~~\\" << std::endl;
        outputFile << "{               }" << std::endl;
        outputFile << " \\  _-     -_  /" << std::endl;
        outputFile << "   ~  \\ //  ~" << std::endl;
        outputFile << "_- -   | | _- _" << std::endl;
        outputFile << "  _ -  | |   -_" << std::endl;
        outputFile << "      // \\\\" << std::endl;

        outputFile.close();
        print("🌳 Shrubbery has been successfully created in " + filename + " 🌿✨", 0, 255, 0);
    }
    else
        throw AForm::FormIsNotSigned();
}