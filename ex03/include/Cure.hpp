/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:32:23 by svereten          #+#    #+#             */
/*   Updated: 2025/05/12 18:17:47 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria {
public:
	Cure();
	~Cure();
	Cure(const Cure &other);

	Cure &operator=(const Cure &other);
	
	AMateria	*clone() const;
	void		use(ICharacter &target);
};
#endif // !CURE_HPP
