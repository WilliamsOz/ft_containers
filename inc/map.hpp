/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:18:08 by wiozsert          #+#    #+#             */
/*   Updated: 2022/12/08 13:09:34 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "extern_library.hpp"
#include "pair.hpp"
#include "node.hpp"
#include "treeIterator.hpp"

#define BLACK_NODE 0
#define RED_NODE 1

namespace ft {

template<class Key, //clé
			class T, //value
				class Compare = std::less<Key>, // use to sort key
					class Allocator = std::allocator<ft::pair<const Key, T > > > // create a pair
class map {
	public :
	typedef Key											key_type;
	typedef T											mapped_type;
	typedef ft::pair<const key_type, mapped_type>		value_type;
	typedef ft::Node<value_type>						node_type;
	typedef size_t										size_type;
	typedef ptrdiff_t									difference_type;

	typedef Compare										key_compare;
	typedef Allocator									allocator_type;


	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_referecen	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;

	// typedef ft::mapIterator< >	iterator;
	//.... const_iterator, reverse_iterator, const_reverse_iterator, difference_type, size_type.


	//\-----------------------------------Nested class value_compare-----------------------------------\/

	/*___
	 @This function object compare object of type std::map::value by comparing of the first components
		of the pair.
		*/
	class value_compare : std::binary_function<value_type, value_type, bool>
	{
		// friend class map;

		protected:
		Compare	comp;
		value_compare( key_compare c) : comp(c) {};


	public:
		typedef bool		result_type;
		typedef value_type	first_argument;
		typedef value_type	second_argument;

		bool operator()( const value_type &x, const value_type &y ) const {
		return (comp(x.first, y.first));
	};

	};


	//\-----------------------------------Constructors-----------------------------------\/

	/*___
	 @Empty constructor.
		*/
	// map( void ) {
		
	// 	return ;
	// };

	/*___
	 @Empty constructor.
		*/
	explicit map( const key_compare& comp, const allocator_type& alloc = allocator_type() ) {
		(void)comp;
		(void)alloc;
		return ;
	};

	/*___
	 @Range constructor.
		*/
	template< class InputIt >
	map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ) {
		(void)first;
		(void)last;
		(void)comp;
		(void)alloc;
		return ;
	};

	/*___
	 @Copy constructor.
		*/
	map( const map& other ) {
		(void)other;
		return ;
	};


	//\-----------------------------------Assignement operator-----------------------------------\/

	/*___
	 @Copy assignment operator.
		*/
	map& operator=( const map& other ) {
		(void)other;
		return *this;
	};


	//\-----------------------------------Allocator Function-----------------------------------\/

	/*___
	 @Returns the allocator associated with the container.
		*/
	allocator_type get_allocator( void ) const {
		return this->_alloc;
	};


	//\-----------------------------------Destructor-----------------------------------\/

	/*___
	 @
		*/
	~map( void ) {
		return ;
	};


	//\-----------------------------------Element Access-----------------------------------\/

	/*___
	 @Returns a reference to the mapped value of the element with key equivalent to key.
	 @If no such element exists, an exception of type std::out_of_range is thrown.
		*/
	// T& at( const Key &key ) {  };

	/*___
	 @Returns a const_reference to the mapped value of the element with key equivalent to key.
	 @If no such element exists, an exception of type std::out_of_range is thrown.
		*/
	// const T& at( const Key &key ) const {  };

	/*___
	 @Returns a reference to the value that is mapped to a key equivalent to key,
		performing an insertion if such key does not already exist.
		*/
	// T& operator[]( const Key &key ) {  };

	/*___
	 @
		*/


	/*___
	 @
		*/


	/*___
	 @
		*/


	/*___
	 @
		*/


	/*___
	 @
		*/


	/*___
	 @
		*/


	/*___
	 @
		*/


	/*___
	 @
		*/


	/*___
	 @
		*/


	/*___
	 @
		*/





	private :
		allocator_type	_alloc;
};

};

//red black visualization

#endif