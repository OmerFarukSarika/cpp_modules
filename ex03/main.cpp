/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay < osarikay@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:57:55 by osarikay          #+#    #+#             */
/*   Updated: 2025/04/07 21:41:37 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <sstream>

void print(const std::string& text, int r, int g, int b) {
    std::cout << "\033[38;2;" << r << ";" << g << ";" << b << "m" << text << "\033[0m" << std::endl;
}

void printSeparator(const std::string& title) {
    print("════════════════════════════════════════════════════════", 255, 215, 0);
    print("🎯 " + title + " 🎯", 0, 255, 255);
    print("════════════════════════════════════════════════════════", 255, 215, 0);
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
        printSeparator("BUREAUCRAT CREATION TEST");
        
        Bureaucrat highLevel("CEO Boss", 1);
        Bureaucrat midLevel("Manager Smith", 50);
        Bureaucrat lowLevel("Intern Joe", 140);
        
        print("👔 " + highLevel.getName() + " (Grade: " + intToString(highLevel.getGrade()) + ")", 0, 255, 0);
        print("💼 " + midLevel.getName() + " (Grade: " + intToString(midLevel.getGrade()) + ")", 255, 165, 0);
        print("📋 " + lowLevel.getName() + " (Grade: " + intToString(lowLevel.getGrade()) + ")", 255, 255, 0);

        printSeparator("INTERN FORM CREATION TEST");
        
        Intern someRandomIntern;
        print("🤖 Intern is ready to create forms!", 128, 128, 255);

        AForm* robotForm = someRandomIntern.makeForm("robotomy request", "C-3PO");
        AForm* pardonForm = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        AForm* shrubForm = someRandomIntern.makeForm("shrubbery creation", "Garden");

        printSeparator("FORM SIGNING TEST");
        
        print("📝 Attempting to sign robotomy form with mid-level bureaucrat...", 255, 255, 255);
        midLevel.signForm(*robotForm);
        
        print("📝 Attempting to sign pardon form with low-level bureaucrat...", 255, 255, 255);
        lowLevel.signForm(*pardonForm);
        
        print("📝 Attempting to sign pardon form with high-level bureaucrat...", 255, 255, 255);
        highLevel.signForm(*pardonForm);
        
        print("📝 Attempting to sign shrub form with high-level bureaucrat...", 255, 255, 255);
        highLevel.signForm(*shrubForm);

        printSeparator("FORM EXECUTION TEST");
        
        print("⚡ Attempting to execute robotomy form with mid-level bureaucrat...", 255, 255, 255);
        midLevel.executeForm(*robotForm);
        
        print("⚡ Attempting to execute pardon form with low-level bureaucrat...", 255, 255, 255);
        lowLevel.executeForm(*pardonForm);
        
        print("⚡ Attempting to execute shrub form with high-level bureaucrat...", 255, 255, 255);
        highLevel.executeForm(*shrubForm);
        
        print("⚡ Attempting to execute robotomy form with high-level bureaucrat...", 255, 255, 255);
        highLevel.executeForm(*robotForm);
        
        print("⚡ Attempting to execute pardon form with high-level bureaucrat...", 255, 255, 255);
        highLevel.executeForm(*pardonForm);

        printSeparator("ERROR HANDLING TEST");
        
        try {
            print("🚨 Trying to create invalid form...", 255, 0, 0);
            AForm* invalidForm = someRandomIntern.makeForm("invalid form", "target");
            delete invalidForm;
        }
        catch (std::exception &e) {
            print("❌ Expected error: " + std::string(e.what()), 255, 100, 100);
        }

        printSeparator("CLEANUP");
        
        delete robotForm;
        delete pardonForm;
        delete shrubForm;
        
        print("🧹 All forms cleaned up successfully!", 0, 255, 0);
        print("✅ ALL TESTS COMPLETED SUCCESSFULLY!", 0, 255, 0);

    }
    catch (std::exception &e) {
        print("💥 Unexpected exception: " + std::string(e.what()), 255, 0, 0);
    }
    
    return 0;
}