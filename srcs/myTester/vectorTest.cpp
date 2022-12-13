/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorTest.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:12:55 by wiozsert          #+#    #+#             */
/*   Updated: 2022/12/13 14:56:27 by wiozsert         ###   ########.fr       */
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

void	emptyConstructor(std::ofstream &myOfs, std::ofstream &realOfs) {
	std::vector<int>	realVector;
	ft::vector<int>		myVector;

	if (realVector.empty() && myVector.empty()) {
		showRealVector(realVector, realOfs);
		showMyVector(myVector, myOfs);
	}
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

void	assignRangeTest(std::ofstream &myOfs, std::ofstream &realOfs) {
	std::vector<int>	tmpReal(4, 42);
	ft::vector<int>		tmpMine(4, 42);

	for (int i = 0 ; i < 38 ; i++) {
		tmpReal.push_back(i);
		tmpMine.push_back(i);
	}
	std::vector<int>	realVector;
	ft::vector<int>		myVector;
	realVector.assign(tmpReal.begin(), tmpReal.end());
	myVector.assign(tmpMine.begin(), tmpMine.end());
	showMyVector(myVector, myOfs);
	showRealVector(realVector, realOfs);
	return ;
}

void	assignFillTest(std::ofstream &myOfs, std::ofstream &realOfs) {
	std::vector<int>	realVector;
	ft::vector<int>		myVector;

	realVector.assign(42, 42);
	myVector.assign(42, 42);
	showMyVector(myVector, myOfs);
	showRealVector(realVector, realOfs);
	return ;
}


void	assignTest(std::ofstream &myOfs, std::ofstream &realOfs) {
	assignRangeTest(myOfs, realOfs);
	assignFillTest(myOfs, realOfs);
	return ;
}

void	atTest(std::ofstream &myOfs, std::ofstream &realOfs) {
	std::vector<int>	realVector;
	ft::vector<int>		myVector;

	myOfs << "at Test :" << std::endl;
	realOfs << "at Test :" << std::endl;
	for (int i = 0 ; i < 42 ; i++) {
		realVector.push_back(i);
		myVector.push_back(i);
	}
	myOfs << "Vector size is " << myVector.size() << std::endl;
	realOfs << "Vector size is " << realVector.size() << std::endl;
	for (int i = 0 ; i < 42 ; i++) {
		realOfs << realVector.at(i) << std::endl;
		myOfs << myVector.at(i) << std::endl;
	}
	return ;
}

void	operatorTest(std::ofstream &myOfs, std::ofstream &realOfs) {
	std::vector<int>	realVector;
	ft::vector<int>		myVector;

	myOfs << "Operator Test :" << std::endl;
	realOfs << "Operator Test :" << std::endl;
	for (int i = 0 ; i < 42 ; i++) {
		realVector.push_back(i);
		myVector.push_back(i);
	}
	myOfs << "Vector size is " << myVector.size() << std::endl;
	realOfs << "Vector size is " << realVector.size() << std::endl;
	for (int i = 0 ; i < 42 ; i++) {
		realOfs << realVector[i] << std::endl;
		myOfs << myVector[i] << std::endl;
	}
	return ;
}

void	frontTest(std::ofstream &myOfs, std::ofstream &realOfs) {
	std::vector<int>	realVector;
	ft::vector<int>		myVector;

	myOfs << "Front Test :" << std::endl;
	realOfs << "Front Test :" << std::endl;
	for (int i = 100 ; i > 0 ; i--) {
		realVector.push_back(i);
		myVector.push_back(i);
	}
	myOfs << "Vector size is " << myVector.size() << std::endl;
	realOfs << "Vector size is " << realVector.size() << std::endl;
	for (int i = 0 ; i < 100 ; i++) {
		realOfs << realVector.front() << std::endl;
		myOfs << myVector.front() << std::endl;
		realVector.erase(realVector.begin());
		myVector.erase(myVector.begin());
	}
	return ;
}

void	backTest(std::ofstream &myOfs, std::ofstream &realOfs) {
	std::vector<int>	realVector(42, -42);
	ft::vector<int>		myVector(42, -42);

	myOfs << "Back Test :" << std::endl;
	realOfs << "Back Test :" << std::endl;
	myOfs << "Vector size is " << myVector.size() << std::endl;
	realOfs << "Vector size is " << realVector.size() << std::endl;
	while (realVector.empty() == false && myVector.empty() == false)
	{
		realOfs << realVector.back() << std::endl;
		myOfs << myVector.back() << std::endl;
		realVector.pop_back();
		myVector.pop_back();
	}
	return ;
}

void	reverseIteratorTest(std::ofstream &myOfs, std::ofstream &realOfs) {
	std::vector<int>			realVector;
	ft::vector<int>				myVector;
	ft::vector<int>::reverse_iterator	itMy;
	std::vector<int>::reverse_iterator	itReal;

	for (int i = 0 ; i < 100 ; i++) {
		realVector.push_back(i);
		myVector.push_back(i);
	}
	itMy = myVector.rbegin();
	itReal = realVector.rbegin();
	while (itMy != myVector.rend() && itReal != realVector.rend()) {
		myOfs << *itMy << std::endl;
		realOfs << *itReal << std::endl;
		++itMy;
		++itReal;
	}
	return ;
}

void	testForVector( void ) {
	std::ofstream		myOfs("./my_output_file.txt", std::ofstream::out | std::ofstream::trunc);
	std::ofstream		realOfs("./real_output_file.txt", std::ofstream::out | std::ofstream::trunc);

	// emptyConstructor(myOfs, realOfs);
	// fillConstructor(myOfs, realOfs);
	// rangeConstructor(myOfs, realOfs);
	// copyConstructor(myOfs, realOfs);
	// assignTest(myOfs, realOfs);
	// atTest(myOfs, realOfs);
	// operatorTest(myOfs, realOfs);
	// frontTest(myOfs, realOfs);
	// backTest(myOfs, realOfs);
	reverseIteratorTest(myOfs, realOfs);
	myOfs.close();
	realOfs.close();
	return ;
}