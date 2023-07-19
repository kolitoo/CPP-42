/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:18:06 by abourdon          #+#    #+#             */
/*   Updated: 2023/07/19 14:43:19 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class	Harl
{
	public:
	
		Harl(void);
		~Harl(void);
		
		void	complain(std::string level);

	private:

		int		_getlevel(std::string level, std::string *levels);
		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);
};

#endif