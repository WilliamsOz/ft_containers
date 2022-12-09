/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:18:46 by wiozsert          #+#    #+#             */
/*   Updated: 2022/12/10 00:40:56 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "extern_library.hpp"
#include "iterator.hpp"
#include "lexicographical_compare.hpp"
#include "equal.hpp"
#include "is_integral.hpp"
#include "enable_if.hpp"
#include "vectorIterator.hpp"

namespace	ft
{

template<class T, class Alloc = std::allocator<T> >
class vector
{
	public :
	typedef	T		value_type;
	typedef	Alloc	allocator_type;

	typedef typename allocator_type::pointer				pointer;//T*
	typedef typename allocator_type::reference				reference;//T&
	typedef typename allocator_type::const_pointer			const_pointer;//const T*
	typedef typename allocator_type::const_reference		const_reference;//const T&
	typedef typename ft::vectorIterator<value_type>			iterator;//value_type*
	typedef typename ft::vectorIterator<const value_type>	const_iterator;//const value_type*
	typedef typename allocator_type::difference_type		difference_type;//ptrdiff_t
	typedef typename allocator_type::size_type				size_type;//size_t
	typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;


	private :
		allocator_type	_alloc;
						/*Allocator Object*/
		size_t			_size;
						/*Number of elements inside the container*/
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
		explicit vector( const allocator_type& alloc = allocator_type() ) {
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
								const allocator_type& alloc = allocator_type() ) {
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
						typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {
			InputIterator	tmp = first;

			this->_size = 0;
			for (; tmp != last ; tmp++)
				this->_size++;
			this->_alloc = alloc;
			this->_capacity = this->_size;
			this->_start = this->_alloc.allocate(this->_capacity);
			this->_end = this->_start;
			for (; first != last ; first++)
			{
				this->_alloc.construct(this->_end, *first);
				this->_end++;
			}
			return ;
		};

		/*___
		 @Copy Constructor -> Constructs a container with a copy of each of the elements in x, in the same order.
			*/
		vector (const vector &copy) {
			this->_size = copy.size();
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
		 @Default Destructor.
		 @This destroys all container elements, and deallocates all the storage capacity allocated
			by the vector using its allocator.
			*/
		~vector() {
			this->clear();
			this->_alloc.deallocate(this->_start, this->_capacity);
			return ;
		};

		/*___
		 @Copy assignment operator -> Assigns new contents to the container,
			replacing its current contents, and modifying its size accordingly.
		 @Copies all the elements from rhs into the container.
		 @The container preserves its current allocator,
			which is used to allocate storage in case of reallocation
			*/
		vector& operator=( const vector &rhs ) {
			if (*this != rhs)
			{
				this->clear();
				if (rhs.size() > this->size())
					this->reserve(rhs.size());
				for (pointer tmp = rhs._start ; tmp != rhs._end ; tmp++)
					this->_alloc.construct(this->_end++, *tmp);
				return *this;
			}
		};

		/*___
		 @Range version.
		 @Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
		 @The new contents are elements constructed from each of the elements in the range between first and last,
			in the same order.
			*/
		template <class InputIterator>
		void assign (InputIterator first,
						InputIterator last,
							typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {
			size_type	nbOfElement = 0;

			for (InputIterator tmp = first ; tmp != last ; tmp++)
				nbOfElement++;
			this->clear();
			this->reserve(nbOfElement);
			for (; first != last ; first++)
				this->_alloc.construct(this->_end++, *first);
			return ;
		};

		/*___
		 @Fill Version.
		 @Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
		 @The new contents are count elements, each initialized to a copy of value.
			*/
		void assign (size_type count, const value_type& value) {
			this->clear();
			this->reserve(count);
			while (count > 0)
			{
				this->_alloc.construct(this->_end, value);
				count--;
				this->_end++;
			}
			return ;
		};

		/*___
		 @Returns a copy of the allocator object associated with the vector.
			*/
		allocator_type	get_allocator( void ) const {
			return this->_alloc;
		};

	//\-----------------------------------Element access-----------------------------------\/

		/*___
		 @Returns a reference to the element at position n in the vector.
		 @The function automatically checks whether n is within the bounds of valid elements in the vector
			*/
		reference	at( size_type n ) {
			if (n >= this->size()){
				throw std::out_of_range("vector");
			}
			else
				return this->_start[n];
		};

		/*___
		 @Returns a const_reference to the element at position n in the vector.
		 @The function automatically checks whether n is within the bounds of valid elements in the vector
			*/
		const_reference	at( size_type n ) const{
			if (n >= this->size()){
				throw std::out_of_range("vector");
			}
			else
				return this->_start[n];
		};

		/*___
		 @Returns a reference to the element at position n in the vector container.
			*/
		value_type&	operator[]( size_t index ) {
			return this->_start[index];
		};

		/*___
		 @Returns a reference to the first element in the vector.
			*/
		reference	front( void ) {
			return *(this->_start);
		};

		/*___
		 @Returns a const_reference to the first element in the vector.
			*/
		const_reference	front( void ) const {
			return *(this->_start);
		};

		/*___
		 @Returns a reference to the last element in the vector.
			*/
		reference	back( void ) {
			return *(this->_end - 1);
		};

		/*___
		 @Returns a const_reference to the last element in the vector.
			*/
		const_reference	back( void ) const {
			return *(this->_end - 1);
		};

	//\-----------------------------------Iterators-----------------------------------\/

		/*___
		 @Returns an iterator pointing to the first element in the vector.
			*/
		iterator	begin( void ) {
			return (iterator(this->_start));
		};

		/*___
		 @Returns a const_iterator pointing to the first element in the vector.
			*/
		const_iterator	begin( void ) const {
			return (const_iterator(this->_start));
		};

		/*___
		 @Returns a reverse_iterator pointing to the last element in the vector.
			*/
		reverse_iterator	rbegin( void ) {
			return (reverse_iterator(this->end()));
		};

		/*___
		 @Returns a const_reverse_iterator pointing to the last element in the vector
			*/
		const_reverse_iterator	rbegin( void ) const {
			return (const_reverse_iterator(this->end()));
		};

		/*___
		 @Returns an iterator referring to the past-the-end element in the vector container.
			*/
		iterator	end( void ) {
			return (iterator(this->_end));
		};

		/*___
		 @Returns a const_iterator referring to the past-the-end element in the vector container.
			*/
		const_iterator	end( void ) const {
			return (const_iterator(this->_end));
		};

		/*___
		 @Returns a reverse_iterator pointing to the first element in the vector
			*/
		reverse_iterator	rend() {
			return (reverse_iterator(this->begin()));
		};

		/*___
		 @Returns a const_reverse_iterator pointing to the first element in the vector
			*/
		const_reverse_iterator	rend() const {
			return (const_reverse_iterator(this->begin()));
		};


	//\-----------------------------------Capacity-----------------------------------\/

		/*___
		 @Returns true if current vector is empty, false otherwise.
			*/
		bool		empty() const {
			return (this->size() == 0 ? true : false);
		};

		/*___
		 @Returns the number of elements in the vector.
			*/
		size_type	size() const {
			return this->_end - this->_start;
		};

		/*___
		 @Returns the maximum number of elements that the vector can hold.
			*/
		size_type	max_size() const {
			return allocator_type().max_size();
		};

		/*___
		 @Requests that the vector capacity be at least enough to contain n elements.
			*/
		void	reserve( size_type n ) {
			if (n > this->max_size())
				throw(std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size"));
			if (n > this->_capacity) {
				pointer			oldStart = this->_start;
				pointer			oldEnd = this->_end;
				// size_type		oldSize = this->_size;
				size_type		oldCapacity = this->_capacity;

				this->_start = this->_alloc.allocate(n);
				this->_end = this->_start;
				this->_size = 0;
				this->_capacity = n;
				for (pointer tmp = oldStart ; tmp != oldEnd ; tmp++)
				{
					this->_alloc.construct(this->_end, *tmp);
					this->_size++;
					this->_end++;
				}
				this->_alloc.deallocate(oldStart, oldCapacity);
			}
		};

		/*___
		 @Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
			*/
		size_type	capacity() const {
			return this->_capacity;
		};


	//\-----------------------------------Modifiers-----------------------------------\/

		/*___
		 @Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
			*/
		void	clear( void ) {
			for (size_type	i = 0 ; i < this->_size ; i++)
			{
				this->_end--;
				this->_alloc.destroy(this->_end);
			}
			return ;
		};

		/*___
		 @Insert single element at position.
		 @Return an iterator that points to the element inserted.
			*/
		iterator	insert (iterator position, const value_type& val) {
			this->insert(position, 1, val);
			return (iterator(position));
		};

		/*___
		 @Fill insert.
		 @Add n val at position.
			*/
		void	insert (iterator position, size_type n, const value_type& val) {
			size_type	keepPosition = 0;

			for (iterator tmp = this->begin() ; tmp != position ; tmp++)
				keepPosition++;
			if ((this->_size + n) > this->_capacity)
			{
				this->resize(this->_size + n);
				for (position = this->begin() ; keepPosition > 0 ; keepPosition--)
					position++;
			}
			iterator	oldB = position;
			iterator	oldE = position;
			for (size_type i = n ; i > 0 ; i--)
				oldE++;
			while (oldE != this->end())
			{
				*oldE = *oldB;
				oldE++;
				oldB++;
			}
			while (n-- > 0)
			{
				*(position) = val;
				position++;
			}
		};

		/*___
		 @Range insert.
		 @Add range first to last at position.
			*/
		template<class InputIterator>
		void	insert(iterator position,
						InputIterator first,
							InputIterator last,
								typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {
			size_type	keepPosition = 0;
			for (iterator tmp = this->begin() ; tmp != position ; tmp++)
				keepPosition++;
			size_type	sizeAdded = 0;
			for (InputIterator tmp = first ; tmp != last ; tmp++)
				sizeAdded++;
			if ((this->_size + sizeAdded) > this->_capacity)
			{
				this->resize(this->_size + sizeAdded);
				for (position = this->begin(); keepPosition > 0 ; keepPosition--)
					position++;
			}
			iterator	oldB = position;
			iterator	oldE = position;
			for (; sizeAdded > 0 ; sizeAdded--)
			{
				oldE++;
			}
			while (oldE != this->end())
			{
				*oldE = *oldB;
				oldE++;
				oldB++;
			}
			while (first != last)
			{
				*(position) = *first;
				position++;
				first++;
			}
			return ;
		};

		/*___
		 @Removes from the vector a single element.
			*/
		iterator	erase(iterator position) {
			size_t		tmpPosition = 0;

			for (iterator tmp = this->begin() ; tmp != position ; tmp++)
				tmpPosition++;
			this->_alloc.destroy(this->_start + tmpPosition);
			iterator	tmp = position;
			while (tmp + 1 != this->end()) {
				*tmp = *(tmp + 1);
				tmp++;
			}
			this->_size -= 1;
			--this->_end;
			return (iterator(position));
		};

		/*___
		 @Removes from the vector  a range of elements.
			*/
		iterator erase (iterator first, iterator last) {
			for (; first != last ; first++)
				erase(first);
			return (iterator(first));
		};

		/*___
		 @Adds val at the end of the vector, after its current last element.
			*/
		void push_back (const value_type &val) {
			if (this->_size == this->_capacity)
			{
				if (this->_size == 0)
					reserve(1);
				else
				{
					reserve(this->_size * 2);
				}
			}
			this->_alloc.construct(this->_end++, val);
			this->_size++;
			return ;
		};

		/*___
		 @Removes the last element in the vector, effectively reducing the container size by one.
			*/
		void pop_back( void ) {
			if (this->empty() == false) {
				this->_alloc.destroy(this->_end - 1);
				this->_end--;
			}
			return ;
		};

		/*___
		 @Resizes the container so that it contains n elements.
			*/
		void	resize(size_type n, value_type val = value_type()) {
			if (n > this->max_size())
				throw(std::length_error("vector"));
			if (this->size() > n) {
				while (this->size() > n)
					this->_alloc.destroy(--this->_end);
			}
			else {
				if (this->capacity() * 2 >= n)
					this->reserve(this->capacity() * 2);
				else
					this->reserve(n);
			}
			while (this->size() < n) {
				this->_alloc.construct(this->_end, val);
				this->_end++;
			}
			return ;
		};

		/*___
		 @Exchanges the content of the container by the content of x.
			*/
		void	swap(vector& x) {
			allocator_type	tmpAlloc = this->_alloc;
			value_type		tmpSize = this->_size;
			value_type		tmpCapacity = this->_capacity;
			pointer			tmpStart = this->_start;
			pointer			tmpEnd = this->_end;

			this->_alloc = x._alloc;
			this->_size = x._size;
			this->_capacity = x._capacity;
			this->_start = x._start;
			this->_end = x._end;

			x->_alloc = tmpAlloc;
			x->_size = tmpSize;
			x->_capacity = tmpCapacity;
			x->_start = tmpStart;
			x->_end = tmpEnd;
			return ;
		};


};

//\-----------------------------------Non-member operator overloads-----------------------------------\/

/*___
 @Performs the == comparison operation between the vector containers lhs and rhs.
	*/
template <class T, class Alloc>
bool	operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	if (lhs._size != rhs._size)
		return false;
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
};

/*___
 @Performs the != comparison operation between the vector containers lhs and rhs.
	*/
template <class T, class Alloc>
bool	operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return (!(lhs == rhs));
};

/*___
 @Performs the < comparison operation between the vector containers lhs and rhs.
	*/
template <class T, class Alloc>
bool	operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
};

/*___
 @Performs the <= comparison operation between the vector containers lhs and rhs.
	*/
template <class T, class Alloc>
bool	operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return (!(lhs > rhs));
};

/*___
 @Performs the > comparison operation between the vector containers lhs and rhs.
	*/
template <class T, class Alloc>
bool	operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return (rhs < lhs);
};

/*___
 @Performs the >= comparison operation between the vector containers lhs and rhs.
	*/
template <class T, class Alloc>
bool	operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return (!(lhs < rhs));
};


//\-----------------------------------Non-member function overloads-----------------------------------\/

	/*___
	 @The contents of container x are exchanged with those of y.
		*/
	template <class T, class Alloc>
	void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y) {
		x.swap(y);
		return ;
	};

};

#endif