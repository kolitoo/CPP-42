/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:32:18 by abourdon          #+#    #+#             */
/*   Updated: 2023/10/20 10:27:45 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie
{
	public:
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
		void	randomChump(std::string name);
		Zombie*	newZombie(std::string name);
	
	private:
		std::string	_name;
	
};

# endif