/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:02:27 by abourdon          #+#    #+#             */
/*   Updated: 2023/10/26 15:20:39 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp" 

int	main()
{
	int	j = 20;
	AAnimal*	tab[j];
	//AAnimal	*a = new AAnimal();//Error car class AAnimal abstract

	for(int i = 0; i < j / 2; i++)
		tab[i] = new Dog();
	for(int i = j / 2; i < j; i++)
		tab[i] = new Cat();
	for(int i = 0; i < j; i++)
		tab[i]->makeSound();
	for(int i = 0; i < j; i++)
		delete tab[i];
	//a->makeSound();
	return (0);
}
