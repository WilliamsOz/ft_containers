/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_input_iterator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:55:55 by wiozsert          #+#    #+#             */
/*   Updated: 2022/11/24 13:34:57 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INPUT_ITERATOR_HPP
#define IS_INPUT_ITERATOR_HPP

#include "extern_library.hpp"
#include "containers.hpp"

namespace ft{

template<class T>
struct is_input_iterator : std::false_type {};

template<>
struct is_input_iterator<ft::input_iterator_tag>: std::true_type {};

};

#endif