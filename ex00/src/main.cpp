/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:06:08 by svereten          #+#    #+#             */
/*   Updated: 2025/05/06 14:38:43 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* d = new Dog();
	const Animal* c = new Cat();
	std::cout << "\n\n" << std::endl;

	std::cout << "Type of c: " << c->getType() << " " << std::endl;
	std::cout << "Type of d: " << d->getType() << " " << std::endl;
	std::cout << "Type of meta: " << meta->getType() << " " << std::endl;
	std::cout << "What does the c say: ";
	c->makeSound(); //will output the cat sound!
	std::cout << "What does the d say: ";
	d->makeSound();
	std::cout << "What does the meta say: ";
	meta->makeSound();
	std::cout << "\n\n" << std::endl;

	delete meta;
	delete c;
	delete d;
	std::cout << "\n\n" << std::endl;

	const WrongAnimal	*wrongC = new WrongCat();
	std::cout << "\n\n" << std::endl;

	std::cout << "Type of wrongC: " << wrongC->getType() << " " << std::endl;
	std::cout << "What does the wrongC say: ";
	wrongC->makeSound(); //will output the cat sound!
	std::cout << "\n\n" << std::endl;

	delete wrongC;

	return 0;
}
