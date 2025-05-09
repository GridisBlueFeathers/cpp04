/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:15:01 by svereten          #+#    #+#             */
/*   Updated: 2025/05/09 13:32:16 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "MateriaSource.hpp"
#include <iostream>

#ifndef DEBUG
# define DEBUG 1
#endif // !DEBUG

int	main() {
	IMateriaSource	*src = new MateriaSource();

	delete src;
}
