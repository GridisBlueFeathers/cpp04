/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:08:29 by svereten          #+#    #+#             */
/*   Updated: 2025/05/09 16:21:02 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Ice.hpp"
#include <iostream>

Ice::Ice(): AMateria("ice") {
	if (DEBUG)
		std::cerr << "Ice was created (default)\n";
}

Ice::~Ice() {
	if (DEBUG)
		std::cerr << "Ice was destroyed\n";
}

Ice::Ice(const Ice &other): AMateria(other.getType()) {
	if (DEBUG)
		std::cerr << "Ice was created (copy)\n";
}

Ice	&Ice::operator=(const Ice &other) {
	if (this != &other) {

	}
	if (DEBUG)
		std::cerr << "Ice was assigned\n";
	return (*this);
}

AMateria	*Ice::clone() const {
	AMateria	*res = new Ice(*this);

	return (res);
}

void	Ice::use(ICharacter	&target) {
	std::cout << "* shoots an ice bolt at " << target.getName()
		<< " *\n";
}
