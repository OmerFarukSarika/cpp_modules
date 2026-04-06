/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:20:00 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/13 12:30:48 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << std::endl << BLACK << BG_WHITE << meta->getType() << RESET << " " << std::endl;
        std::cout << BLACK << BG_WHITE << " " << j->getType() << "  " << RESET << std::endl;
        std::cout << BLACK << BG_WHITE << " " << i->getType() << "  " << RESET << std::endl << std::endl;
        i->makeSound();
        j->makeSound();
        meta->makeSound();
        std::cout << std::endl;
        delete meta;
        delete j;
        delete i;
    }
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();
        std::cout << meta->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        meta->makeSound();
        delete meta;
        delete i;
    }
    return 0;
}