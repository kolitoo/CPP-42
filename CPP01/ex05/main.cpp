/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:35:31 by abourdon          #+#    #+#             */
/*   Updated: 2023/08/07 10:34:38 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl h;
	
	h.complain("debug");
	h.complain("info");
	h.complain("warning");
	h.complain("error");
	h.complain("TEST");
	return (0);
}