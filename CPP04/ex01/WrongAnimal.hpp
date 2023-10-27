/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:09:18 by abourdon          #+#    #+#             */
/*   Updated: 2023/10/26 18:19:13 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &copy);
		virtual ~WrongAnimal(void);

		WrongAnimal	&operator=(const WrongAnimal &substitue);
		void	makeSound() const;
		std::string	getType() const;
		
	protected:
		std::string	_type;
};

#endif