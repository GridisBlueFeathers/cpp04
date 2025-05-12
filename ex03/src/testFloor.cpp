/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testFloor.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:23:21 by svereten          #+#    #+#             */
/*   Updated: 2025/05/12 18:56:16 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Floor.hpp"
#include <gtest/gtest.h>

/**
 * Copy and assignment are private because floor is only supposed to be a part
 * of AMateria class
 */
TEST(Floor, constructor) {
	Floor floor;
	Floor noCompileB;
	//Floor noCompileA(floor);
	//noCompileB = floor;
}
