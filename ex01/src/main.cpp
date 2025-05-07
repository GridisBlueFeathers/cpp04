/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:06:08 by svereten          #+#    #+#             */
/*   Updated: 2025/05/07 16:42:58 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

static void	shallowCopyCheck(void) {
	std::cout << "\n\n" << std::endl;
	std::cout << "Check for shallow copy:\n";

	const Cat	oneC = Cat();
	oneC.getBrain()->setIdea("Forming a cat thought", 0);
	const Cat	twoC = oneC;
	oneC.getBrain()->setIdea("Still forming", 1);

	std::cout << "This will have something: " << oneC.getBrain()->getIdea(0) << std::endl;
	std::cout << "This will have something: " << twoC.getBrain()->getIdea(0) << std::endl;
	std::cout << "This will have something: " << oneC.getBrain()->getIdea(1) << std::endl;
	std::cout << "This will not :" << twoC.getBrain()->getIdea(1) << std::endl;

	const Dog	oneD = Dog();
	oneD.getBrain()->setIdea("Forming a dog thought", 0);
	const Dog	twoD = oneD;
	oneD.getBrain()->setIdea("Woof, that a lot to process", 1);
	std::cout << "This will have something: " << oneD.getBrain()->getIdea(0) << std::endl;
	std::cout << "This will have something: " << twoD.getBrain()->getIdea(0) << std::endl;
	std::cout << "This will have something: " << oneD.getBrain()->getIdea(1) << std::endl;
	std::cout << "This will not :" << twoD.getBrain()->getIdea(1) << std::endl;
}

int main()
{
	const Animal	*c = new Cat();
	const Animal	*d = new Dog();
	delete c;
	delete d;

	shallowCopyCheck();

	std::cout << "\n\n" << std::endl;
	std::cout << "Generating an array of animals:\n";
	const Animal *arr[10];

	int	i = 0;
	while (i < 10) {
		if (i < 5)
			arr[i] = new Cat();
		else
			arr[i] = new Dog();
		i++;
	}

	std::cout << "\n\n" << std::endl;
	std::cout << "Calling destructors: \n";
	i = 0;
	while (i < 10) {
		delete arr[i];
		i++;
	}
	return 0;
}
