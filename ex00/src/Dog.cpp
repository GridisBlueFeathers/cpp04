/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:17:51 by svereten          #+#    #+#             */
/*   Updated: 2025/05/06 14:24:53 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Dog.hpp"
#include <iostream>

Dog::Dog(): Animal("Dog") {
	std::cout << "btw Dog\n"; 
}

Dog::Dog(const Dog &dog): Animal(dog) {
	std::cout << "btw Dog\n";
}

Dog::~Dog() {
	std::cout << "btw Dog\n";
}

Dog	&Dog::operator=(const Dog &dog) {
	if (this != &dog) {
		setType(dog.getType());
	}
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "Woof\n";
}
