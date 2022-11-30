/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:21:41 by wiozsert          #+#    #+#             */
/*   Updated: 2022/11/30 16:56:24 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
#define EQUAL_HPP

#include "extern_library.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"

namespace ft{

template <class InputIterator1, class InputIterator2>
bool	equal(InputIterator1 first1,
				InputIterator1 last1,
					InputIterator2 first2,
						typename ft::enable_if<!ft::is_integral<InputIterator1>::value, InputIterator1>::type* = NULL) {
	while (first1 != last1)
	{
		if (*first1 != *first2)
			return false;
		first1++;
		first2++;
	}
	return true;
};

template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool	equal(InputIterator1 first1,
				InputIterator1 last1,
					InputIterator2 first2,
						BinaryPredicate pred,
						typename ft::enable_if<!ft::is_integral<InputIterator1>::value, InputIterator1>::type* = NULL) {
	while (first1 != last1)
	{
		if (!pred(*first1, *first2))
			return false;
		first1++;
		first2++;
	}
	return true;
};

};



#endif