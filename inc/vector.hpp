/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:18:46 by wiozsert          #+#    #+#             */
/*   Updated: 2022/11/25 19:10:54 by wiozsert         ###   ########.fr       */
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
	typedef typename allocator_type::difference_type		difference_type;
	typedef typename allocator_type::size_type				size_type;
	typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
	

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

	//\-----------------------------------Constructors-----------------------------------\/

		/*___
		 @Empty Container constructor (default constructor) -> Constructs an empty container with no elements.
			*/
		explicit vector( const allocator_type& alloc = allocator_type() ){
			std::cout << "Default Constructor" << std::endl;
			this->_alloc = alloc;
			this->_size = 0;
			this->_capacity = 0;
			this->_start = NULL;
			this->_end = NULL;
			return ;
		};


		/*___
		 @Fill Constructor -> Constructs a container with n elements.
			Each element is a copy of val.
			*/
		explicit vector( size_type n,
							const value_type& val = value_type(),
								const allocator_type& alloc = allocator_type() ){
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

		/*___
		 @Range Constructor -> Constructs a container with as many elements as the range [first,last),
			with each element constructed from its corresponding element in that range, in the same order.
			*/
		template<class InputIterator>
		vector(InputIterator first,
				InputIterator last,
					const allocator_type& alloc = allocator_type(),
						typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL){
			(void)first;
			(void)last;
			this->_alloc = alloc;
			// this->_size = ft::distance_between_iterators(first, last);
			this->_capacity = this->_size;
			this->_start = this->_alloc.allocate(this->_capacity);
			this->_end = this->_start;
			// while (first != last)
			// {
			// 	this->_alloc.construct(this->_end, *first);
			// 	this->_end++;
			// 	first++;
			// }
			return ;
		};

		/*___
		 @Copy Constructor -> Constructs a container with a copy of each of the elements in x, in the same order
			*/
		vector (const vector &src){
			this->_size = src.size();
			this->_capacity = this->_size;
			this->_start = this->_alloc.allocate(this->_size);
			this->_end = this->_start;
			for (size_t i = 0 ; i < this->_size ; i++)
			{
				this->_alloc.construct(this->_end, *this->_end);
				this->_end++;
			}
		};


	//\-----------------------------------Destructor-----------------------------------\/

		/*___
		 @Default Destructor
		 @This destroys all container elements, and deallocates all the storage capacity allocated
			by the vector using its allocator.
			*/
		~vector(){
			this->clear();
			this->_alloc.deallocate(this->_start, this->_capacity);
			return ;
		};


		//operator= https://en.cppreference.com/w/cpp/container/vector/operator%3D

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last){
			(void)first;
			(void)last;
			return ;
		};

		void assign (size_type n, const value_type& val){
			(void)n;
			(void)val;
			return ;
		};

		allocator_type get_allocator( void ) const{
			return this->_alloc;
		};

	//\-----------------------------------Element access-----------------------------------\/

		// reference	at( size_type n );

		// const_reference at( size_type n ) const{
		// 	(void)n;
		// };

		value_type&	operator[]( size_t index ) {
			return this->_start[index];
		};

		// reference	front();

		// const_reference	front() const;

		// reference back();

		// const_reference back() const;

		// value_type* data() noexcept;

		// const value_type* data() const noexcept;

	//\-----------------------------------Iterators-----------------------------------\/

		iterator				begin( void ){
			return (iterator(this->_start));
		};

		const_iterator			begin( void ) const{
			return (const_iterator(this->_start));
		};

		reverse_iterator		rbegin( void ){
			return (reverse_iterator(this->end()));
		};

		const_reverse_iterator	rbegin( void ) const{
			return (const_reverse_iterator(this->end()));
		};

		iterator				end( void ){
			return (iterator(this->_end));
		};

		const_iterator			end( void ) const{
			return (const_iterator(this->_end));
		};

		reverse_iterator 		rend(){
			return (reverse_iterator(this->begin()));
		};

		const_reverse_iterator	rend() const{
			return (const_reverse_iterator(this->begin()));
		};


	//\-----------------------------------Capacity-----------------------------------\/

		bool		empty() const {
			return (this->size() == 0 ? true : false);
		};

		size_type	size() const {
			return this->_end - this->_start;
		};

		size_type	max_size() const {
			return allocator_type().max_size();
		};

		void		reserve( size_type n ){
			(void)n;
		};

		size_type	capacity() const {
			return this->_capacity;
		};


	//\-----------------------------------Modifiers-----------------------------------\/

		void	clear( void ){
			for (size_type	i = 0 ; i < this->_size ; i++)
			{
				this->_end--;
				this->_alloc.destroy(this->_end);
			}
			return ;
		};

		iterator	insert (iterator position, const value_type& val){;
			(void)position;
			(void)val;
			return ;
		};

		template<class InputIterator>
		void	insert(iterator position, InputIterator first, InputIterator last){
			(void)position;
			(void)first;
			(void)last;
			return ;
		};

		iterator	erase(iterator position){
			(void)position;
		};

		// iterator erase (iterator first, iterator last){
		// 	(void)first;
		// 	(void)last;
		// };

		void push_back (const value_type& val){
			(void)val;
			return ;
		};

		void pop_back( void ){
			return ;
		};

		void		resize(size_type n, value_type val = value_type()){
			(void)n;
			(void)val;
			return ;
		};

		void swap (vector& x){
			(void)x;
			return ;
		};
};

};

#endif