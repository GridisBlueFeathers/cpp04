/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:06:11 by svereten          #+#    #+#             */
/*   Updated: 2025/05/12 18:53:33 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Floor.hpp"
#include "AMateria.hpp"
#include <cstdio>
#include <iostream>

// Public
//

Floor::Floor(): _materias(), _size(0) {
	if (DEBUG)
		std::cerr << "Floor was constructed (default)\n";
}

Floor::~Floor() {
	size_t	i = 0;

	while (i < _size) {
		delete _materias[i];
		i++;
	}
	delete [] _materias;

	if (DEBUG)
		std::cerr << "Floor was destroyed\n";
}

void	Floor::add(AMateria *aMateria) {
	AMateria	**res = new AMateria *[_size + 1];
	size_t		i = 0;

	while (i < _size) {
		res[i] = _materias[i];
		i++;
	}
	res[i] = aMateria;
	delete [] _materias;
	_materias = res;
	_size++;
}

// Private
//

Floor::Floor(const Floor &other) {
	(void)other;
	std::cerr << "You are not supposed to see this\n";
}

Floor	&Floor::operator=(const Floor &other) {
	(void)other;
	std::cerr << "You are not supposed to see this\n";
	return (*this);
}
