/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:07:31 by wiozsert          #+#    #+#             */
/*   Updated: 2022/12/13 14:51:54 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

// void	printStack(ft::stack<int, ft::vector<int> > &s)
// {
// 	COLOR(GRN)std::cout << "Stack size is : " << s.size() << std::endl;ENDCOLOR
// 	for (size_t i = s.size() ; i > 0 ; i--)
// 	{
// 		std::cout << s.top() << std::endl;
// 		s.pop();
// 	}
// 	return ;
// }

// void	printStack(std::stack<int, std::vector<int> > &s)
// {
// 	COLOR(MAG)std::cout << "Stack size is : " << s.size() << std::endl;ENDCOLOR
// 	for (size_t i = s.size() ; i > 0 ; i--)
// 	{
// 		std::cout << s.top() << std::endl;
// 		s.pop();
// 	}
// 	return ;
// }


int main( int ac, char **av )
{
	try
	{
		if (ac == 1)
			return 0;
		else if (ac == 2 && static_cast<std::string>(av[1]).compare("vector_test") == 0)
			testForVector();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}