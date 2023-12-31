/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:59:18 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/07 11:35:08 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

// static void	error_msg(std::string str)
// {
// 	std::cout << str << std::endl;
// 	return ;
// }

// int	main(int ac, char **av)
// {
// 	if (ac == 4)
// 	{
// 		std::string infile = av[1];
// 		std::string s1 = av[2];
// 		std::string s2 = av[3];
// 		std::string line;
// 		std::string content;
// 		std::string outfile = std::string(av[1]) + ".replace";
// 		std::ifstream inputFile(av[1]);
// 		if (inputFile.is_open())
// 		{
// 			while (std::getline(inputFile, line))
// 			{
// 				if (!inputFile.eof())
// 					content.append(line + '\n');
// 				else //pas de \n si derniere ligne
// 					content.append(line);
// 			}
// 			inputFile.close();
// 			if (s1.empty() != 1 || s2.empty() != 1)
// 			{
// 				for(std::size_t i = content.find(s1); i != std::string::npos; i = content.find(s1, i + s2.size()))//représente la position invalide ou la valeur de retour spéciale pour les opérations de recherche dans une chaîne (std::string)
// 				content.erase(i, s1.size()).insert(i, s2);
// 			}
// 			std::ofstream outputFile(outfile.c_str(), std::ios::trunc);//.c_str() permet de convertir une string en const char *. trunc pour ouvrir en trunc(efface tt)
// 			if (outputFile.is_open())
// 			{
// 				outputFile << content;
// 				outputFile.close();
// 				std::cout << "Contenu modifié écrit dans le fichier " << outfile << std::endl;
// 			}
// 			else
// 			{
// 				error_msg("Erreur lors de l'ouverture de " + outfile);
// 				return (1);
// 			}
// 		}
// 		else
// 		{
// 			error_msg("Erreur lors 
//		de l'ouverture de " + infile);
// 			return (1);
// 		}
// 	}
// 	else
// 	{
// 		error_msg("Nombre d'arguments incorrects");
// 		return (1);
// 	}
// 	return (0);
// }

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		Sed	sed(av, std::string(av[1]) + ".replace");
		sed.ft_sed(av);
	}
	else
	{
		std::cout << "Nombre d'arguments incorrects" << std::endl;
		return (1);
	}
	return (0);
}
