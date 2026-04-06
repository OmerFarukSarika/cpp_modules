/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:09:24 by osarikay          #+#    #+#             */
/*   Updated: 2025/01/23 15:51:06 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <unistd.h>
#include <iomanip>
#include <cstdlib>

void PhoneBook::clearConsole() {
    std::cout << "\033[2J\033[1;1H";
}

std::string PhoneBook::GetInput() {
    std::string input;

    while (true)
    {
        std::getline(std::cin, input);
        if (!input.empty())
            return input;
        else if (std::cin.eof())
            return ("");
        else
            std::cout << "\033[1;31mInput empty. Please enter a valid input: " << "\033[0m";
    }
    return input;
}

void printShortened(const std::string& input) {

    if (input.length() == 0) {
        std::cout << std::setw(11);
    }
    else if (input.length() > 9) {
        for (int i = 0; i < 9; ++i) {
            std::cout << input[i];
        }
        std::cout << ".";
    } 
    else {
        std::cout << std::setw(10);
        std::cout << input;
    }
}

void PhoneBook::addContact() {
    Contact contact;
    static int i = 0;

    index = i;
    if (index == 8) {
        index = 0;
        i = 0;
    }
    this->clearConsole();
    std::cout << "\033[1;36mAdding a new contact." << std::endl;
    usleep(280000);
    this->clearConsole();
    std::cout << "Adding a new contact.." << std::endl;
    usleep(280000);
    this->clearConsole();
    std::cout << "Adding a new contact...\033[0m" << std::endl;
    usleep(280000);
    this->clearConsole();
    std::cout << "\033[1;37mEnter your first name: ";
    std::string name;
    name = GetInput();
    if (name == "")
        return;
    contact.setFirstName(name);
    std::cout << "Enter your last name: ";
    std::string lastName;
    lastName = GetInput();
    if (lastName == "")
        return;
    contact.setLastName(lastName);
    std::cout << "Enter your nickname: ";
    std::string nickname;
    nickname = GetInput();
    if (nickname == "")
        return;
    contact.setNickname(nickname);
    std::cout << "Enter your phone number: ";
    std::string phoneNumber;
    phoneNumber = GetInput();
    if (phoneNumber == "")
        return;
    contact.setPhoneNumber(phoneNumber);
    std::cout << "Enter your darkest secret: ";
    std::string darkestSecret;
    darkestSecret = GetInput();
    if (darkestSecret == "")
        return;
    contact.setDarkestSecret(darkestSecret);
    std::cout << "\033[0m";
    contacts[index] = contact;
    i++;
}

void PhoneBook::searchContact(){
        std::cout << "Searching for a contact..." << std::endl;
        this->clearConsole();
        std::cout << "     index|first name| last name|  nickname" << std::endl;
        for (int i = 0; i < 8; i++)
        {
            if (this->contacts[i].getFirstName().length() == 0)
                continue;
            std::cout << "----------|----------|----------|-----------" << std::endl;
            std::cout << std::setw(10);
            std::cout << i + 1 << "|";
            printShortened(this->contacts[i].getFirstName());
            std::cout << "|";
            printShortened(this->contacts[i].getLastName());
            std::cout << "|";
            printShortened(this->contacts[i].getNickname());
            std::cout << std::endl;
        }
            std::cout << "----------|----------|----------|-----------" << std::endl;
            std::string input;
            std::cout << "Enter the index of the contact you want to see: ";
            input = GetInput();
            if (input == "")
                return;
            if (input.length() == 1 && isdigit(input[0]))
            {
                int index = input[0] - '0';
                if (index > 0 && index < 9 && this->contacts[index - 1].getFirstName().length() != 0)
                {
                    this->clearConsole();
                    std::cout << "First name: " << this->contacts[index - 1].getFirstName() << std::endl;
                    std::cout << "Last name: " << this->contacts[index - 1].getLastName() << std::endl;
                    std::cout << "Nickname: " << this->contacts[index - 1].getNickname() << std::endl;
                    std::cout << "Phone number: " << this->contacts[index - 1].getPhoneNumber() << std::endl;
                    std::cout << "Darkest secret: " << this->contacts[index - 1].getDarkestSecret() << std::endl;
                }
                else if (index > 0 && index < 9 && this->contacts[index - 1].getFirstName().length() == 0)
                {
                    this->clearConsole();
                    std::cout << "\033[1;31mThis contact is empty\033[0m" << std::endl;
                    usleep(1000000);
                }
            }
            else
            {
                this->clearConsole();
                std::cout << "\033[1;31mInvalid input. Please enter a number between 1 and 8.\033[0m" << std::endl;
                usleep(1000000);
            }
}