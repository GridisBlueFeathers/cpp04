/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:52:50 by svereten          #+#    #+#             */
/*   Updated: 2025/05/09 13:29:18 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
	if (DEBUG)
		std::cerr << "MateriaSource was created (default)\n";
}

MateriaSource::~MateriaSource() {
	if (DEBUG)
		std::cerr << "MateriaSource was destroyed\n";
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource) {
	deepCopyMaterias(materiaSource);
	if (DEBUG)
		std::cerr << "MateriaSource was created (copy)\n";
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &materiaSource) {
	if (this != &materiaSource) {
		deepCopyMaterias(materiaSource);
	}
	if (DEBUG)
		std::cerr << "MateriaSource was assigned\n";
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *aMateria) {
	int	i = 0;

	while (i < 4) {
		if (!_materias[i]) {
			_materias[i] = aMateria->clone();
			break ;
		}
		i++;
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type) {
	int			i = 0;
	AMateria	*res = NULL;

	while (i < 4) {
		if (_materias[i] && _materias[i]->getType() == type) {
			res = _materias[i]->clone();
			break ;
		}
		i++;
	}
	return (res);
}

void	MateriaSource::deepCopyMaterias(const MateriaSource &materiaSource) {
	int	i = 0;

	while (i < 4) {
		delete _materias[i];
		_materias[i] = NULL;
		if (materiaSource._materias[i])
			_materias[i] = materiaSource._materias[i]->clone();
		i++;
	}
}

