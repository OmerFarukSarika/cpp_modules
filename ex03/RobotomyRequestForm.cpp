/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay < osarikay@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:18:10 by osarikay          #+#    #+#             */
/*   Updated: 2025/03/16 22:04:42 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target)
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    else if (getSigned())
    {
        print("🔧 BZZZZT! BZZZZT! 🛠️  Drilling noises... 🔩", 255, 165, 0);
        srand(time(NULL));
        if (rand() % 2)
            print("✅ 🤖 Robotomy SUCCESSFUL! Target has been robotomized! 🎉", 0, 255, 0);
        else
            print("❌ 🔧 Robotomy FAILED! Better luck next time... 💔", 255, 0, 0);
    }
    else
        throw AForm::FormIsNotSigned();
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    if (this != &copy)
    {
        this->_target = copy._target;
    }
    return *this;
}