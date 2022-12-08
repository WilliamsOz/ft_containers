/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extern_library.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:35:37 by wiozsert          #+#    #+#             */
/*   Updated: 2022/12/08 13:10:54 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTERN_LIBRARY_HPP
#define EXTERN_LIBRARY_HPP

#include <iostream>
#include <memory>
#include <cstddef>
#include <exception>

//usefull
#define p1 std::cout <<
#define p2 << std::endl;
#define RED "\033[1;31m"
#define GRN "\033[1;32m"
#define YEL "\033[1;33m"
#define BLU "\033[1;34m"
#define MAG "\033[1;35m"
#define CYA "\033[1;36m"
#define COLOR(x) std::cout<<x;
#define ENDCOLOR std::cout<<"\033[0m";

#endif