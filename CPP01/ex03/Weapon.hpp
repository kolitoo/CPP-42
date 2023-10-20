/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:02:31 by abourdon          #+#    #+#             */
/*   Updated: 2023/10/20 10:58:12 by abourdon         ###   ########.fr       */
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

		std::string const&	getType(void) const;
		void			setType(std::string str);

	private:
		std::string _type;
};

#endif