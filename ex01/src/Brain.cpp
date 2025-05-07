/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:30:13 by svereten          #+#    #+#             */
/*   Updated: 2025/05/07 13:04:06 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain was created\n";
}

Brain::Brain(const Brain &brain) {
	int	i;

	i = 0;
	while (i < 100) {
		_ideas[i] = brain._ideas[i];
		i++;
	}
	std::cout << "Brain was created\n";
}

Brain::~Brain() {
	std::cout << "Brain is shutting down\n";
}

Brain	&Brain::operator=(const Brain &brain) {
	int	i;

	if (this != &brain) {
		i = 0;
		while (i < 100) {
			_ideas[i] = brain._ideas[i];
			i++;
		}
	}
	return (*this);
}

std::string	Brain::getIdea(int idx) const {
	return (_ideas[idx]);
}

void	Brain::setIdea(const std::string &idea, int idx) {
	_ideas[idx] = idea;
}
