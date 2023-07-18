/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:59:18 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/18 19:25:22 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#include <fstream>

int main(int ac, char **av)
{
    if (ac == 4)
    {
        std::string s1 = av[2];
        std::string s2 = av[3];
        std::fstream file(av[1]);
        if (file.is_open())
        {
            std::string line;
            std::string content;
            while (std::getline(file, line))
                content.append(line + '\n');
            std::size_t i = content.find(s1);
            while (i != std::string::npos)
            {
                content.erase(i, s1.size());
                content.insert(i, s2);
                i = content.find(s1, i + s2.size());
            }
            file.close();

            std::ofstream outputFile("output.replace");  // Nom du fichier de sortie
            if (outputFile.is_open())
            {
                outputFile << content;
                outputFile.close();
                std::cout << "Contenu écrit dans le fichier 'output.txt'" << std::endl;
            }
            else
            {
                std::cout << "Erreur lors de l'ouverture du fichier de sortie" << std::endl;
                return 1;
            }
        }
        else
        {
            std::cout << "Erreur lors de l'ouverture du fichier" << std::endl;
            return 1;
        }
    }
    else
        std::cout << "Nombre d'arguments incorrects" << std::endl;
    return 0;
}
