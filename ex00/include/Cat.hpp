/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:23:54 by svereten          #+#    #+#             */
/*   Updated: 2025/05/06 13:37:27 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal {
public:
	Cat();
	Cat(const Cat &cat);
	~Cat();

	Cat		&operator=(const Cat &cat);
	void	makeSound() const;

private:
	
};

#endif // CAT_HPP
