/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:34:20 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/13 14:42:34 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "Cat";
    std::cout << TEXT_BOLD << PINK << "WrongCat Default Constructor Called" << std::endl;    
}

WrongCat::~WrongCat()
{
    std::cout << TEXT_BOLD << PINK << "WrongCat Destructor Called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
    *this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
        *this = other;
    return *this;   
}

void WrongCat::makeSound() const
{
    std::cout << TEXT_BOLD << PINK << "MEOW MEOW MEOW" << std::endl;
}