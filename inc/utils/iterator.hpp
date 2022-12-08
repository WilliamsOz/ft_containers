/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:37:27 by wiozsert          #+#    #+#             */
/*   Updated: 2022/12/08 12:41:52 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "extern_library.hpp"

namespace ft{

	//empty class types used to indicate iterator categories
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};


//\-----------------------------------iterator-----------------------------------\/
template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
struct iterator
{
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
};

//\-----------------------------------iterator_traits-----------------------------------\/
template< class Iterator >
struct iterator_traits
{
	typedef typename	Iterator::difference_type	difference_type;
	typedef typename	Iterator::value_type		value_type;
	typedef typename	Iterator::pointer			pointer;
	typedef typename	Iterator::reference			reference;
	typedef typename	Iterator::iterator_category	iterator_category;
};

template< class T >
struct iterator_traits<T*>
{
	typedef	ptrdiff_t					difference_type;
	typedef	T							value_type;
	typedef	T*							pointer;
	typedef	T&							reference;
	typedef	random_access_iterator_tag	iterator_category;
};

template< class T >
struct iterator_traits<const T*>
{
	typedef	ptrdiff_t					difference_type;
	typedef	T							value_type;
	typedef	T*							pointer;
	typedef	T&							reference;
	typedef	random_access_iterator_tag	iterator_category;
};


//\-----------------------------------reverse_iterator-----------------------------------\/
template <class Iterator>
class reverse_iterator
{
	public :
	typedef	Iterator													iterator_type;
	typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
	typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
	typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
	typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
	typedef typename ft::iterator_traits<Iterator>::reference			reference;

	private :
	iterator_type	_it;

	public :

	//\-----------------------------------Constructors-----------------------------------\/

		/*\___
		 *	default constructor -> Constructs a reverse iterator that points to no object.
		\*/
		reverse_iterator( void ) : _it(){  };

		/*\___
		 * initalization constructor -> Constructs a reverse iterator from some original iterator it.
		\*/
		explicit reverse_iterator (iterator_type it) : _it(it){  };

		/*\___
		 * copy / type-cast constructor -> Constructs a reverse iterator from some other reverse iterator.
		\*/
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter>& rev_it) : _it(rev_it.base()){  };


	//\-----------------------------------Destructor-----------------------------------\/

		/*\___
		 * default destructor -> to keep coplien form.
		\*/
		virtual ~reverse_iterator( void ) {  };


	//\-----------------------------------Member functions-----------------------------------\/

		/*\___
		 * @assignement constructor.
		\*/
		reverse_iterator<Iterator>&	operator=( const reverse_iterator<Iterator> &rhs ){
			if (this != &rhs)
				this->_it = rhs._it;
			return *this;
		};

		/*\___
		 * @Returns a copy of the base iterator.
		\*/
		iterator_type	base() const{
			return this->_it;
		};

		/*\___
		 * @dereference iterator.
		 * @Returns a reference to the element pointed to by the iterator.
		 * @Internally, the function decreases a copy of its base iterator
			and returns the result of dereferencing it.
		\*/
		reference operator*() const{
			iterator_type	tmp = this->_it;

			return (*(--tmp));
		};

		/*\___
		 * @Addition operator.
		 * @Returns a reverse iterator pointing to the element
			located n positions away from the element the iterator currently points to.
		\*/
		reverse_iterator operator+ (difference_type n) const{
			return (reverse_iterator(this->_it - n));
		};

		/*\___
		 * @Pre-Increment iterator position : ++_it.
		 * @Decrements the base iterator kept by the object.
		\*/
		reverse_iterator& operator++(){
			--this->_it;
			return *this;
		};

		/*\___
		 * @Post-Increment iterator position : _it++.
		\*/
		reverse_iterator& operator++( int ){
			reverse_iterator	tmp(*this);

			--this->_it;
			return tmp;
		};

		/*\___
		 * @Advance iterator.
		\*/
		reverse_iterator& operator+= (difference_type n){
			this->_it -= n;
			return *this;
		};

		/*\___
		 * @Subtraction operator.
		\*/
		reverse_iterator operator- (difference_type n) const{
			return (reverse_iterator(this->_it + n));
		};

		/*\___
		 * @Pre-Decrement iterator position : ++_it.
		 * @increments the base iterator kept by the object (as if applying operator++ to it).
		\*/
		reverse_iterator& operator--(){
			++this->_it;
			return *this;
		};

		/*\___
		 * @Post-Decrement iterator position : _it++.
		\*/
		reverse_iterator  operator--( int ){
			reverse_iterator	tmp(*this);

			++this->_it;
			return tmp;
		};

		/*\___
		 * @Retrocede iterator.
		 * @Descreases the reverse_iterator by n element positions.
		\*/
		reverse_iterator& operator-= (difference_type n){
			this->_it += n;
			return *this;
		};

		/*\___
		 * Dereference iterator.
		\*/
		pointer operator->() const{
			return &(operator*());
		};

		/*\___
		 * Dereference iterator with offset.
		\*/
		reference operator[] (difference_type n) const{
			return (this->_it[-n -1]);
		};


	//\-----------------------------------Non-member functions overloads-----------------------------------\/

		/*\___
		 * Relational operators for reverse_iterator.
		 2 friend ?
		\*/
		template <class ROIterator>
		friend bool operator==(const reverse_iterator<ROIterator>& lhs, const reverse_iterator<ROIterator>& rhs){
			return (lhs.base() == rhs.base());
		};

		template <class ROIterator>
		friend bool operator!=(const reverse_iterator<ROIterator>& lhs, const reverse_iterator<ROIterator>& rhs){
			return (lhs.base() = rhs.base());
		};

		template <class ROIterator>
		friend bool operator<(const reverse_iterator<ROIterator>& lhs, const reverse_iterator<ROIterator>& rhs){
			return (lhs.base() > rhs.base());
		};

		template <class ROIterator>
		friend bool operator<=(const reverse_iterator<ROIterator>& lhs, const reverse_iterator<ROIterator>& rhs){
			return (lhs.base() >= rhs.base());
		};

		template <class ROIterator>
		friend bool operator>(const reverse_iterator<ROIterator>& lhs, const reverse_iterator<ROIterator>& rhs){
			return (lhs.base() < rhs.base());
		};

		template <class ROIterator>
		friend bool operator>=(const reverse_iterator<ROIterator>& lhs, const reverse_iterator<ROIterator>& rhs){
			return (lhs.base() <= rhs.base());
		};

		/*\___
		 * Addition operator.
		\*/
		template <class ROIterator>
		friend reverse_iterator<ROIterator> operator+(typename reverse_iterator<ROIterator>::difference_type n, const reverse_iterator<ROIterator>& rev_it){
			return (rev_it + n);
		};

		/*\___
		 * @Subtraction operator.
		\*/
		template <class ROIterator>
		friend typename reverse_iterator<ROIterator>::difference_type operator-(const reverse_iterator<ROIterator>& lhs, const reverse_iterator<ROIterator>& rhs){
			return (rhs.base() - lhs.base());
		};
};

};

#endif