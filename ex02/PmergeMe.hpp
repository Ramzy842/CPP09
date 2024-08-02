/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:51:20 by rchahban          #+#    #+#             */
/*   Updated: 2024/08/02 17:28:36 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>

class PmergeMe
{
    private:
		bool is_even_seq;
		unsigned int left_over_num;
		std::deque< std::pair<unsigned int, unsigned int> > deq;
		std::vector< std::pair<unsigned int, unsigned int> > vec;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &original);
        PmergeMe &operator=(const PmergeMe &original);
		void add_to_deq(int num1, int num2);
		void add_to_vec(int num1, int num2);
		void display_before(int argc, char **argv);
		template <typename T> void display_result(T& container);
		void execute(int argc, char **argv);
		void perform_deq_sorting(std::deque <unsigned int>& small_nums, std::deque <unsigned int>& big_nums);
		void perform_vec_sorting(std::vector <unsigned int>& small_nums, std::vector <unsigned int>& big_nums);
		bool get_is_even_seq();
		void set_is_even_seq(bool b);
};

#endif