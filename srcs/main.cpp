/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:07:31 by wiozsert          #+#    #+#             */
/*   Updated: 2022/12/01 15:41:34 by wiozsert         ###   ########.fr       */
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
		std::stack<int, std::vector<int> >	s;
		s.push(42);
		s.push(21);
		s.push(10);
		s.push(5);
		s.push(2);
		s.push(1);
		s.push(0);
		printStack(s);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}