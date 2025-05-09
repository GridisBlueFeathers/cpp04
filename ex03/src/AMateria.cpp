/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:59:44 by svereten          #+#    #+#             */
/*   Updated: 2025/05/09 13:39:12 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "AMateria.hpp"
#include <iostream>

// Public
//

AMateria::AMateria(std::string const &type): _type(type) {
	if (DEBUG)
		std::cout << "Materia of " << _type << " was created\n";
}

AMateria::~AMateria() {
	if (DEBUG)
		std::cout << "Materia of " << _type << " was destroyed\n";
}

std::string const	&AMateria::getType() const {
	return (_type);
}

void	AMateria::use(ICharacter &target) {
	std::cout << "* Unknown Materia does unimaginable things to " << target.getName()
		<< " *\n";
}


// Protected
//

AMateria::AMateria(): _type("Unknown Materia") {
	std::cerr << "You shouldn't be able to see this\n";
}

AMateria::AMateria(const AMateria &aMateria): _type(aMateria._type) {
	std::cerr << "You shouldn't be able to see this\n";
}

AMateria	&AMateria::operator=(const AMateria &aMateria) {
	std::cerr << "You shouldn't be able to see this\n";
	if (this != &aMateria) {
		_type = aMateria._type;
	}
	return (*this);
}
