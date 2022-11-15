/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:37:27 by wiozsert          #+#    #+#             */
/*   Updated: 2022/11/15 18:22:49 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "extern_library.hpp"

namespace ft {

template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class iterator
{
	public	:
	typedef T			value_type;
	typedef Distance	difference_type;
	// typedef Pointer		pointer;
	// typedef Reference	reference;
	typedef Category	iterator_category;

	iterator();
	iterator(Pointer ptr);
	iterator(iterator &copy);
	~iterator();

	Reference	operator*() const;
	Pointer		operator->();
	iterator&	operator++();
	iterator&	operator++( int );

	protected	:
	Pointer	_ptr;
};

}


	// struct input_iterator_tag {};
	// struct output_iterator_tag {};
	// struct forward_iterator_tag : public input_iterator_tag {};
	// struct bidirectional_iterator_tag : public forward_iterator_tag {};
	// struct random_access_iterator_tag : public bidirectional_iterator_tag {};


#include "iterator.tpp"

#endif