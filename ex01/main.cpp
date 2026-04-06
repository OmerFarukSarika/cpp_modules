/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:20:00 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/13 15:01:03 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "\n=== TEST 1: Deep Copy via Assignment Operator ===" << std::endl << std::endl;
    {
        Dog dog1;
        dog1.setIdea(0, "I want to play fetch!");

        Dog dog2;
        std::cout << std::endl;
        dog2 = dog1;
        std::cout << std::endl;
        std::cout << "dog1 Idea[0]: " << dog1.getIdea(0) << std::endl;
        std::cout << "dog2 Idea[0]: " << dog2.getIdea(0) << std::endl;

        dog2.setIdea(0, "I want to dig a hole!");
        std::cout << std::endl << "After modifying dog2:" << std::endl;
        std::cout << "dog1 Idea[0]: " << dog1.getIdea(0) << std::endl;
        std::cout << "dog2 Idea[0]: " << dog2.getIdea(0) << std::endl << std::endl;
    }
    std::cout << "\n=== TEST 2: Polymorphism and Virtual Destructor ===" << std::endl << std::endl;
    {
        const int ARRAY_SIZE = 4;
        Animal* animals[ARRAY_SIZE];

        for (int i = 0; i < ARRAY_SIZE / 2; ++i)
        {
            animals[i] = new Dog();
        }
        std::cout << std::endl;
        for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; ++i)
        {
            animals[i] = new Cat();
        }
        std::cout << std::endl;
        for (int i = 0; i < ARRAY_SIZE; ++i)
        {
            animals[i]->makeSound();
        }
        std::cout << std::endl;
        for (int i = 0; i < ARRAY_SIZE; ++i)
        {
            delete animals[i];
        }
    }
    return (0);
}
