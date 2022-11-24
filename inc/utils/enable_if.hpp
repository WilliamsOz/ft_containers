/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:47:07 by wiozsert          #+#    #+#             */
/*   Updated: 2022/11/24 13:13:25 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF
#define ENABLE_IF

namespace ft {

template<bool Cond, class T = void>
struct enable_if { };

template<class T>
struct enable_if<true, T>{
	typedef T type;
};

};

#endif