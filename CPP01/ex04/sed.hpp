/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:53:20 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/07 11:31:39 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>

class Sed
{
	public:
		Sed(char **av, std::string outfile);
		~Sed(void);
		
		void	ft_sed(char **av);

	private:
		std::string _infile;
		std::string _s1;
		std::string _s2;
		std::string _line;
		std::string _content;
		std::string _outfile;
};

#endif