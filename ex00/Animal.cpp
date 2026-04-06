/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:25:39 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/13 12:15:16 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
    std::cout << TEXT_BOLD << RED << "Animal Default Consturctor Called" << RESET << std::endl;
}

Animal::~Animal()
{
    std::cout << TEXT_BOLD << RED << "Animal Destructor Called" << RESET << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << RED << "Animal Copy Constructor Called" << RESET << std::endl;
    *this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "Assignation operator called - (Animal)" << std::endl;
	return (*this);
}

void Animal::makeSound() const 
{
    std::cout << TEXT_BOLD << RED << "I am a Animal. I dont have a sound." << RESET << std::endl;
}

std::string Animal::getType() const
{
	return type;
}
