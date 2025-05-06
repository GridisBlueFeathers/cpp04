/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:02:57 by svereten          #+#    #+#             */
/*   Updated: 2025/05/06 13:32:31 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {
public:
	Animal();
	Animal(const Animal &animal);
	virtual ~Animal();
	Animal(const std::string &type);

	Animal			&operator=(const Animal &animal);

	std::string		getType() const;
	void			setType(const std::string &type);
	virtual void	makeSound() const;

private:
	std::string	_type;
};

#endif // ANIMAL_HPP
