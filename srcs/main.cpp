/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:07:31 by wiozsert          #+#    #+#             */
/*   Updated: 2022/11/24 12:17:36 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers.hpp"
#include <vector>

int main( void )
{
	std::vector<int>	vr;
	vr.push_back(42);
	vr.push_back(21);
	vr.push_back(10);
	vr.push_back(5);
	vr.push_back(2);
	vr.push_back(1);
	vr.push_back(0);
	
	// std::reverse_iterator<std::vector<int>::iterator>	it = vr.rend();
	// ft::vector<int>		vm(4, 42);

	// std::iterator_traits<int>	it;
	// std::reverse_iterator<int>	lol;
	// std::vector<int>::iterator	itr;
	// itr = vr.begin();
	// ft::vector<int>::iterator	itm;
	// itm = vm.begin();
	// std::cout << *itm << std::endl;
	// std::vector<int>::iterator	itb = v.begin();
	// std::vector<int>::iterator	ite = v.end();
	// ptrdiff_t	ptr1 = ite - itb;

	// std::cout << ptr1 << std::endl;
	// std::cout << v.empty() << std::endl;
	// ft::vectorIterator<int>	itb(v.begin());
	// ft::vectorIterator<int>	ite(v.end());

	// ft::vector<int>	vt(itb, ite);
	// ft::vector<int>	v(4, 42);
	// ft::iterator<int, int>	it;
	// ft::iterator<int, int>	ite;

	// *it = 0;
	// std::cout << *it << std::endl;
	// v[1] = -42;
	// v[2] = -21;
	// it = v.begin();
	// ite = v.end();
	// if (ite==it)
	// 	std::cout << "Same" << std::endl;
	// else
	// 	std::cout << "Different" << std::endl;
	// it++;
	// std::cout << *it << std::endl;
	// ++it;
	// std::cout << *it << std::endl;
	return 0;
}