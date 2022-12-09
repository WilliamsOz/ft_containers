/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:56:05 by wiozsert          #+#    #+#             */
/*   Updated: 2022/12/09 15:18:52 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
#define RBT_HPP

#include "node.hpp"
#include "extern_library.hpp"

namespace ft
{

template<class T, class Compare, class Node = ft::Node<T>, class Alloc = std::allocator<Node> >
class rbt
{
	public :
	typedef T		value_type;
	typedef Node	node_type;
	typedef Compare	value_compare;
	typedef Alloc	allocator_type;

	typedef	typename	allocator_type::reference			reference;
	typedef	typename	allocator_type::const_reference		const_reference;
	typedef	typename	allocator_type::pointer				pointer;
	typedef	typename	allocator_type::const_pointer		const_pointer;
	typedef	typename	allocator_type::difference_type		difference_type;
	typedef	typename	allocator_type::size_type			size_type;


	//\-----------------------------------Constructors-----------------------------------\/


};


};


#endif