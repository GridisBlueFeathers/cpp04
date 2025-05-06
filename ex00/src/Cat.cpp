/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:23:46 by svereten          #+#    #+#             */
/*   Updated: 2025/05/06 13:37:47 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal("Cat") {
	std::cout << "Cat btw\n";
}

Cat::Cat(const Cat &cat): Animal(cat) {
	std::cout << "Cat btw\n";
}

Cat::~Cat() {
	std::cout << "Cat btw\n";
}

Cat	&Cat::operator=(const Cat &cat) {
	if (this != &cat) {
		setType(cat.getType());
	}
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "Meow\n";
}
