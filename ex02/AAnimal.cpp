/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:25:39 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/11 19:39:08 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	type = "AAnimal";
    std::cout << TEXT_BOLD << RED << "AAnimal Default Consturctor Called" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << TEXT_BOLD << RED << "AAnimal Destructor Called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
    std::cout << TEXT_BOLD << RED << "AAnimal Copy Constructor Called" << std::endl;
    *this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << TEXT_BOLD << RED << "Assignation operator called - (AAnimal)" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

std::string AAnimal::getType() const
{
	return type;
}