/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:02:21 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/17 16:57:40 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string str);
        ~HumanB(void);

        void    attack(void);
        void    setWeapon(Weapon &weaponB);
        
    private:
        Weapon *_weaponB;
        std::string _name;
        
};

#endif