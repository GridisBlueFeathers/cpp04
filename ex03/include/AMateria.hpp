/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:18:28 by svereten          #+#    #+#             */
/*   Updated: 2025/05/09 13:38:44 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

#include "ICharacter.hpp"

class AMateria {
public:
	AMateria(std::string const &type);
	virtual ~AMateria();

	std::string const	&getType() const;

	virtual AMateria	*clone() const = 0;
	virtual void		use(ICharacter &target);

private:
	std::string	_type;

protected:
	AMateria();
	AMateria(const AMateria &);

	AMateria			&operator=(const AMateria &);
};

#endif // !AMATERIA_HPP
