/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:23:54 by svereten          #+#    #+#             */
/*   Updated: 2025/05/07 12:49:45 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal {
public:
	Cat();
	Cat(const Cat &cat);
	~Cat();

	Cat		&operator=(const Cat &cat);
	
	Brain	*getBrain() const;
	void	setBrain(Brain *brain);

	void	makeSound() const;

private:
	Brain	*_brain;
};

#endif // CAT_HPP
