/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treeIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:13:07 by wiozsert          #+#    #+#             */
/*   Updated: 2022/12/05 12:21:20 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREEITERATOR_HPP
#define TREEITERATOR_HPP

#include "iterator.hpp"

namespace ft
{

template<class T, class Node>
class treeIterator : public ft::iterator<bidirectional_iterator_tag, T>
{
	public:
	typedef T			value_type;
	typedef typename	ft::iterator<bidirectional_iterator_tag, value_type>::pointer			pointer;
	typedef typename	ft::iterator<bidirectional_iterator_tag, value_type>::reference			reference;
	typedef typename	ft::iterator<bidirectional_iterator_tag, value_type>::difference_type	difference_type;
	typedef typename	ft::iterator<bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;

	typedef	Node	node_type;
	typedef Node*	node_pointer;

	private :
	node_pointer	_root;
	node_pointer	_node;
	// node_pointer	null;
		

};

};

#endif