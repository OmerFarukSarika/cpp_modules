/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:05:18 by osarikay          #+#    #+#             */
/*   Updated: 2025/01/24 00:43:45 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie zombie;
    Zombie *zombie2;

    void (Zombie::*func)(void) = &Zombie::announce;
    zombie.setName("Foo");
    (zombie.*func)();
    zombie2 = newZombie("Baz");
    zombie2->announce();
    randomChump("Bar");
    delete zombie2;
    return 0;
}