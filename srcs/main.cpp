/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:07:31 by wiozsert          #+#    #+#             */
/*   Updated: 2022/11/28 16:26:20 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers.hpp"
#include <vector>

int main( void )
{
	try
	{//4.611.686.018.427.387.903
		std::vector<int>	v(4, 42);
		// std::cout << v.size() << std::endl;
		// v.clear();
		v.reserve(2);
		// std::cout << v[0] << std::endl;
		// std::cout << v[1] << std::endl;
		// std::cout << v[2] << std::endl;
		// std::cout << v[3] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}