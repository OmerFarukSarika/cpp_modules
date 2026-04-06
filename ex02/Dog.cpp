/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:39:36 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/13 14:54:53 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    brain = new (Brain);
    type = "Dog";
    std::cout << YELLOW << TEXT_BOLD << "Dog    Default Consturctor Called" << std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << YELLOW << TEXT_BOLD << "Dog    Destructor Called" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
    std::cout << YELLOW << TEXT_BOLD << "Dog Copy Constructor Called" << std::endl;
    this->brain = new Brain(*(other.brain));
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << YELLOW << TEXT_BOLD << "Dog Operator Assigment Called" << std::endl;
    if (this != &other)
    {
        delete brain;
        brain = new Brain(*(other.brain));
        this->type = other.type;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << YELLOW << TEXT_BOLD << "BARK BARK BARK" << std::endl;
}

const std::string Dog::getIdea(int index) const
{
    return (brain->getIdea(index));
}

void Dog::setIdea(int index, const std::string &idea)
{
    brain->setIdea(index, idea);
}