/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:47:10 by osarikay          #+#    #+#             */
/*   Updated: 2025/01/24 00:47:40 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *zombies = zombieHorde(5, "Zombie");
    for (int i = 0; i < 5; i++)
        zombies[i].announce();
    delete [] zombies;
    return 0;
}