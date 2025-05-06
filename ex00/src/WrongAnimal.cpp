/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:08:38 by svereten          #+#    #+#             */
/*   Updated: 2025/05/06 14:34:00 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(): _type("A certain scientific animal") {
	std::cout << "A wild " << _type << " has appeared!\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal): _type(animal._type) {
	std::cout << "A wild " << _type << " has appeared!\n";
} 

WrongAnimal::~WrongAnimal() {
	std::cout << _type << " has fainted\n";
}

WrongAnimal::WrongAnimal(const std::string &type): _type(type) {
	std::cout << "A wild " << _type << " has appeared!\n";
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &animal) {
	if (this != &animal) {
		_type = animal._type;
	}
	return (*this);
}

std::string	WrongAnimal::getType() const {
	return (_type);
}

void	WrongAnimal::setType(const std::string &type) {
	_type = type;
}

void	WrongAnimal::makeSound() const {
	std::cout << "*Inidentified certain scientific animal noises*\n";
}
