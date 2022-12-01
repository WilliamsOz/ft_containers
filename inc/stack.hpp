/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:18:29 by wiozsert          #+#    #+#             */
/*   Updated: 2022/12/01 16:12:36 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "extern_library.hpp"
#include "vector.hpp"

namespace ft {

template <class T, class Container = ft::vector<T> >
class stack{

	public :
	typedef T				value_type;
	typedef Container		container_type;
	typedef size_t			size_type;

	typedef typename Container::reference		reference;
	typedef typename Container::const_reference	const_reference;


	protected :
		container_type	container;

	public :
	
	//\-----------------------------------Constructors-----------------------------------\/
	
		/*___
		 @Default constructor, constructs a stack container adaptor object.
			*/
		explicit stack (const container_type& ctnr = container_type()): container(ctnr) {
			return ;
		};

		/*___
		 @Default destructor.
			*/
		virtual ~stack( void ){
			return ;
		}


	//\-----------------------------------Member functions-----------------------------------\/

	/*___
	 @Returns a reference to the top element in the stack.
		*/
	reference top( void ) {
		return (reference(this->container.back()));
	};

	/*___
	 @Returns a const_reference to the top element in the stack.
		*/
	const_reference top( void ) const {
		return (const_reference(this->container.back()));
	}

	/*___
	 @Checks if the underlying container has no elements.
		*/
	bool empty( void ) const {
		return (this->container.empty());
	};

	/*___
	 @Returns the number of elements in the underlying container.
		*/
	size_type size( void ) const {
		return (this->container.size());
	};

	/*___
	 @Inserts value at the top.
		*/
	void push( const value_type& value ) {
		this->container.push_back(value);
		return ;
	};

	/*___
	 @Removes the top element.
		*/
	void pop( void ) {
		this->container.pop_back();
		return ;
	};


	//\-----------------------------------Non-member function overloads-----------------------------------\/

	/*___
	 @Performs the == comparison operation between the vector containers lhs and rhs.
		*/
	template< class TB, class ContainerB >
	friend bool operator==( const stack<TB,ContainerB>& lhs, const stack<TB,ContainerB>& rhs ) {
		return (lhs.container == rhs.container);
	};

	/*___
	 @Performs the != comparison operation between the vector containers lhs and rhs.
		*/
	template< class TB, class ContainerB >
	friend bool operator!=( const stack<TB,ContainerB>& lhs, const stack<TB,ContainerB>& rhs ) {
		return (lhs.container != rhs.container);
	};

	/*___
	 @Performs the < comparison operation between the vector containers lhs and rhs.
		*/
	template< class TB, class ContainerB >
	friend bool operator<( const stack<TB,ContainerB>& lhs, const stack<TB,ContainerB>& rhs ) {
		return (lhs.container < rhs.container);
	};

	/*___
	 @Performs the <= comparison operation between the vector containers lhs and rhs.
		*/
	template< class TB, class ContainerB >
	friend bool operator<=( const stack<TB,ContainerB>& lhs, const stack<TB,ContainerB>& rhs ) {
		return (lhs.container <= rhs.container);
	};

	/*___
	 @Performs the > comparison operation between the vector containers lhs and rhs.
		*/
	template< class TB, class ContainerB >
	friend bool operator>( const stack<TB,ContainerB>& lhs, const stack<TB,ContainerB>& rhs ) {
		return (lhs.container > rhs.container);
	};

	/*___
	 @Performs the >= comparison operation between the vector containers lhs and rhs.
		*/
	template< class TB, class ContainerB >
	friend bool operator>=( const stack<TB,ContainerB>& lhs, const stack<TB,ContainerB>& rhs ) {
		return (lhs.container >= rhs.container);
	};

};

};

#endif