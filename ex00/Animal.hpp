/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:32:12 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/13 12:21:36 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

# define RESET "\033[0m"
# define TEXT_BOLD "\033[1m"
# define RED "\033[38;2;226;24;24m"
# define PINK "\033[38;2;255;105;180m"
# define YELLOW "\033[38;2;255;255;0m"
# define BG_WHITE "\033[48;2;255;255;255m"
# define BLACK "\033[38;2;0;0;0m"

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
        virtual void makeSound() const;
        
        std::string getType() const;
};

#endif