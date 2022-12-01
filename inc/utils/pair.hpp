/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:19:57 by wiozsert          #+#    #+#             */
/*   Updated: 2022/12/01 16:46:33 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {

/*___
 @This class couples together a pair of values, which may be of different types (T1 and T2).
 @The individual values can be accessed through its public members first and second.
	*/
template <class T1, class T2>
struct pair{
	typedef T1	first_type;
	typedef T2	second_type;

	first_type	first;
	second_type	second;

	//\-----------------------------------Constructors-----------------------------------\/

	/*___
	 @Default constructor.
	 @Constructs a pair object with its elements value-initialized.
		*/
	pair( void ) : first(), second() {
		return ;
	};

	/*___
	 @Copy / Move constructor.
	 @The object is initialized with the contents of the pr pair object.
	 @The corresponding member of pr is passed to the constructor of each of its members.
		*/
	template<class U, class V>
	pair(const pair<U,V>& pr) : first(pr.first), second(pr.second){
		return ;
	};

	/*___
	 @Initialization constructor.
	 @Member first is constructed with a and member second with b.
		*/
	pair(const first_type& a, const second_type& b) : first(a), second(b){
		return ;
	};

	/*___
	 @Assignement operator.
	 @Assigns pr as the new content for the pair object.
		*/
	pair& operator= (const pair& pr) {
		if (this != &pr)
		{
			this->first = pr.first;
			this->second = pr.second;
		}
		return *this;
	};

};

//\-----------------------------------Non-member operator overloads-----------------------------------\/

/*___
 @Performs the == comparison operation between the vector containers lhs and rhs.
	*/
template <class T1, class T2>
bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
	return ((lhs.first == rhs.first) && (lhs.second == rhs.second));
};

/*___
 @Performs the != comparison operation between the vector containers lhs and rhs.
	*/
template <class T1, class T2>
bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
	return (!(lhs == rhs));
};

/*___
 @Performs the < comparison operation between the vector containers lhs and rhs.
	*/
template <class T1, class T2>
bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
	return ((lhs.first < rhs.first) ||  (!(rhs.first < lhs.first) && lhs.second < rhs.second));
};

/*___
 @Performs the <= comparison operation between the vector containers lhs and rhs.
	*/
template <class T1, class T2>
bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
	return (!(lhs < rhs));
};

/*___
 @Performs the > comparison operation between the vector containers lhs and rhs.
	*/
template <class T1, class T2>
bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
	return (rhs < lhs);
};

/*___
 @Performs the >= comparison operation between the vector containers lhs and rhs.
	*/
template <class T1, class T2>
bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
	return (!(lhs < rhs));
};

};

#endif