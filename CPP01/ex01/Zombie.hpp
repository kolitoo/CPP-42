/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:45:11 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/17 11:58:14 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include <iostream>

class	Zombie
{
	public:
		Zombie(void);
		~Zombie(void);
		
		Zombie	*zombieHorde(int N, std::string name);
		void	announce(void);

	private:
		std::string	_name;
	
};

#endif