/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:07:31 by wiozsert          #+#    #+#             */
/*   Updated: 2022/11/30 17:12:26 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers.hpp"
#define RED "\033[1;31m"
#define GRN "\033[1;32m"
#define YEL "\033[1;33m"
#define BLU "\033[1;34m"
#define MAG "\033[1;35m"
#define CYA "\033[1;36m"
#define COLOR(x) std::cout<<x;
#define ENDCOLOR std::cout<<"\033[0m";
#include <vector>

void	printRealVector(std::vector<int> &v)
{
	COLOR(MAG)std::cout << "Vector size is : " << v.size() << std::endl;ENDCOLOR
	for (std::vector<int>::iterator	it = v.begin() ; it != v.end() ; it++)
		std::cout << *it << std::endl;
}

void	printMyVector(ft::vector<int> &v)
{
	COLOR(GRN)std::cout << "Vector size is : " << v.size() << std::endl;ENDCOLOR
	for (ft::vector<int>::iterator	it = v.begin() ; it != v.end() ; it++)
		std::cout << *it << std::endl;
}

int main( void )
{
	try
	{//4.611.686.018.427.387.903 ==> max_size()
		// ft::vector<int>	vr;
		ft::vector<int>	v(4, 42);
		v.push_back(-42);
		v.push_back(42);
		// v.push_back(21);
		// v.push_back(10);
		// v.erase(v.begin(), v.end());
		// std::cout << *it << std::endl;
		// std::cout << v.capacity() << std::endl;
		// std::vector<int>::iterator	itb = v.begin();
		// std::vector<int>::iterator	ite = v.end();
		// ft::vector<int>::iterator	pos = vr.begin();
		// vr.insert(pos, itb, ite);
		printMyVector(v);
		// printRealVector(v);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}