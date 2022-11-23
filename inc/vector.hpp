/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:18:46 by wiozsert          #+#    #+#             */
/*   Updated: 2022/11/23 19:39:22 by wiozsert         ###   ########.fr       */
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
	// typedef	size_t	size_type;

	typedef typename allocator_type::pointer				pointer;//T*
	typedef typename allocator_type::reference				reference;//T&
	typedef typename allocator_type::const_pointer			const_pointer;//const T*
	typedef typename allocator_type::const_reference		const_reference;//const T&
	typedef typename ft::vectorIterator<value_type>			iterator;
	typedef typename ft::vectorIterator<const value_type>	const_iterator;
	typedef typename allocator_type::difference_type		difference_type;//
	typedef typename allocator_type::size_type				size_type;
	
	

	private :
		allocator_type	_alloc;
						/*Allocator Object*/
		size_t			_size;
						/*Number of elements in the container*/
		size_t			_capacity;
						/*Number total of element that the containers can hold*/
		pointer			_start;
						/*Pointer to the start of the container*/
		pointer			_end;
						/*Pointer to the end of the container*/

	public :

		/*\___
		 * Empty Container constructor (default constructor) -> Constructs an empty container with no elements.
		 * @allocator_type : Allocator object.
		\*/
		explicit vector( const allocator_type& alloc = allocator_type() ){
			std::cout << "Default Constructor" << std::endl;
			this->_alloc = alloc;
			this->_size = 0;
			this->_capacity = 0;
			this->_start = NULL;
			this->_end = NULL;
			return ;
		};


		/*\___
		 * Fill Constructor -> Constructs a container with n elements.
			Each element is a copy of val.
		 * @size_type : Number of elements in the container at construction. 
		 * @value_type : Value to fill the container with.
			Each n elements will be initialized to a copy of this value.
		 * @allocator_type : Allocator object.
		\*/
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

		/*\___
		 * Range Constructor -> Constructs a container with as many elements as the range [first,last),
			with each element constructed from its corresponding element in that range, in the same order.
		 * 
		\*/
		// template<class InputIterator>
		// vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){
		// 	(void)first;
		// 	(void)last;
		// 	(void)alloc;
		// 	std::cout << "Range Constructor" << std::endl;
		// 	return ;
		// };

		/*\___
		 * Copy Constructor
		\*/
		// vector (const vector& x){
			
		// };

		/*\___
		 *	Default Destructor
		 *	This destroys all container elements, and deallocates all the storage capacity allocated
			by the vector using its allocator.
		\*/
		~vector(){
			for (size_type	i = 0 ; i < this->_size ; i++)
			{
				this->_end--;
				this->_alloc.destroy(this->_end);
			}
			this->_alloc.deallocate(this->_start, this->_capacity);
			return ;
		};

		/*\
		 * Iterators member functions
		 */
		iterator	begin( void ){
			return (iterator(this->_start));
		};

		iterator	end( void ){
			return (iterator(this->_end));
		};

		//TO DO
		// reverse_iterator rbegin(){
			
		// };

		//TO DO
		// reverse_iterator rend(){
			
		// };

		const_iterator	cbegin() const{
			const_pointer	constPTR = this->_start;
			return (constPTR);
		};

		const_iterator	cend(){
			const_pointer constPTR = this->_end;
			return (constPTR);
		};

		// const_reverse_iterator	crbegin(){

		// };

		// const_reverse_iterator	crend(){
			
		// };
/*---------------------------------------------------------------------------------------------------------------------*/
		/*\
		 * Capacity member functions
		 */
		size_type	size() const {
			return this->_end - this->_start;
		};

		size_type	max_size() const {
			return allocator_type().max_size();
		};

		//TO DO
		void		resize(size_type n, value_type val = value_type()){
			(void)n;
			(void)val;
		};

		size_type	capacity() const {
			return this->_capacity;
		};

		bool		empty() const {
			return (this->size() == 0 ? true : false);
		};

		//TO DO
		void		reserve( size_type n ){
			(void)n;
		};

		//TO DO
		void		shrink_to_fit() {
			
		};

/*---------------------------------------------------------------------------------------------------------------------*/

		/*\
		 * Element Access member functions
		 */
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