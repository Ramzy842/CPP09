
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
class PmergeMe
{
    private:
    
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &original);
        PmergeMe &operator=(const PmergeMe &original);
};

#endif