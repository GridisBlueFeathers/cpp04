/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:06:24 by svereten          #+#    #+#             */
/*   Updated: 2025/05/09 16:20:39 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria {
public:
	Ice();
	~Ice();
	Ice(const Ice &other);
	
	Ice			&operator=(const Ice &other);
	
	AMateria	*clone() const;
	void		use(ICharacter &target);

private:
	
};

#endif // !ICE_HPP
