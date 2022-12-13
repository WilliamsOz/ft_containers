/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorTest.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:12:55 by wiozsert          #+#    #+#             */
/*   Updated: 2022/12/13 12:35:43 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <fstream>
#include <iostream>
#include <vector>

void	showRealVector(std::vector<int> &v, std::ofstream &ofs) {
	ofs << "Size of vector is " << v.size() << std::endl;
	for (std::vector<int>::iterator	it = v.begin() ; it != v.end() ; it++)
		ofs << *it << std::endl;
	return ;
}

void	showMyVector(ft::vector<int> &v, std::ofstream &ofs) {
	ofs << "Size of vector is " << v.size() << std::endl;
	for (ft::vector<int>::iterator	it = v.begin() ; it != v.end() ; it++)
		ofs << *it << std::endl;
	return ;
}

void	emptyConstructor( std::ofstream &myOfs, std::ofstream &realOfs ) {
	std::vector<int>	realVector;
	ft::vector<int>		myVector;

	showMyVector(myVector, myOfs);
	showRealVector(realVector, realOfs);
	return ;
}

void	fillConstructor(std::ofstream &myOfs, std::ofstream &realOfs ) {
	std::vector<int>	realVector(4, 42);
	ft::vector<int>		myVector(4, 42);

	showMyVector(myVector, myOfs);
	showRealVector(realVector, realOfs);
	return ;
}

void	rangeConstructor(std::ofstream &myOfs, std::ofstream &realOfs) {
	std::vector<int>	tmp;

	for (int i = 0 ; i < 42 ; i++)
		tmp.push_back(i);
	std::vector<int>	realVector(tmp.begin(), tmp.end());
	ft::vector<int>		myVector(tmp.begin(), tmp.end());
	showMyVector(myVector, myOfs);
	showRealVector(realVector, realOfs);
	return ;
}

void	copyConstructor(std::ofstream &myOfs, std::ofstream &realOfs) {
	std::vector<int>	tmpReal(4, 42);
	ft::vector<int>		tmpMine(4, 42);

	for (int i = 0 ; i < 38 ; i++) {
		tmpReal.push_back(-42);
		tmpMine.push_back(-42);
	}
	std::vector<int>	realVector(tmpReal);
	ft::vector<int>		myVector(tmpMine);
	showMyVector(myVector, myOfs);
	showRealVector(realVector, realOfs);
	return ;
}

void	testForVector( void ) {
	std::ofstream		myOfs("./my_output_file.txt", std::ofstream::out | std::ofstream::trunc);
	std::ofstream		realOfs("./real_output_file.txt", std::ofstream::out | std::ofstream::trunc);

	emptyConstructor(myOfs, realOfs);
	fillConstructor(myOfs, realOfs);
	rangeConstructor(myOfs, realOfs);
	copyConstructor(myOfs, realOfs);
	myOfs.close();
	realOfs.close();
	return ;
}