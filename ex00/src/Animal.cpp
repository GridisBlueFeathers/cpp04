/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:08:38 by svereten          #+#    #+#             */
/*   Updated: 2025/05/06 13:33:22 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Animal.hpp"
#include <iostream>

Animal::Animal(): _type("A certain scientific animal") {
	std::cout << "A wild " << _type << " has appeared!\n";
}

Animal::Animal(const Animal &animal): _type(animal._type) {
	std::cout << "A wild " << _type << " has appeared!\n";
} 

Animal::~Animal() {
	std::cout << _type << " has fainted\n";
}

Animal::Animal(const std::string &type): _type(type) {
	std::cout << "A wild " << _type << " has appeared!\n";
}

Animal	&Animal::operator=(const Animal &animal) {
	if (this != &animal) {
		_type = animal._type;
	}
	return (*this);
}

std::string	Animal::getType() const {
	return (_type);
}

void	Animal::setType(const std::string &type) {
	_type = type;
}

void	Animal::makeSound() const {
	std::cout << "*Inidentified certain scientific animal noises*\n";
}
