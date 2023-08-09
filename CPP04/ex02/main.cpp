/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:02:27 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/09 11:54:11 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp" 

int	main()
{
	AAnimal*	tab[100];
	//AAnimal	*a = new AAnimal();//Error car class AAnimal abstract

	for(int i = 0; i < 50; i++)
		tab[i] = new Dog();
	for(int i = 50; i < 100; i++)
		tab[i] = new Cat();
	for(int i = 0; i < 100; i++)
		tab[i]->makeSound();
	for(int i = 0; i < 100; i++)
		delete tab[i];
	a->makeSound();
	return (0);
}
