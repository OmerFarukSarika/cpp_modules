/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:35:38 by osarikay          #+#    #+#             */
/*   Updated: 2025/01/29 18:07:12 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        Harl harl;
        harl.complain(av[1]);
    }
    else
    {
        std::cout << "Incorrect Parameter. Please Try Again" << std::endl;
        std::cout << "Usage: ./harl [DEBUG|INFO|WARNING|ERROR]" << std::endl;
    }
}