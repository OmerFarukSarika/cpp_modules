/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:09:10 by osarikay          #+#    #+#             */
/*   Updated: 2025/01/23 15:50:55 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <unistd.h>

int main()
{
    PhoneBook phoneBook;
    Contact contact;

    phoneBook.clearConsole();
    while (true)
    {
        std::cout << "\033[1;32mWelcome to the phonebook!" << std::endl;
        std::cout << "Please enter commands: ADD, SEARCH or EXIT\033[0m" << std::endl;
        if (std::cin.eof())
            break;
        std::string command;
        std::cin.clear();
        command = phoneBook.GetInput();
        if (command == "")
            break;
        if (command == "ADD")
        {
            phoneBook.addContact();
        }
        else if (command == "SEARCH")
        {
            phoneBook.searchContact();
        }
        else if (command == "EXIT")
        {
            std::cout << "Exiting the phonebook..." << std::endl;
            break;
        }
        else
        {
            phoneBook.clearConsole();
            std::cout << "\033[1;31mInvalid command. Please enter ADD, SEARCH or EXIT\033[0m" << std::endl;
            usleep(1000000);
            phoneBook.clearConsole();
        }
    }
    return 0;
}