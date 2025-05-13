/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:59:44 by svereten          #+#    #+#             */
/*   Updated: 2025/05/13 11:13:57 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "AMateria.hpp"
#include "Floor.hpp"
#include <iostream>

static bool	onHeap = false;

// Public
//

AMateria::AMateria(std::string const &type): _type(type), _onHeap(onHeap) {
	onHeap = false;
	if (DEBUG) {
		std::cout << "Materia of " << _type << " was created ";
		if (_onHeap)
			std::cout << "on heap\n";
		else
			std::cout << "on stack\n";
	}
}

AMateria::~AMateria() {
	if (DEBUG)
		std::cout << "Materia of " << _type << " was destroyed\n";
}

void	*AMateria::operator new(size_t size) {
	void	*res;

	res = ::operator new(size);
	onHeap = true;
	return (res);
}

std::string const	&AMateria::getType() const {
	return (_type);
}

bool	AMateria::getOnHeap() const {
	return (_onHeap);
}

Floor	&AMateria::getFloor() const {
	return (_floor);
}

void	AMateria::use(ICharacter &target) {
	std::cout << "* Unknown Materia does unimaginable things to " << target.getName()
		<< " *\n";
}


// Private
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

Floor	AMateria::_floor;
