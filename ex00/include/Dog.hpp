/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:18:00 by svereten          #+#    #+#             */
/*   Updated: 2025/05/06 14:20:24 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Animal.hpp"

#ifndef DOG_HPP
# define DOG_HPP

class Dog: public Animal {
public:
	Dog();
	Dog(const Dog &dog);
	~Dog();

	Dog		&operator=(const Dog &dog);
	void	makeSound() const;

private:
	
};

#endif // !DOG_HPP
