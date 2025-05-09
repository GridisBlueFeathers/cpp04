/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:34:18 by svereten          #+#    #+#             */
/*   Updated: 2025/05/09 13:24:33 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource: public IMateriaSource {
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource &materiaSource);

	MateriaSource	&operator=(const MateriaSource &materiaSource);

	void			learnMateria(AMateria *aMateria);
	AMateria		*createMateria(std::string const &type);

private:
	AMateria	*_materias[4];
	
	void			deepCopyMaterias(const MateriaSource &materiaSource);
};

#endif // !MATERIASOURCE_HPP
