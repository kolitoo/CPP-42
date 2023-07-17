/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:32:18 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/17 11:42:40 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class	Zombie
{
	public:
		Zombie(std::string name);
		~Zombie(void);
		
		Zombie	*newZombie(std::string name);
		void	randomChump(std::string name);
		void	announce(void);

	private:
		std::string	_name;
	
};

# endif