/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:02:46 by svereten          #+#    #+#             */
/*   Updated: 2025/05/12 16:05:15 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FLOOR_HPP
# define FLOOR_HPP

# include <cstddef>

class AMateria;

class Floor {
public:
	Floor();
	~Floor();
	void			add(AMateria *aMateria);

private:
	Floor(const Floor &other);
	Floor &operator=(const Floor &other);

	AMateria		**_materias;
	size_t			_size;
	
};

#endif // !FLOOR_HPP
