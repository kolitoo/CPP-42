/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:02:27 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/09 10:20:25 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp" 

int	main()
{
	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();
	const WrongAnimal	*w = new WrongAnimal();
	const WrongAnimal	*wc = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();//will output the cat sound !
	j->makeSound();
	meta->makeSound();
	std::cout << "---------------------------" << std::endl;
	std::cout << wc->getType() << " " << std::endl;
	wc->makeSound();//will output the cat sound !
	w->makeSound();
	delete i;
	delete j;
	delete meta;
	delete w;
	delete wc;
	return (0);
}