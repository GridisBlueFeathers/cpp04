/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testCure.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:06:57 by svereten          #+#    #+#             */
/*   Updated: 2025/05/12 18:17:29 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Character.hpp"
#include "Cure.hpp"
#include <gtest/gtest.h>

TEST(Cure, constructors) {
	Cure		def;
	Cure		copy(def);
	Cure		assign = def;
	ICharacter	*bob = new Character("Bob");
	std::string	out;

	testing::internal::CaptureStdout();
	def.use(*bob);
	out = testing::internal::GetCapturedStdout();
	EXPECT_EQ(out, "* heals Bob’s wounds *\n");
	testing::internal::CaptureStdout();
	copy.use(*bob);
	out = testing::internal::GetCapturedStdout();
	EXPECT_EQ(out, "* heals Bob’s wounds *\n");
	testing::internal::CaptureStdout();
	assign.use(*bob);
	out = testing::internal::GetCapturedStdout();
	EXPECT_EQ(out, "* heals Bob’s wounds *\n");

	delete bob;
}

TEST(Cure, clone) {
	Cure		cure;
	AMateria	*m = cure.clone();
	ICharacter	*bob = new Character("Bob");
	std::string	out;

	testing::internal::CaptureStdout();
	m->use(*bob);
	out = testing::internal::GetCapturedStdout();
	EXPECT_EQ(out, "* heals Bob’s wounds *\n");

	delete m;
	delete bob;
}

TEST(Cure, use) {
	Cure		cure;
	ICharacter	*bob = new Character("Bob");
	std::string	out;

	testing::internal::CaptureStdout();
	cure.use(*bob);
	out = testing::internal::GetCapturedStdout();
	EXPECT_EQ(out, "* heals Bob’s wounds *\n");

	delete bob;
}
