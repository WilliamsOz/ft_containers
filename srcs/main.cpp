/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:07:31 by wiozsert          #+#    #+#             */
/*   Updated: 2022/11/15 15:15:03 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers.hpp"

int main( void )
{
	ft::vector<int>	v(4, 42);
	ft::iterator<int, int>	it;

	it = v.begin();
	// int	tab[2] = {42, 42};
	// *it = tab[0];
	std::cout << *it << std::endl;
	return 0;
}