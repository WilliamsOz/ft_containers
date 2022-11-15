/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:25:06 by wiozsert          #+#    #+#             */
/*   Updated: 2022/11/15 14:41:04 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector.hpp"

template<class T, class Alloc >
ft::vector<T, Alloc>::vector( const allocator_type &alloc )
{
	this->_alloc = alloc;
	this->_size = 0;
	this->_capacity = 0;
	this->_start = NULL;
	this->_end = NULL;
	return ;
}

template<class T, class Alloc >
ft::vector<T, Alloc>::~vector( void )
//This destroys all container elements, and deallocates all the storage capacity allocated by the vector using its allocator.
{
	return ;
}

template<class T, class Alloc >
ft::vector<T, Alloc>::vector( size_type n, const value_type &val, const allocator_type &alloc )
{
	this->_alloc = alloc;
	this->_size = n;
	this->_capacity = n;
	this->_start = this->_alloc.allocate(n);
	this->_end = this->_start;
	for (size_t i = 0 ; i < n ; i++)
	{
		this->_alloc.construct(this->_end, val);
		this->_end++;
	}
	return ;
}

// template<class T, class Alloc >
// iterator ft::vector<T, Alloc>::begin( void )
// {
// 	return (iterator(this->_start));
// }