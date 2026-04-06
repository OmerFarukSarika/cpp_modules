/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:55:48 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/13 14:47:37 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << TEXT_BOLD << GREEN << "Brain Default Constructor Called" << std::endl;
}

Brain::~Brain()
{
    std::cout << TEXT_BOLD << GREEN << "Brain Destructor Called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << TEXT_BOLD << GREEN << "Brain Copy Constructor Called" << std::endl;
    *this = other;
}

Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        for(int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    std::cout << TEXT_BOLD << GREEN << "Brain Copy Assigment Operator Called" << std::endl;
    return *this;
}

const std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
    {
        return ideas[index];
    }
    return "";
}

void Brain::setIdea(int index, const std::string &idea)
{
    if (index >= 0 && index < 100)
    {
        ideas[index] = idea;
    }
}