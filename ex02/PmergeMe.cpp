/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:51:19 by rchahban          #+#    #+#             */
/*   Updated: 2024/07/13 03:07:50 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
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

void PmergeMe::add_to_deq(int num)
{
	this->deq.push_back(num);
}
void PmergeMe::add_to_list(int num)
{
	this->list.push_back(num);
}
template<typename T> void PmergeMe::display(T& container)
{
	typename T::iterator it;
	for (it = container.begin(); it != container.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::execute(char **argv) 
{
	int x = 1;
	while (argv[x])
	{
		int number = atoi(argv[x]);
		if (number <= 0)
		{
			std::cout << "Error" << std::endl;
			return ;
		}
		this->add_to_deq(number);
		this->add_to_list(number);
		x++;
	}
	std::cout << "Before: ";
	this->display(this->deq);

	clock_t start1 = clock();
    mrg_isrt_sort_deq(this->deq);
    clock_t end1 = clock();
    double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

    clock_t start2 = clock();
    mrg_isrt_sort_list(this->list);
    clock_t end2 = clock();
    double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;

    std::cout << "After: ";
    display(this->deq);
    std::cout << "Time to process a range of " << this->deq.size() << " elements with std::deque container: " << time1 << " us" << std::endl;
    std::cout << "Time to process a range of " << this->list.size() << " elements with std::list container: " << time2 << " us" << std::endl;
}

void PmergeMe::mrg_isrt_sort_deq(std::deque<int>& deq)
{
	std::deque<int>::iterator it1, it2;
    for (it1 = deq.begin() + 1; it1 != deq.end(); ++it1)
    {
        int temp = *it1;
        it2 = it1;
        while (it2 != deq.begin() && *(std::prev(it2)) > temp)
        {
            *it2 = *(std::prev(it2));
            std::advance(it2, -1);
        }
        *it2 = temp;
    }
}
void PmergeMe::mrg_isrt_sort_list(std::list<int>& list)
{
	std::list<int>::iterator it1, it2;
    for (it1 = ++list.begin(); it1 != list.end(); ++it1)
    {
        int temp = *it1;
        it2 = it1;
        while (it2 != list.begin() && *(std::prev(it2)) > temp)
        {
            *it2 = *(std::prev(it2));
            std::advance(it2, -1);
        }
        *it2 = temp;
    }
}