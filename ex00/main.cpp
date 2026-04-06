/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:57:55 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/19 15:57:29 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int		main()
{
	std::cout << "-------------------- How it Works ? -------------------" << std::endl;
	std::cout << RED << "@.@ \tBureaucrat \t@.@" << RESET << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl << std::endl;
	try
	{
		Bureaucrat b1("B1", 1);
		std::cout << b1 << std::endl;
		b1.decrementGrade();
		std::cout << b1 << std::endl;
		b1.decrementGrade();
		std::cout << b1 << std::endl;
		
		Bureaucrat b2("B2", 150);
		std::cout << b2 << std::endl;
		b2.incrementGrade();
		std::cout << b2 << std::endl;
		b2.decrementGrade();
		std::cout << b2 << std::endl;
		
		Bureaucrat b3;
		b3 = b1;
		std::cout << b3 << std::endl;
		b3.incrementGrade();
		std::cout << b3 << std::endl;
		b3.decrementGrade();
		std::cout << b3 << std::endl;
		b3.decrementGrade();
		std::cout << b3 << std::endl;

		Bureaucrat b4(b2);
		std::cout << b4 << std::endl;
		b4.incrementGrade();
		std::cout << b4 << std::endl;
		b4.decrementGrade();
		std::cout << b4 << std::endl;
        b4.decrementGrade();
		std::cout << b4 << std::endl;
    }
	catch (std::exception &e)
	{
		std::cerr << RED << "GradeTooLowException caught: " << e.what() << std::endl;
	}
	return (0);
}