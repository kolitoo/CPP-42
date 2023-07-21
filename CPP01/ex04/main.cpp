/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:59:18 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/20 11:58:38 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>

static void	error_msg(std::string str)
{
	std::cout << str << std::endl;
	exit (1);
}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string infile = av[1];
		std::string s1 = av[2];
		std::string s2 = av[3];
		std::string line;
		std::string content;
		std::string outfile = std::string(av[1]) + ".replace";
		std::ifstream inputFile(av[1]);
		if (inputFile.is_open())
		{
			while (std::getline(inputFile, line))
			{
				if (!inputFile.eof())
					content.append(line + '\n');
				else //pas de \n si derniere ligne
					content.append(line);
			}
			inputFile.close();
			for(std::size_t i = content.find(s1); i != std::string::npos; i = content.find(s1, i + s2.size()))//représente la position invalide ou la valeur de retour spéciale pour les opérations de recherche dans une chaîne (std::string)
				content.erase(i, s1.size()).insert(i, s2);
			std::ofstream outputFile(outfile.c_str(), std::ios::trunc);//.c_str() permet de convertir une string en const char *. trunc pour ouvrir en trunc(efface tt)
			if (outputFile.is_open())
			{
				outputFile << content;
				outputFile.close();
				std::cout << "Contenu modifié écrit dans le fichier " << outfile << std::endl;
			}
			else
				error_msg("Erreur lors de l'ouverture de " + outfile);
		}
		else
		error_msg("Erreur lors de l'ouverture de " + infile);
	}
	else
		error_msg("Nombre d'arguments incorrects");
	return (0);
}

