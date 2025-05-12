/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testAMateria.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:33:10 by svereten          #+#    #+#             */
/*   Updated: 2025/05/12 13:30:17 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "gtest/gtest.h"

/**
 * These won't compile to show that AMateria is not instantiatible by itself
 */
// TEST(AMateria, wontCompile) {
// 	AMateria matA;
// 	AMateria matB("Some name");
// 	AMateria matC = matA;
// 	AMateria matD(matA);
// }

TEST(AMateria, typeConstruction) {
	AMateria	*matA = new Ice();
	AMateria	*matB = new Cure();

	EXPECT_EQ(matA->getType(), "ice");
	EXPECT_EQ(matB->getType(), "cure");

	delete matA;
	delete matB;
}

TEST(AMateria, cloning) {
	AMateria	*matA = new Ice();
	AMateria	*matAClone = matA->clone();

	EXPECT_NE(matA, matAClone);
	EXPECT_EQ(matA->getType(), matAClone->getType());

	delete matA;
	delete matAClone;
}

TEST(AMateria, useOutput) {
	AMateria	*matA = new Ice();
	AMateria	*matB = new Cure();
	ICharacter	*john = new Character("John");

	testing::internal::CaptureStdout();
	matA->use(*john);
	std::string outA = testing::internal::GetCapturedStdout();
	EXPECT_EQ(outA, "* shoots an ice bolt at John *\n");
	testing::internal::CaptureStdout();
	matB->use(*john);
	std::string outB = testing::internal::GetCapturedStdout();
	EXPECT_EQ(outB, "* heals John’s wounds *\n");
	EXPECT_NE(outA, outB);
	
	delete matA;
	delete matB;
	delete john;
}
