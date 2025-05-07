/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:18:00 by svereten          #+#    #+#             */
/*   Updated: 2025/05/07 14:10:32 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal {
public:
	Dog();
	Dog(const Dog &dog);
	~Dog();

	Dog		&operator=(const Dog &dog);

	Brain	*getBrain() const;
	void	setBrain(Brain *brain);

	void	makeSound() const;

private:
	Brain	*_brain;
	
};

#endif // !DOG_HPP
