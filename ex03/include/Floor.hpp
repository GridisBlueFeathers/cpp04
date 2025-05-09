/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:02:46 by svereten          #+#    #+#             */
/*   Updated: 2025/05/09 18:16:29 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FLOOR_HPP
# define FLOOR_HPP

#include "AMateria.hpp"
#include <cstddef>

class Floor {
public:
	~Floor();
	static Floor	*get();
	void			add(AMateria *aMateria);
	void			clean();

private:
	Floor();
	Floor(const Floor &other);
	Floor &operator=(const Floor &other);

	static Floor	*_floor;
	AMateria		**_materias;
	size_t			_size;
	
};

#endif // !FLOOR_HPP
