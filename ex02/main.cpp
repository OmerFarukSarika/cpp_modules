/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay < osarikay@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:57:55 by osarikay          #+#    #+#             */
/*   Updated: 2025/03/16 22:09:42 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <sstream>

void print(const std::string& text, int r, int g, int b) {
    std::cout << "\033[38;2;" << r << ";" << g << ";" << b << "m" << text << "\033[0m" << std::endl;
}

void printWithSpace(const std::string& text, int r, int g, int b) {
    std::cout << "\033[38;2;" << r << ";" << g << ";" << b << "m" << text << "\033[0m" << std::endl << std::endl;
}

void printSeparator(const std::string& title) {
    print("════════════════════════════════════════════════════════", 255, 215, 0);
    print("🎯 " + title + " 🎯", 0, 255, 255);
    printWithSpace("════════════════════════════════════════════════════════", 255, 215, 0);
}

std::string intToString(int value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

int main()
{
    try
    {
        printSeparator("BUREAUCRAT CREATION");
        
        Bureaucrat Boss("Boss", 1);
        Bureaucrat Engineer("Engineer", 50);
        Bureaucrat Intern("Intern", 140);
        
        print("👔 " + Boss.getName() + " (Grade: " + intToString(Boss.getGrade()) + ")", 0, 255, 0);
        print("🔧 " + Engineer.getName() + " (Grade: " + intToString(Engineer.getGrade()) + ")", 255, 165, 0);
        printWithSpace("📋 " + Intern.getName() + " (Grade: " + intToString(Intern.getGrade()) + ")", 255, 255, 0);

        printSeparator("SHRUBBERY CREATION FORM TEST");
        
        ShrubberyCreationForm createForm("Garden");
        printWithSpace("🌳 Shrubbery form created for target: Garden", 0, 255, 128);
        
        print("📝 Boss attempting to sign shrubbery form...", 255, 255, 255);
        Boss.signForm(createForm);
        
        print("⚡ Boss attempting to execute shrubbery form...", 255, 255, 255);
        Boss.executeForm(createForm);
        std::cout << std::endl;

        printSeparator("ROBOTOMY REQUEST FORM TEST");
        
        RobotomyRequestForm robotomyForm("C-3PO");
        printWithSpace("🤖 Robotomy form created for target: C-3PO", 128, 128, 255);

        print("📝 ROBOTOMY SIGN TEST", 255, 215, 0);
        print("📝 Engineer attempting to sign robotomy form...", 255, 255, 255);
        Engineer.signForm(robotomyForm);
        std::cout << std::endl;

        print("⚡ ROBOTOMY EXEC TEST", 255, 215, 0);
        print("⚡ Boss attempting to execute robotomy form...", 255, 255, 255);
        Boss.executeForm(robotomyForm);
        
        print("⚡ Engineer attempting to execute robotomy form...", 255, 255, 255);
        Engineer.executeForm(robotomyForm);
        
        print("⚡ Intern attempting to execute robotomy form...", 255, 255, 255);
        Intern.executeForm(robotomyForm);
        std::cout << std::endl;

        printSeparator("PRESIDENTIAL PARDON FORM TEST");
        
        PresidentialPardonForm pardonForm("Arthur Dent");
        printWithSpace("🏛️ Presidential pardon form created for target: Arthur Dent", 255, 0, 255);

        print("📝 PARDON SIGN TEST", 255, 215, 0);
        print("📝 Boss attempting to sign pardon form...", 255, 255, 255);
        Boss.signForm(pardonForm);
        
        print("📝 Engineer attempting to sign pardon form...", 255, 255, 255);
        Engineer.signForm(pardonForm);
        
        print("📝 Intern attempting to sign pardon form...", 255, 255, 255);
        Intern.signForm(pardonForm);
        std::cout << std::endl;

        print("⚡ PARDON EXEC TEST", 255, 215, 0);
        print("⚡ Boss attempting to execute pardon form...", 255, 255, 255);
        Boss.executeForm(pardonForm);
        
        print("⚡ Engineer attempting to execute pardon form...", 255, 255, 255);
        Engineer.executeForm(pardonForm);
        
        print("⚡ Intern attempting to execute pardon form...", 255, 255, 255);
        Intern.executeForm(pardonForm);
        std::cout << std::endl;

        printSeparator("TEST COMPLETED");
        printWithSpace("✅ All tests finished successfully!", 0, 255, 0);
    }
    catch (std::exception &e) {
        printWithSpace("💥 Exception caught: " + std::string(e.what()), 255, 0, 0);
    }
    
    return 0;
}