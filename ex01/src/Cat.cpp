/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:23:46 by svereten          #+#    #+#             */
/*   Updated: 2025/05/07 13:03:44 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal("Cat") {
	_brain = new Brain();
	std::cout << "Cat btw\n";
}

Cat::Cat(const Cat &cat): Animal(cat) {
	_brain = new Brain(*cat._brain);
	std::cout << "Cat btw\n";
}

Cat::~Cat() {
	delete	_brain;
	std::cout << "Cat btw\n";
}

Cat	&Cat::operator=(const Cat &cat) {
	if (this != &cat) {
		setType(cat.getType());
		delete	_brain;
		_brain = new Brain(*cat._brain);
	}
	return (*this);
}

Brain	*Cat::getBrain() const {
	return (_brain);
}

void	Cat::setBrain(Brain *brain) {
	_brain = brain;
}

void	Cat::makeSound() const {
	std::cout << "Meow\n";
}
