/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:18:46 by wiozsert          #+#    #+#             */
/*   Updated: 2022/11/15 18:22:16 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "extern_library.hpp"

namespace	ft
{

template<class T, class Alloc = std::allocator<T> >
class vector
{
	public :
	typedef	Alloc	allocator_type;
	typedef	T		value_type;
	typedef	size_t	size_type;

	typedef typename allocator_type::pointer			pointer;

	private :
		allocator_type	_alloc;
		size_t			_size;
		size_t			_capacity;
		pointer			_start;
		pointer			_end;

	public :

		explicit vector( const allocator_type& alloc = allocator_type() );
		explicit vector( size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type() );
		// explicit vector(  );
		// explicit vector(  );
		// explicit vector(  );
		~vector();
		pointer	begin(){ return this->_start; };
		// iterator<T>	begin();


};

}

#include "vector.tpp"

#endif