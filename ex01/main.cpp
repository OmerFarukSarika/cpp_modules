/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:57:55 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/19 16:57:52 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
    Bureaucrat bureaucrat1("facetint", 9);
    Bureaucrat bureaucrat2("osarikay", 11);
    Form form1("form1", 10, 10);

    std::cout << bureaucrat1 << std::endl;
    std::cout << form1 << std::endl;

    try
    {
        bureaucrat2.signForm(form1);
        bureaucrat1.signForm(form1);
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "Exception caught: " << e.what() << std::endl << RESET;
    }

    std::cout << form1 << std::endl;
    
    return 0;
}