/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:33:41 by svereten          #+#    #+#             */
/*   Updated: 2025/05/09 16:39:51 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Cure.hpp"
#include <iostream>

Cure::Cure(): AMateria("cure") {
	if (DEBUG)
		std::cerr << "Cure was constructed (default)\n";
}

Cure::~Cure() {
	if (DEBUG)
		std::cerr << "Cure was destroyed\n";
}

Cure::Cure(const Cure &other): AMateria(other.getType()) {
	if (DEBUG)
		std::cerr << "Cure was constructed (copy)\n";
} 

Cure	&Cure::operator=(const Cure &other) {
	if (this != &other) {
	}
	if (DEBUG)
		std::cerr << "Cure was assigned\n";
	return (*this);
}

AMateria	*Cure::clone() const {
	AMateria	*res = new Cure(*this);

	return (res);
}

void	Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName()
		<< "'s wounds\n";
}
