/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:57:09 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/09 17:14:52 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &copy);
		~MateriaSource(void);

		MateriaSource	&operator=(const MateriaSource &substitue);

		void learnMateria(AMateria* mat);
		AMateria	*createMateria(std::string const& type);
		
	private:
		AMateria *_mat_tab[4];
};


#endif
