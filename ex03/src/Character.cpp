/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:46:34 by svereten          #+#    #+#             */
/*   Updated: 2025/05/12 16:13:18 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Character.hpp"
#include "Floor.hpp"
#include <iostream>

Character::Character(): _name("John"), _materias() {
	if (DEBUG)
		std::cerr << "Character by the name " << _name
			<< " was constructed (default)\n";
}

Character::~Character() {
	int	i = 0;

	while (i < 4) {
		delete _materias[i];
		i++;
	}
	if (DEBUG)
		std::cerr << "Character by the name " << _name
			<< " was destroyed\n";
}

Character::Character(const Character &other): _name(other._name), _materias() {
	if (DEBUG)
		std::cerr << "Character by the name " << _name
			<< " was constructed (copy)\n";
}

Character::Character(const std::string &name): _name(name), _materias() {
	if (DEBUG)
		std::cerr << "Character by the name " << _name
			<< " was constructed (name)\n";
}

Character	&Character::operator=(const Character &other) {
	if (this != &other) {
		_name = other._name;
	}
	std::cerr << "Character by the name " << _name
		<< " was assigned\n";
	return (*this);
}

std::string const	&Character::getName() const {
	return (_name);
}

void	Character::equip(AMateria *aMateria) {
	int	i = 0;

	while (i < 4) {
		if (!_materias[i]) {
			_materias[i] = aMateria;
			break ;
		}
		i++;
	}
}

// Oof size: Large *edit: not so large anymore
void	Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return ;
	_materias[idx]->getFloor().add(_materias[idx]);
	_materias[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx < 4 && _materias[idx])
		_materias[idx]->use(target);
}
