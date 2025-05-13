/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:18:28 by svereten          #+#    #+#             */
/*   Updated: 2025/05/13 11:10:37 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

# include "ICharacter.hpp"
# include "Floor.hpp"

class AMateria {
public:
	AMateria(std::string const &type);
	virtual ~AMateria();

	void				*operator new(size_t size);

	std::string const	&getType() const;
	bool				getOnHeap() const;
	Floor				&getFloor() const;

	virtual AMateria	*clone() const = 0;
	virtual void		use(ICharacter &target);

private:
	std::string		_type;
	bool			_onHeap;
	static Floor	_floor;

	AMateria();
	AMateria(const AMateria &);

	AMateria			&operator=(const AMateria &);
};

#endif // !AMATERIA_HPP
