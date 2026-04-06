/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:25:39 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/13 14:55:25 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
    std::cout << TEXT_BOLD << RED << "Animal Default Consturctor Called" << std::endl;
}

Animal::~Animal()
{
    std::cout << TEXT_BOLD << RED << "Animal Destructor Called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << TEXT_BOLD << RED << "Animal Copy Constructor Called" << std::endl;
    *this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << TEXT_BOLD << RED << "Animal Operator Assigment Called." << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

void Animal::makeSound() const 
{
    std::cout << TEXT_BOLD << RED << "I am a Animal. I dont have a sound." << std::endl;
}

std::string Animal::getType() const
{
	return type;
}
