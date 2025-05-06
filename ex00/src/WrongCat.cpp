/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:23:46 by svereten          #+#    #+#             */
/*   Updated: 2025/05/06 14:35:11 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal("WrongCat") {
	std::cout << "WrongCat btw\n";
}

WrongCat::WrongCat(const WrongCat &cat): WrongAnimal(cat) {
	std::cout << "WrongCat btw\n";
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat btw\n";
}

WrongCat	&WrongCat::operator=(const WrongCat &cat) {
	if (this != &cat) {
		setType(cat.getType());
	}
	return (*this);
}

void	WrongCat::makeSound() const {
	std::cout << "Meow\n";
}
