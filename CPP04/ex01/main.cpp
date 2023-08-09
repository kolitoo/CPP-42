/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:02:27 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/09 11:12:17 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp" 

int	main()
{
	Animal*	tab[100];

	for(int i = 0; i < 50; i++)
		tab[i] = new Dog();
	for(int i = 50; i < 100; i++)
		tab[i] = new Cat();
	for(int i = 0; i < 100; i++)
		tab[i]->makeSound();
	for(int i = 0; i < 100; i++)
		delete tab[i];
	return (0);
}
