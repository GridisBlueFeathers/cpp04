/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:23:54 by svereten          #+#    #+#             */
/*   Updated: 2025/05/06 14:37:51 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
public:
	WrongCat();
	WrongCat(const WrongCat &cat);
	~WrongCat();

	WrongCat	&operator=(const WrongCat &cat);
	void		makeSound() const;

private:
	
};

#endif // WRONGCAT_HPP
