/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:51:15 by rchahban          #+#    #+#             */
/*   Updated: 2024/07/13 02:50:26 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	
	if (argc == 1)
	{
		std::cout << "Usage: ./PmergeMe 52 1 43 8 2.." << std::endl;
		return 1;
	}
	PmergeMe p;
	p.execute(argv);
	return 0;
}