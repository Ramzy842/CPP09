/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:51:07 by rchahban          #+#    #+#             */
/*   Updated: 2024/07/10 19:11:26 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: RPN \"expression\"" << std::endl;
        return 1;
    }
    RPN rpn;
    std::string expression = argv[1];
    rpn.calculate(expression);
    return 0;
}