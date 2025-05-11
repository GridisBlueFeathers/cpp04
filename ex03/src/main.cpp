/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:15:01 by svereten          #+#    #+#             */
/*   Updated: 2025/05/11 17:35:28 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Floor.hpp"
#include <iostream>

#ifndef DEBUG
# define DEBUG 1
#endif // !DEBUG

void	testAMateria() {
	std::cout << "-- AMateria tests --\n";
	// Amateria cannot be instantiated by itself 
	//AMateria materia;

}

int	main() {
	IMateriaSource	*src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter	*me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	std::cout << tmp->getType() << std::endl;
	me->equip(tmp);
	tmp = src->createMateria("cure");
	std::cout << tmp->getType() << std::endl;
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(0);
	me->unequip(1);

	Floor	*floor = Floor::get();

	delete src;
	delete me;
	delete bob;
	delete floor;
}
