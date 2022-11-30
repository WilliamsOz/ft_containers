/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:35:18 by wiozsert          #+#    #+#             */
/*   Updated: 2022/11/30 17:01:51 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP

#include "extern_library.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"

namespace ft {

template <class InputIterator1, class InputIterator2>
bool	lexicographical_compare(InputIterator1 first1,
									InputIterator1 last1,
										InputIterator2 first2,
											InputIterator2 last2,
												typename ft::enable_if<!ft::is_integral<InputIterator1>::value, InputIterator1>::type* = NULL,
													typename ft::enable_if<!ft::is_integral<InputIterator2>::value, InputIterator2>::type* = NULL) {
	while (first1 != last1) {
		if (*first1 > *first2 || first2 == last2)
			return false;
		else if (*first1 < *first2)
			return true;
		first1++;
		first2++;
	}
	return (first2 != last2);
};

template <class InputIterator1, class InputIterator2, class Compare>
bool	lexicographical_compare(InputIterator1 first1,
									InputIterator1 last1,
										InputIterator2 first2,
											InputIterator2 last2,
												Compare comp,
													typename ft::enable_if<!ft::is_integral<InputIterator1>::value, InputIterator1>::type* = NULL,
													typename ft::enable_if<!ft::is_integral<InputIterator2>::value, InputIterator2>::type* = NULL) {
	while (first1 != last1) {
		if (comp(*first1, *first2))
			return true;
		else if (comp(*first2, *first1))
			return false;
	}
	return (first2 != last2);
};

};


#endif