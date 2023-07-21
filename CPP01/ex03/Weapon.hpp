/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:02:31 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/20 11:40:47 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class	Weapon
{
	public:
		Weapon(std::string str);
		~Weapon(void);

		std::string const	&getType(void);
		void				setType(std::string str);

	private:
		std::string _type;
};

#endif