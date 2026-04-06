/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:39:47 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/13 12:13:51 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << TEXT_BOLD << PINK << "Cat    Default Consturctor Called" << RESET << std::endl;
}

Cat::~Cat()
{
    std::cout << TEXT_BOLD << PINK << "Cat    Destructor Called" << RESET << std::endl;
}

Cat::Cat(const Cat &other)
{
    std::cout << PINK << "Cat Copy Constructor Called" << RESET << std::endl;
    *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << TEXT_BOLD << PINK << "MEOW MEOW MEOW" << RESET << std::endl;
}