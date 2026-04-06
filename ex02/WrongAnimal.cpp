/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:34:18 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/13 14:49:18 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
    std::cout << TEXT_BOLD << RED << "WrongAnimal Default Consturctor Called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << TEXT_BOLD << RED << "WrongAnimal Destructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    *this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
    {
        type = other.type;
    }
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << TEXT_BOLD << RED << "I am a Animal. I dont have a sound." << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;   
}