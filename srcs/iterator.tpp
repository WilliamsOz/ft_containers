/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:24:27 by wiozsert          #+#    #+#             */
/*   Updated: 2022/11/15 14:40:39 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iterator.hpp"

template <class Category, class T, class Distance, class Pointer, class Reference>
ft::iterator<Category, T, Distance, Pointer, Reference>::iterator( void )
{
	return ;
}

template <class Category, class T, class Distance, class Pointer, class Reference>
ft::iterator<Category, T, Distance, Pointer, Reference>::iterator( pointer ptr )
{
	this->_ptr = ptr;
	return ;
}

template <class Category, class T, class Distance, class Pointer, class Reference>
ft::iterator<Category, T, Distance, Pointer, Reference>::~iterator( void )
{
	return ;
}

// template <class Category, class T, class Distance, class Pointer, class Reference>
// ft::iterator::reference ft::iterator<Category, T, Distance, Pointer, Reference>::operator*( void ) const
// {
// 	return this->*_ptr;
// }

// template <class Category, class T, class Distance, class Pointer, class Reference>
// typename ft::iterator<Category, T>::pointer ft::iterator<Category, T, Distance, Pointer, Reference>::operator->( void )
// {
// 	return this->_ptr;
// }

// template <class Category, class T, class Distance, class Pointer, class Reference>
// iterator& ft::iterator<Category, T, Distance, Pointer, Reference>::operator++( void )
// {
// 	this->_ptr++;
// 	return *this;
// }

// template <class Category, class T, class Distance, class Pointer, class Reference>
// iterator& ft::iterator<Category, T, Distance, Pointer, Reference>::operator++( int )
// {
// 	ft::iterator<class Category, class T>	tmp = *this;

// 	++(*this);
// 	return tmp;
// }
