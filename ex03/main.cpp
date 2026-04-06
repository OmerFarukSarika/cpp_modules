/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay < osarikay@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:48:40 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/09 17:28:39 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	{
		DiamondTrap diamond("Ömer");
		diamond.displayStats();
		diamond.attack("enemy");
		std::cout << std::endl;
		diamond.takeDamage(40);
		std::cout << std::endl;
		diamond.beRepaired(20);
		std::cout << std::endl;
		diamond.guardGate();
		std::cout << std::endl;
		diamond.highFivesGuys();
		std::cout << std::endl;
		diamond.whoAmI();
		std::cout << std::endl;
	}
	{
		std::cout << std::endl << "---------------------" << std::endl << std::endl;
		ClapTrap clap("Clap");
		clap.displayStats();
		clap.attack("enemy");
		std::cout << std::endl;
		clap.takeDamage(7);
		std::cout << std::endl;
		clap.beRepaired(20);
		std::cout << std::endl;
	}
	return (0);
}