/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:39:36 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/13 12:00:20 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << YELLOW << TEXT_BOLD << "Dog    Default Consturctor Called" << RESET << std::endl;
}

Dog::~Dog()
{
    std::cout << TEXT_BOLD << YELLOW << "Dog    Destructor Called" << RESET << std::endl;
}

Dog::Dog(const Dog &other)
{
    std::cout << YELLOW << TEXT_BOLD << "Dog Copy Constructor Called" << RESET << std::endl;
    *this = other;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << TEXT_BOLD << YELLOW << "BARK BARK BARK" << RESET << std::endl;
}