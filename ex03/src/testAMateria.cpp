/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testAMateria.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:33:10 by svereten          #+#    #+#             */
/*   Updated: 2025/05/11 20:04:37 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "gtest/gtest.h"

TEST(AMateria, typeReturn) {
	AMateria *materia = new Ice();

	EXPECT_STREQ(materia->getType().c_str(), "ice");
	delete materia;

}

