/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMateriaSource.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:01:26 by svereten          #+#    #+#             */
/*   Updated: 2025/05/13 11:25:16 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <gtest/gtest.h>
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

TEST(MateriaSource, constructors) {
	MateriaSource	source;
	AMateria		*ice = new Ice();
	std::string		out;

	source.learnMateria(ice);

	MateriaSource	sourceCopy(source);
	MateriaSource	sourceAssign;

	sourceAssign = source;

	ICharacter	*john = new Character();

	john->equip(source.createMateria("ice"));
	john->equip(sourceCopy.createMateria("ice"));
	john->equip(sourceAssign.createMateria("ice"));

	ICharacter	*bob = new Character("Bob");

	testing::internal::CaptureStdout();
	john->use(0, *bob);
	out = testing::internal::GetCapturedStdout();
	EXPECT_EQ(out, "* shoots an ice bolt at Bob *\n");
	testing::internal::CaptureStdout();
	john->use(1, *bob);
	out = testing::internal::GetCapturedStdout();
	EXPECT_EQ(out, "* shoots an ice bolt at Bob *\n");
	testing::internal::CaptureStdout();
	john->use(2, *bob);
	out = testing::internal::GetCapturedStdout();
	EXPECT_EQ(out, "* shoots an ice bolt at Bob *\n");

	delete john;
	delete bob;
}

/**
 * 
 */
TEST(IMateriaSource, learnMateria) {
	IMateriaSource	*src = new MateriaSource();
	AMateria		*i0 = new Ice();
	AMateria		*i1 = new Ice();
	AMateria		*i2 = new Ice();
	AMateria		*i3 = new Ice();
	AMateria		*c = new Cure();
	std::string		out;

	src->learnMateria(i0);
	src->learnMateria(i1);
	src->learnMateria(i2);
	src->learnMateria(i3);
	src->learnMateria(c);

	ICharacter	*john = new Character();

	john->equip(src->createMateria("ice"));
	john->equip(src->createMateria("cure"));

	ICharacter	*bob = new Character("Bob");

	testing::internal::CaptureStdout();
	john->use(0, *bob);
	out = testing::internal::GetCapturedStdout();
	EXPECT_EQ(out, "* shoots an ice bolt at Bob *\n");
	testing::internal::CaptureStdout();
	john->use(1, *bob);
	out = testing::internal::GetCapturedStdout();
	EXPECT_EQ(out, "");

	delete john;
	delete bob;
	delete src;
	delete c;
}

TEST(IMateriaSource, createMateria) {
	IMateriaSource	*src = new MateriaSource();
	AMateria		*i = new Ice();
	AMateria		*c = new Cure();
	std::string		out;

	src->learnMateria(i);
	src->learnMateria(c);

	ICharacter	*john = new Character();

	john->equip(src->createMateria("ice"));
	john->equip(src->createMateria("cure"));

	ICharacter	*bob = new Character("Bob");

	testing::internal::CaptureStdout();
	john->use(0, *bob);
	out = testing::internal::GetCapturedStdout();
	EXPECT_EQ(out, "* shoots an ice bolt at Bob *\n");
	testing::internal::CaptureStdout();
	john->use(1, *bob);
	out = testing::internal::GetCapturedStdout();
	EXPECT_EQ(out, "* heals Bob’s wounds *\n");

	delete john;
	delete bob;
	delete src;
}

TEST(MateriaSource, deepCopy) {
	MateriaSource	*src = new MateriaSource();
	AMateria		*i = new Ice();
	AMateria		*c = new Cure();
	std::string		out;

	src->learnMateria(i);
	src->learnMateria(c);
	

	MateriaSource	srcCopy(*src);

	delete src;

	ICharacter	*john = new Character();

	john->equip(srcCopy.createMateria("ice"));
	john->equip(srcCopy.createMateria("cure"));

	ICharacter	*bob = new Character("Bob");

	testing::internal::CaptureStdout();
	john->use(0, *bob);
	out = testing::internal::GetCapturedStdout();
	EXPECT_EQ(out, "* shoots an ice bolt at Bob *\n");
	testing::internal::CaptureStdout();
	john->use(1, *bob);
	out = testing::internal::GetCapturedStdout();
	EXPECT_EQ(out, "* heals Bob’s wounds *\n");

	delete john;
	delete bob;
}

/**
 * This shouldn't segfault
 */
TEST(MateriaSource, passStackByReference) {
	MateriaSource	src;
	Ice				ice;

	src.learnMateria(&ice);

}
