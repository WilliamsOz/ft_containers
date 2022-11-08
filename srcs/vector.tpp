/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:25:06 by wiozsert          #+#    #+#             */
/*   Updated: 2022/11/08 12:17:50 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

template<class T, class Alloc >
vector<T, Alloc>::vector( void )
{
	std::cout << "Coucou" << std::endl;
	return ;
}

template<class T, class Alloc >
vector<T, Alloc>::~vector( void )
{

	std::cout << "Coucou aussi" << std::endl;
	return ;
}