/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:39:47 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/13 14:55:11 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << TEXT_BOLD << PINK << "Cat    Default Consturctor Called" << std::endl;
    brain = new (Brain);
}

Cat::~Cat()
{
    delete brain;
    std::cout << TEXT_BOLD << PINK << "Cat    Destructor Called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << TEXT_BOLD << PINK << "Cat Copy Constructor Called" << std::endl;
    this->brain = new Brain(*(other.brain));
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << TEXT_BOLD << PINK << "Cat Operator Assigment Called" << std::endl;
    if (this != &other)
    {
        delete brain;
        brain = new Brain(*(other.brain));
        this->type = other.type;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << TEXT_BOLD << PINK << "MEOW MEOW MEOW" << std::endl;
}

const std::string Cat::getIdea(int index) const
{
    return (brain->getIdea(index));
}

void Cat::setIdea(int index, const std::string &idea)
{
    brain->setIdea(index, idea);
}