/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:17:51 by svereten          #+#    #+#             */
/*   Updated: 2025/05/07 14:17:35 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Dog.hpp"
#include <iostream>

Dog::Dog(): Animal("Dog") {
	_brain = new Brain();
	std::cout << "btw Dog\n"; 
}

Dog::Dog(const Dog &dog): Animal(dog) {
	_brain = new Brain(*dog._brain);
	std::cout << "btw Dog\n";
}

Dog::~Dog() {
	delete _brain;
	std::cout << "btw Dog\n";
}

Dog	&Dog::operator=(const Dog &dog) {
	if (this != &dog) {
		setType(dog.getType());
		delete _brain;
		_brain = new Brain(*dog._brain);
	}
	return (*this);
}

Brain	*Dog::getBrain() const {
	return (_brain);
}

void	Dog::setBrain(Brain *brain) {
	_brain = brain;
}

void	Dog::makeSound() const {
	std::cout << "Woof\n";
}
