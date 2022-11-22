/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:18:46 by wiozsert          #+#    #+#             */
/*   Updated: 2022/11/22 15:52:32 by wiozsert         ###   ########.fr       */
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
	typedef typename allocator_type::reference			reference;

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
			std::cout << "Default Constructor" << std::endl;
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
		// template<class InputIterator>
		// vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){
		// 	(void)first;
		// 	(void)last;
		// 	(void)alloc;
		// 	std::cout << "Range Constructor" << std::endl;
		// 	return ;
		// };

		/**
		 * Copy Constructor
		 **/
		// vector (const vector& x){
			
		// };

		/**
		 *	Default Destructor
		 *	This destroys all container elements, and deallocates all the storage capacity allocated by the vector using its allocator.
		 **/
		~vector(){

			return ;
		};


		/**
		 * Iterators
		 **/
		pointer	begin( void ){ return (this->_start); };
		pointer	end( void ){ return (this->_end); };
		// rbegin();
		// rend();
		// cbegin();
		// cend();
		// crbegin();
		// crend();


		/**
		 * Capacity
		 **/
		size_type	size() const { return this->_end - this->_start; };
		size_type	max_size() const { return allocator_type().max_size(); };
		// void		resize(size_type n, value_type val = value_type());
		size_type	capacity() const { return this->_capacity; };
		bool		empty() const { return (this->size() == 0 ? true : false); };
		// void		reserve( size_type n );
		void		shrink_to_fit() {  };


		/**
		 * Capacity
		 **/
		value_type&	operator[]( size_t index ) { return this->_start[index]; };
		// reference	at( size_type n );
		// const_reference at( size_type n ) const;
		// reference	front();
		// const_reference	front() const;
		// reference back();
		// const_reference back() const;
		// value_type* data() noexcept;
		// const value_type* data() const noexcept;


		/**
		 * Modifiers
		 **/
		// template <class InputIterator>
		// void assign (InputIterator first, InputIterator last);

		// void assign (size_type n, const value_type& val);
		// void push_back (const value_type& val);
		// void pop_back();
		// iterator insert (iterator position, const value_type& val);
		// void insert (iterator position, size_type n, const value_type& val);

		// template <class InputIterator>
		// void insert (iterator position, InputIterator first, InputIterator last);

		// iterator erase (iterator position);
		// iterator erase (iterator first, iterator last);
		// void swap (vector& x);
		// void clear();

		// template <class... Args>
		// iterator emplace (const_iterator position, Args&&... args);

		// template <class... Args>
		// void emplace_back (Args&&... args);

		// allocator_type get_allocator() const;

};

};

#endif