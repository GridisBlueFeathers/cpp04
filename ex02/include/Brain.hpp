/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <svereten@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:56:56 by svereten          #+#    #+#             */
/*   Updated: 2025/05/07 13:00:19 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {
public:
	Brain();
	Brain(const Brain &brain);
	~Brain();

	Brain &operator=(const Brain &brain);

	std::string	getIdea(int idx) const;
	void		setIdea(const std::string &idea, int idx);


private:
	std::string	_ideas[100];
	
};

#endif // !BRAIN_HPP
