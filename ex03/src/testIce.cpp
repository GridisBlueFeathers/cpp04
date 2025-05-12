/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testIce.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:59:03 by svereten          #+#    #+#             */
/*   Updated: 2025/05/12 19:00:42 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Character.hpp"
#include "Ice.hpp"
#include <gtest/gtest.h>

TEST(Ice, constructors) {
	Ice		def;
	Ice		copy(def);
	Ice		assign = def;
	ICharacter	*bob = new Character("Bob");
	std::string	out;

	testing::internal::CaptureStdout();
	def.use(*bob);
	out = testing::internal::GetCapturedStdout();
	EXPECT_EQ(out, "* shoots an ice bolt at Bob *\n");
	testing::internal::CaptureStdout();
	copy.use(*bob);
	out = testing::internal::GetCapturedStdout();
	EXPECT_EQ(out, "* shoots an ice bolt at Bob *\n");
	testing::internal::CaptureStdout();
	assign.use(*bob);
	out = testing::internal::GetCapturedStdout();
	EXPECT_EQ(out, "* shoots an ice bolt at Bob *\n");

	delete bob;
}

TEST(Ice, clone) {
	Ice		cure;
	AMateria	*m = cure.clone();
	ICharacter	*bob = new Character("Bob");
	std::string	out;

	testing::internal::CaptureStdout();
	m->use(*bob);
	out = testing::internal::GetCapturedStdout();
	EXPECT_EQ(out, "* shoots an ice bolt at Bob *\n");

	delete m;
	delete bob;
}

TEST(Ice, use) {
	Ice		cure;
	ICharacter	*bob = new Character("Bob");
	std::string	out;

	testing::internal::CaptureStdout();
	cure.use(*bob);
	out = testing::internal::GetCapturedStdout();
	EXPECT_EQ(out, "* shoots an ice bolt at Bob *\n");

	delete bob;
}
