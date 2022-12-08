/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:24:00 by wiozsert          #+#    #+#             */
/*   Updated: 2022/12/07 15:40:53 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

#include "extern_library.hpp"
#define BLACK_NODE 0
#define RED_NODE 1

namespace ft
{

	template<class T>
	struct Node
	{
		typedef T		value_type;
		typedef size_t	size_type;

		value_type	data;
		size_type	color;
		Node		*parent;
		Node		*left;
		Node		*right;

		Node( void ) : data(), color(BLACK_NODE), parent(NULL), left(NULL), right(NULL) {
			return ;
		};

		Node(const Node &cpy) : data(cpy.data), color(cpy.color), parent(cpy.parent), left(cpy.left), right(cpy.right) {
			return ;
		};

		Node&	operator=( const Node &rhs ) {
			if (this != rhs) {
				this->data = rhs.data;
				this->color = rhs.color;
				this->parent = rhs.parent;
				this->left = rhs.left;
				this->right = rhs.right;
			}
			return *this;
		}

		~Node( void ) {
			return ;
		}

	};

};

#endif