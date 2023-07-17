/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:45:17 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/17 11:58:35 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int     main(void)
{
        int size = 5;
        Zombie	*z = NULL;
        z = z->zombieHorde(size, "Coco");
        for (int i = 0; i < size; i++)
                z->announce();
        delete [] z;
        
}