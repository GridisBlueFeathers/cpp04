/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:29:41 by svereten          #+#    #+#             */
/*   Updated: 2025/05/06 14:35:29 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &animal);
	~WrongAnimal();
	WrongAnimal(const std::string &type);

	WrongAnimal	&operator=(const WrongAnimal &animal);

	std::string	getType() const;
	void		setType(const std::string &type);
	void		makeSound() const;

private:
	std::string	_type;
};

#endif // !WRONGANIMAL_HPP
