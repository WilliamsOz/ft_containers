/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:43:39 by wiozsert          #+#    #+#             */
/*   Updated: 2022/12/01 16:46:29 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_PAIR_HPP
#define MAKE_PAIR_HPP

#include "pair.hpp"

namespace ft {

	template <class T1, class T2>
	ft::pair<T1, T2> make_pair(T1 first, T2 second) {
		ft::pair<T1, T2>	newPair(first, second);

		return (newPair);
	}

};

#endif