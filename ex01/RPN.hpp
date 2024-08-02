/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:51:13 by rchahban          #+#    #+#             */
/*   Updated: 2024/08/02 16:54:25 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <algorithm>
#include <stack>

class RPN
{
    private:
        std::stack<double> numbers;
    public:
        RPN();
        ~RPN();
        RPN(const RPN& original);
        RPN& operator=(const RPN& original);
        void calculate(std::string& expression);
};


#endif