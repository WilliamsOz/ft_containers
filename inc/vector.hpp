/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:18:46 by wiozsert          #+#    #+#             */
/*   Updated: 2022/11/22 14:08:13 by wiozsert         ###   ########.fr       */
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
	typedef	T		value_type;
	typedef	Alloc	allocator_type;
	typedef	size_t	size_type;

	typedef typename allocator_type::pointer			pointer;

	private :
		allocator_type	_alloc;
		size_t			_size;
		size_t			_capacity;
		pointer			_start;
		pointer			_end;

	public :

		/**
		 * Default Constructor
		 **/
		explicit vector( const allocator_type& alloc = allocator_type() ){
			this->_alloc = alloc;
			this->_size = 0;
			this->_capacity = 0;
			this->_start = NULL;
			this->_end = NULL;
			return ;
		};


		/**
		 * Fill Constructor
		 **/
		explicit vector( size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type() ){
			std::cout << "Fill Constructor" << std::endl;
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
		};

		/**
		 * Range Constructor
		 **/
		template<class InputIterator> vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){
			(void)first;
			(void)last;
			(void)alloc;
			std::cout << "Range Constructor" << std::endl;
			return ;
		};


		/**
		 *	Default Destructor
		 *	This destroys all container elements, and deallocates all the storage capacity allocated by the vector using its allocator.
		 **/

		~vector(){

			return ;
		};

		pointer	begin( void ){ return (this->_start); };
		pointer	end( void ){ return (this->_end); };
		value_type&	operator[]( size_t index ) { return this->_start[index]; };
};

};

#endif