/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:03:18 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/07 11:36:10 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

Sed::Sed(char **av, std::string outfile): _infile(av[1]), _s1(av[2]), _s2(av[3]), _line(std::string()), _content(std::string()), _outfile(outfile)
{
	return ;	
}

Sed::~Sed(void)
{
	return ;
}

void	Sed::ft_sed(char **av)
{
	std::ifstream inputFile(av[1]);
	if (inputFile.is_open())
	{
		while (std::getline(inputFile, _line))
		{
			if (!inputFile.eof())
				_content.append(_line + '\n');
			else //pas de \n si derniere ligne
				_content.append(_line);
		}
		inputFile.close();
		if (_s1.empty() != 1 || _s2.empty() != 1)
		{
			for(std::size_t i = _content.find(_s1); i != std::string::npos; i = _content.find(_s1, i + _s2.size()))//représente la position invalide ou la valeur de retour spéciale pour les opérations de recherche dans une chaîne (std::string)
				_content.erase(i, _s1.size()).insert(i, _s2);
		}
		std::ofstream outputFile(_outfile.c_str(), std::ios::trunc);//.c_str() permet de convertir une string en const char *. trunc pour ouvrir en trunc(efface tt)
		if (outputFile.is_open())
		{
			outputFile << _content;
			outputFile.close();
			std::cout << "Contenu modifié écrit dans le fichier " << _outfile << std::endl;
		}
		else
			std::cout << "Erreur lors de l'ouverture de " + _outfile << std::endl;
	}
	else
	{
		std::cout << "Erreur lors de l'ouverture de " + std::string(av[1]) << std::endl;
		return ;
	}
	return ;
}