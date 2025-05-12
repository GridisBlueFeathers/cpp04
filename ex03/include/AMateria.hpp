/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:18:28 by svereten          #+#    #+#             */
/*   Updated: 2025/05/12 16:07:27 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

#include "ICharacter.hpp"
#include "Floor.hpp"

class AMateria {
public:
	AMateria(std::string const &type);
	virtual ~AMateria();

	std::string const	&getType() const;
	Floor				&getFloor() const;

	virtual AMateria	*clone() const = 0;
	virtual void		use(ICharacter &target);

private:
	std::string		_type;
	static Floor	_floor;

	AMateria();
	AMateria(const AMateria &);

	AMateria			&operator=(const AMateria &);
protected:
};

#endif // !AMATERIA_HPP
