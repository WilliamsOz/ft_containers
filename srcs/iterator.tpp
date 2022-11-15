/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:24:27 by wiozsert          #+#    #+#             */
/*   Updated: 2022/11/15 18:22:48 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterator.hpp"

template <class Category, class T, class Distance, class Pointer, class Reference>
ft::iterator<Category, T, Distance, Pointer, Reference>::iterator( void )
{
	return ;
}

template <class Category, class T, class Distance, class Pointer, class Reference>
ft::iterator<Category, T, Distance, Pointer, Reference>::iterator( Pointer ptr )
{
	this->_ptr = ptr;
	return ;
}

template <class Category, class T, class Distance, class Pointer, class Reference>
ft::iterator<Category, T, Distance, Pointer, Reference>::iterator( ft::iterator<Category, T, Distance, Pointer, Reference> &copy )
{
	if (*this != copy)
		*this = copy;
	return ;
}


template <class Category, class T, class Distance, class Pointer, class Reference>
ft::iterator<Category, T, Distance, Pointer, Reference>::~iterator( void )
{
	return ;
}

template <class Category, class T, class Distance, class Pointer, class Reference>
Reference ft::iterator<Category, T, Distance, Pointer, Reference>::operator*( void ) const
{
	return *this->_ptr;
}

template <class Category, class T, class Distance, class Pointer, class Reference>
Pointer ft::iterator<Category, T, Distance, Pointer, Reference>::operator->( void )
{
	return this->_ptr;
}

template <class Category, class T, class Distance, class Pointer, class Reference>
ft::iterator<Category, T, Distance, Pointer, Reference>& ft::iterator<Category, T, Distance, Pointer, Reference>::operator++( void )
{
	this->_ptr++;
	return *this;
}

// template <class Category, class T, class Distance, class Pointer, class Reference>
// ft::iterator<Category, T, Distance, Pointer, Reference>& ft::iterator<Category, T, Distance, Pointer, Reference>::operator++( int )
// {
// 	ft::iterator<class Category, class T>	tmp = *this;

// 	++(*this);
// 	return tmp;
// }
