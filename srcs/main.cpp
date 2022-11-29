/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:07:31 by wiozsert          #+#    #+#             */
/*   Updated: 2022/11/29 13:36:28 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers.hpp"
#include <vector>

void	printVector(ft::vector<int> &v)
{
	std::cout << v.size() << std::endl;
	for (ft::vector<int>::iterator	it = v.begin() ; it != v.end() ; it++)
		std::cout << *it << std::endl;
}

int main( void )
{
	try
	{//4.611.686.018.427.387.903 ==> max_size()
		ft::vector<int>	v(3, 42);
		ft::vector<int>::iterator	it = v.begin();
		it++;
		v.insert(it, 3, -42);
		printVector(v);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}