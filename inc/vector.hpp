/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:18:46 by wiozsert          #+#    #+#             */
/*   Updated: 2022/11/08 12:18:02 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "ft_containers.hpp"

template<class T, class Alloc = std::allocator<T> >
class vector
{
	private :

	public :
		explicit vector( void );
		~vector();
	
};

#include "vector.tpp"

#endif