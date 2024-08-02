/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:51:19 by rchahban          #+#    #+#             */
/*   Updated: 2024/08/02 17:28:48 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : is_even_seq(false)
{
	
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &original)
{
    (void)original;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &original)
{
    (void)original;
    return *this;
}

bool PmergeMe::get_is_even_seq()
{
	return this->is_even_seq;
}
void PmergeMe::set_is_even_seq(bool b)
{
	this->is_even_seq = b;
}

void PmergeMe::add_to_deq(int num1, int num2)
{
	this->deq.push_back(std::make_pair(num1, num2));
}
void PmergeMe::add_to_vec(int num1, int num2)
{
	this->vec.push_back(std::make_pair(num1, num2));
}
void PmergeMe::display_before(int argc, char **argv)
{
	for (int x = 1; x < argc; x++)
	{
		std::cout << argv[x] << " ";	
	}
	std::cout << std::endl;
}

template <typename T> void PmergeMe::display_result(T& container)
{
	typename T::iterator it;
	int x = 0;
	for (it = container.begin(); it != container.end(); it++)
	{
		std::cout << *it << " ";
		x++;
	}
	std::cout << std::endl;
}

bool numbers_are_digits(char **numbers)
{
	int x = 1;
	while (numbers[x])
	{
		int y = 0;
		while (numbers[x][y])
		{
			if (!isdigit(numbers[x][y]) && numbers[x][y] != '+')
            	return false;
			y++;
		}
		x++;
	}
	return true;
}

void PmergeMe::execute(int argc, char **argv) 
{
	if ((argc - 1) % 2 == 0)
		set_is_even_seq(true);
	if (!numbers_are_digits(argv))
	{
		std::cerr << "Error" << std::endl;
		return ;
	}
	int x = 1;
	while (argv[x] && argv[x+1])
	{
		unsigned int number1 = atoi(argv[x]);
		unsigned int number2 = atoi(argv[x + 1]);
		if (number1 < 0 || number2 < 0)
		{
			std::cerr << "Error" << std::endl;
			return ;
		}
		this->add_to_deq(number1, number2);
		this->add_to_vec(number1, number2);
		x += 2;
	}
	if (!get_is_even_seq())
	{
		left_over_num = atoi(argv[x]);
		if (left_over_num < 0)
		{
			std::cerr << "Error" << std::endl;
			return ;
		}
	}
	std::cout << "Before: ";
	this->display_before(argc, argv);

	clock_t start1 = clock();
	std::deque <unsigned int> deq_small_nums, deq_big_nums;
	perform_deq_sorting(deq_small_nums, deq_big_nums);
    clock_t end1 = clock();
    double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

    clock_t start2 = clock();
	std::vector <unsigned int> vec_small_nums, vec_big_nums;
    perform_vec_sorting(vec_small_nums, vec_big_nums);
    clock_t end2 = clock();
    double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;

    std::cout << "After: ";
    display_result(vec_small_nums);
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque container: " << time1 << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector container: " << time2 << " us" << std::endl;
}

void PmergeMe::perform_deq_sorting(std::deque <unsigned int>& small_nums,
									std::deque <unsigned int>& big_nums)
{
	for (size_t x = 0; x < this->deq.size(); x++)
    {
        if (this->deq[x].first > this->deq[x].second)
            std::swap(this->deq[x].first, this->deq[x].second);
    }
	for (size_t x = 0; x < this->deq.size(); x++)
    {
        small_nums.push_back(this->deq[x].first);
		big_nums.push_back(this->deq[x].second);
    }
	std::sort(small_nums.begin(), small_nums.end());
	for (size_t x = 0; x < big_nums.size(); x++) {
		std::deque <unsigned int>::iterator it = std::lower_bound(small_nums.begin(), small_nums.end(), big_nums[x]);
		small_nums.insert(it, big_nums[x]);
	}
	if (!get_is_even_seq())
	{
		std::deque <unsigned int>::iterator it = std::lower_bound(small_nums.begin(), small_nums.end(), left_over_num);	
		small_nums.insert(it, left_over_num);
	}
}

void PmergeMe::perform_vec_sorting(std::vector <unsigned int>& small_nums,
									std::vector <unsigned int>& big_nums)
{
	for (size_t x = 0; x < this->vec.size(); x++)
    {
        if (this->vec[x].first > this->vec[x].second)
            std::swap(this->vec[x].first, this->vec[x].second);
    }
	for (size_t x = 0; x < this->vec.size(); x++)
    {
        small_nums.push_back(this->vec[x].first);
		big_nums.push_back(this->vec[x].second);
    }
	std::sort(small_nums.begin(), small_nums.end());
	for (size_t x = 0; x < big_nums.size(); x++) {
		std::vector <unsigned int>::iterator it = std::lower_bound(small_nums.begin(), small_nums.end(), big_nums[x]);
		small_nums.insert(it, big_nums[x]);
	}
	if (!get_is_even_seq())
	{
		std::vector <unsigned int>::iterator it = std::lower_bound(small_nums.begin(), small_nums.end(), left_over_num);	
		small_nums.insert(it, left_over_num);
	}
}

