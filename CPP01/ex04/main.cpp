/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:59:18 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/17 17:36:11 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    if (ac == 4)
    {
        std::fstream file(av[1]);
        if (file != NULL)
        {
            std::string line;
            while (std::getline(file, line))
                std::cout << line << std::endl;
            file.close();
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