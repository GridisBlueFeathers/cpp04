/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testCharacter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:17:24 by svereten          #+#    #+#             */
/*   Updated: 2025/05/13 11:22:20 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <gtest/gtest.h>

TEST(Character, constructors) {
	Character	john;
	Character	*heapJohn = new Character();
	Character	johnCopy(john);
	Character	jane("Jane");
	Character	assignedJohn = john;

	EXPECT_EQ(john.getName(), "John");
	EXPECT_EQ(heapJohn->getName(), "John");
	EXPECT_EQ(johnCopy.getName(), "John");
	EXPECT_EQ(jane.getName(), "Jane");
	EXPECT_EQ(assignedJohn.getName(), "John");

	delete heapJohn;
}

/**
 * Use ouputs nothing when tries to use non existant materia
 *
 * Equip John with 4 ices, so there are no slots for cure
 *
 * John will only use cure, and new materia would need to be handled outside of John
 */
TEST(Character, equip) {
	Character	john;
	Character	bob("Bob");
	AMateria	*m = new Ice();

	// Check that nothing happens if index is wrong
	testing::internal::CaptureStdout();
	john.use(1000, bob);
	std::string out = testing::internal::GetCapturedStdout();
	EXPECT_EQ(out, "");

	// Check that nothing happens if index is right but there is no materia there yet
	for (int i = 0; i < 4; i++) {
		testing::internal::CaptureStdout();
		john.use(i, bob);
		std::string out = testing::internal::GetCapturedStdout();
		EXPECT_EQ(out, "");
		john.equip(m->clone());
	}

	delete m;

	// Check that new materia doesn't overwrite old ones
	m = new Cure();
	AMateria	*tmp = m->clone();

	john.equip(tmp);

	for (int i = 0; i < 4; i++) {
		testing::internal::CaptureStdout();
		john.use(i, bob);
		std::string out = testing::internal::GetCapturedStdout();
		EXPECT_EQ(out, "* shoots an ice bolt at Bob *\n");
	}

	delete m;
	delete tmp;
}

TEST(Character, unequip) {
	Character	john;
	Character	bob("Bob");
	AMateria	*m = new Ice();

	for (int i = 0; i < 4; i++) {
		john.equip(m->clone());
	}

	// Check for nothing happening if materia at the slot got unequipped
	for (int i = 0; i < 4; i++) {
		john.unequip(i);
		testing::internal::CaptureStdout();
		john.use(i, bob);
		std::string out = testing::internal::GetCapturedStdout();
		EXPECT_EQ(out, "");
	}

	// Check for nothing happening if index is invalid
	john.unequip(1000);

	delete m;
}

TEST(Character, deepCopy) {
	Character	*john = new Character();
	Character	johnAssign;
	Character	bob("Bob");
	AMateria	*m = new Ice();

	john->equip(m->clone());
	john->equip(m->clone());
	john->equip(m->clone());
	john->equip(m->clone());

	Character	johnCopy(*john);
	johnAssign = *john;

	delete john;

	// Check for copy still being able to use materia even if original
	// instance was deleted, and with it all the materias and pointers
	// were freed as well
	for (int i = 0; i < 4; i++) {
		testing::internal::CaptureStdout();
		johnCopy.use(i, bob);
		std::string out = testing::internal::GetCapturedStdout();
		EXPECT_EQ(out, "* shoots an ice bolt at Bob *\n");
	}

	for (int i = 0; i < 4; i++) {
		testing::internal::CaptureStdout();
		johnAssign.use(i, bob);
		std::string out = testing::internal::GetCapturedStdout();
		EXPECT_EQ(out, "* shoots an ice bolt at Bob *\n");
	}

	delete m;
}

/**
 * Tis segfaults for now
 * Edit: tis doesn't segfault anymore
 */
TEST(Character, passingStackByReference) {
	Character	john;
	Ice			ice;

	john.equip(&ice);

}
