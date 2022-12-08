/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:07:31 by wiozsert          #+#    #+#             */
/*   Updated: 2022/12/08 13:08:09 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <vector>
#include <stack>

void	printVector(std::vector<int> &v)
{
	COLOR(MAG)std::cout << "Vector size is : " << v.size() << std::endl;ENDCOLOR
	for (std::vector<int>::iterator	it = v.begin() ; it != v.end() ; it++)
		std::cout << *it << std::endl;
	return ;
}

void	printVector(ft::vector<int> &v)
{
	COLOR(GRN)std::cout << "Vector size is : " << v.size() << std::endl;ENDCOLOR
	for (ft::vector<int>::iterator	it = v.begin() ; it != v.end() ; it++)
		std::cout << *it << std::endl;
	return ;
}

void	printStack(ft::stack<int, ft::vector<int> > &s)
{
	COLOR(GRN)std::cout << "Stack size is : " << s.size() << std::endl;ENDCOLOR
	for (size_t i = s.size() ; i > 0 ; i--)
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
	return ;
}

void	printStack(std::stack<int, std::vector<int> > &s)
{
	COLOR(MAG)std::cout << "Stack size is : " << s.size() << std::endl;ENDCOLOR
	for (size_t i = s.size() ; i > 0 ; i--)
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
	return ;
}

int main( void )
{
	try
	{
	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}