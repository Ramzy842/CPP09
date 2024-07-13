/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:51:20 by rchahban          #+#    #+#             */
/*   Updated: 2024/07/13 03:03:01 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>
#include <cstdlib>

class PmergeMe
{
    private:
		std::deque<int> deq;
		std::list<int> list;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &original);
        PmergeMe &operator=(const PmergeMe &original);
		void add_to_deq(int num);
		void add_to_list(int num);
		template <typename T> void display(T& container);
		void execute(char **argv);
		void mrg_isrt_sort_deq(std::deque<int>& deq);
		void mrg_isrt_sort_list(std::list<int>& list);
};

#endif