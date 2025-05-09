/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:41:01 by svereten          #+#    #+#             */
/*   Updated: 2025/05/09 17:04:12 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "AMateria.hpp"

class Character: public ICharacter {
public:
	Character();
	~Character();
	Character(const Character &other);
	Character(const std::string &name);

	Character &operator=(const Character &other);

	std::string const	&getName() const;
	void				equip(AMateria *aMateria);
	void				unequip(int idx);
	void				use(int idx, ICharacter &target);

private:
	std::string	_name;
	AMateria	*_materias[4];
	
};

#endif // !CHARACTER_HPP

