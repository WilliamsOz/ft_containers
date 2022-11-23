/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:56:40 by wiozsert          #+#    #+#             */
/*   Updated: 2022/11/23 12:26:22 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

#include "extern_library.hpp"

namespace ft{

// template<class T, T v>
// struct integral_constant{
// 	static const T	value;
// 	typedef T	value_type;
// 	typedef integral_constant<T, v>	type;

// 	operator T(){ return v; }
// };

// typedef integral_constant<bool, false>	false_type;
// typedef integral_constant<bool, true>	true_type;

template<class T>
struct is_integral : std::false_type {};

template<>
struct is_integral<bool>: std::true_type {};

template<>
struct is_integral<char>: std::true_type {};

template<>
struct is_integral<char16_t>: std::true_type {};

template<>
struct is_integral<char32_t>: std::true_type {};

template<>
struct is_integral<wchar_t>: std::true_type {};

template<>
struct is_integral<signed char>: std::true_type {};

template<>
struct is_integral<short int>: std::true_type {};

template<>
struct is_integral<int>: std::true_type {};

template<>
struct is_integral<long int>: std::true_type {};

template<>
struct is_integral<long long int>: std::true_type {};

template<>
struct is_integral<unsigned char>: std::true_type {};

template<>
struct is_integral<unsigned short int>: std::true_type {};

template<>
struct is_integral<unsigned int>: std::true_type {};

template<>
struct is_integral<unsigned long int>: std::true_type {};

template<>
struct is_integral<unsigned long long int>: std::true_type {};

};

#endif