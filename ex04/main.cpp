/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:03:39 by osarikay          #+#    #+#             */
/*   Updated: 2025/01/30 14:54:09 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replace_string(std::string fileName, std::string s1, std::string s2)
{
    std::string line;

    std::ifstream str(fileName.c_str());
    if (!str.is_open())
    {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        return;
    }

    std::ofstream outFile((fileName + ".replace").c_str());
    if (!outFile.is_open())
    {
        std::cerr << "Error: Could not create output file " << fileName << ".replace" << std::endl;
        return;
    }

    while (std::getline(str, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        outFile << line << std::endl;
    }
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Error: Invalid number of arguments!" << std::endl;
        return 1;
    }
    replace_string(av[1], av[2], av[3]);
    return 0;
}