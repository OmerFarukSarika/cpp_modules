/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:50:32 by osarikay          #+#    #+#             */
/*   Updated: 2025/01/30 13:27:07 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    str = "ÖMER";
    std::cout << "Address in memory of the string     : " << &str << std::endl;
    std::cout << "Address in memory of the stringPTR  : " << stringPTR << std::endl;
    std::cout << "Address in memory of the stringREF  : " << &stringREF << std::endl;
    std::cout << "StringPTR  : " << *stringPTR << std::endl;
    std::cout << "StringREF  : " << stringREF << std::endl;
    std::cout << "String     : " << str << std::endl;
    
    return 0;
}