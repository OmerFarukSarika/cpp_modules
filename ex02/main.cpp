/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:20:00 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/13 14:57:56 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        Dog dog1;
        Cat cat1;

        std::cout << std::endl;
        dog1.makeSound();
        cat1.makeSound();
        dog1.setIdea(0, "Chase the ball");
        std::cout << std::endl;
        cat1.setIdea(0, "Sleep on the couch");
        std::cout << "Dog's idea: " << dog1.getIdea(0) << std::endl;
        std::cout << "Cat's idea: " << cat1.getIdea(0) << std::endl;
        std::cout << TEXT_BOLD << GREEN << "\n--- Assignment Operator Test ---" << RESET << std::endl << std::endl;
        
        Dog dog3;
        Cat cat3;

        std::cout << std::endl;
        dog3 = dog1;
        std::cout << std::endl;
        cat3 = cat1;

        std::cout << std::endl << "Dog3's idea (assigned): " << dog3.getIdea(0) << std::endl;
        std::cout << "Cat3's idea (assigned): " << cat3.getIdea(0) << std::endl << std::endl;
    }

    std::cout << TEXT_BOLD << GREEN << "\n--- Polymorphism Test (AAnimal pointers) ---" << RESET << std::endl << std::endl;
    {
        AAnimal *animals[2];
        animals[0] = new Dog();
        animals[1] = new Cat();

        for (int i = 0; i < 2; ++i)
        {
            std::cout << std::endl;
            animals[i]->makeSound();
            std::cout << std::endl;
            delete animals[i];
        }
    }

    return 0;
}