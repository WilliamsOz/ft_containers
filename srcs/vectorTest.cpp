/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorTest.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:12:55 by wiozsert          #+#    #+#             */
/*   Updated: 2022/12/09 16:23:09 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "ft_containers.hpp"
#include <vector>

void	showRealVector(std::vector<int> &v, std::ofstream &ofs)
{
	for (std::vector<int>::iterator	it = v.begin() ; it != v.end() ; it++)
		ofs << *it << std::endl;
	return ;
}

void	showMyVector(ft::vector<int> &v, std::ostream &ofs)
{
	for (ft::vector<int>::iterator	it = v.begin() ; it != v.end() ; it++)
		ofs << *it << std::endl;
	return ;
}

void	testForVector( void ) {
	ft::vector<int>		myVector(100, 42);
	std::vector<int>	realVector(100, 42);
	std::ofstream		myOfs("./my_output_file.txt", std::ofstream::out | std::ofstream::trunc);
	std::ofstream		realOfs("./real_output_file.txt", std::ofstream::out | std::ofstream::trunc);

	// for (int i = 0; i < 100 ; i++)
	// {
	// 	p1 i p2
	// 	myVector.push_back(i);
	// 	realVector.push_back(i);
	// }
	showMyVector(myVector, myOfs);
	showRealVector(realVector, realOfs);
	// p1 myVector[0] p2
}
