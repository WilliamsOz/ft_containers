/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:37:03 by wiozsert          #+#    #+#             */
/*   Updated: 2022/11/23 18:57:14 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP

#include "extern_library.hpp"
#include "iterator.hpp"

namespace ft{

template <class T>
class vectorIterator : public ft::iterator<random_access_iterator_tag, T>
{
	public :
	typedef typename ft::iterator<random_access_iterator_tag, T>::value_type		value_type;
	typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type	difference_type;
	typedef typename ft::iterator<random_access_iterator_tag, T>::pointer			pointer;
	typedef typename ft::iterator<random_access_iterator_tag, T>::reference			reference;
	typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;

	private:
	pointer	_ptr;

	public:
		vectorIterator( void ) : _ptr(){ };
		
		explicit vectorIterator( pointer ptr ) : _ptr(ptr ){ };
		
		vectorIterator( const vectorIterator &copy ) : _ptr(copy._ptr){ };
		
		~vectorIterator() { };


		vectorIterator & operator=( const vectorIterator &rhs ){
			if (this != &rhs)
				this->_ptr = rhs._ptr;
			return *this;
		};

		reference	operator*() const {
			return *this->_ptr;
		};

		pointer		operator->() {
			return this->_ptr;
		};

		vectorIterator<T>&	operator++( void ){  // ++_ptr
			++this->_ptr;
			return *this;
		};

		vectorIterator<T>&	operator--( void ){ // --_ptr
			--this->_ptr;
			return *this;
		};

		vectorIterator<T>	operator++( int ){// _ptr++
			ft::vectorIterator<T>	tmp(*this);

			++this->_ptr;
			return tmp;
		};

		vectorIterator<T>	operator--( int ){ // _ptr--
			ft::vectorIterator<T>	tmp(*this);

			--this->_ptr;
			return tmp;
		};

		bool				operator==( const vectorIterator &rhs ) const{
			return (rhs._ptr == this->_ptr);
		};

		bool				operator!=( const vectorIterator &rhs ) const{
			return (rhs._ptr != this->_ptr);
		};

		bool				operator<( const vectorIterator &rhs ) const{
			return (rhs._ptr < this->_ptr);
		};

		bool				operator<=( const vectorIterator &rhs ) const{
			return (rhs._ptr <= this->_ptr);
		};

		bool				operator>( const vectorIterator &rhs ) const{
			return (rhs._ptr > this->_ptr);
		};

		bool				operator>=( const vectorIterator &rhs ) const{
			return (rhs._ptr >= this->_ptr);
		};

};

};

#endif