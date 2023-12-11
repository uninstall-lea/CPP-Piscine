#include "PmergeMe.hpp"

/* ------------------------- Initialize static field ------------------------ */
t_lstPair	PmergeMe::lst;
t_vecPair	PmergeMe::vec;

/* ----------------------------- Printing output ---------------------------- */
void	PmergeMe::printTime( const t_vecPair& vec, clock_t start, clock_t end ) {

	double	time_used	= double(end - start) / CLOCKS_PER_SEC;

	std::cout << "Time to process a range of " << vec.size() << " elements with vector: "
	<< std::fixed << std::setprecision(5) << time_used << " us" << std::endl;
}

void	PmergeMe::printTime( const t_lstPair& lst, clock_t start, clock_t end ) {

	double	time_used	= double(end - start) / CLOCKS_PER_SEC;

	std::cout << "Time to process a range of " << lst.size() << " elements with list: "
	<< std::setprecision(5) << time_used << " us" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const t_vecPair& vec) {

	for (t_vecPair::const_iterator i = vec.begin(); i != vec.end(); ++i) {
		os << i->first;
        if (i != vec.end() - 1)
            os << " ";
	}
	return (os);
}

std::ostream& operator<<(std::ostream& os, const t_lstPair& lst) {

	for (t_lstPair::const_iterator i = lst.begin(); i != lst.end(); ++i) {
		os << i->first;
        if (i != lst.end())
            os << " ";
	}
	return (os);
}

/* ----------------------------- Core functions ----------------------------- */

void	PmergeMe::fordJohnson(void) {

	for (t_lstPair::iterator it = lst.begin(); it != lst.end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
}

void	PmergeMe::fordJohnson(t_vecPair& v) {

	if (v.size() <= 1)
        return;

    t_vecPair v1, v2;
    for (size_t i = 0; i < v.size() / 2; ++i) {
        v1.push_back(v[i]);
	}

    for (size_t i = v.size() / 2; i < v.size(); ++i) {
        v2.push_back(v[i]);
	}

    fordJohnson(v1);
    fordJohnson(v2);
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
}

void	PmergeMe::fillContainers(int ac, char** av) {

	int i = 1;

	for (; i < ac - 1; ++i) {
		size_t n1 = atoll(av[i]);
		size_t n2 = atoll(av[i + 1]);
        if (n1 < 0 || n2 < 0 || n1 > INT_MAX || n2 > INT_MAX || !isdigit(*av[i]) || !isdigit(*av[i + 1]))
            throw std::invalid_argument("Error => Bad input: only positive integers within the range '0-INT_MAX' allowed.");
        vec.push_back(std::make_pair(n1, n2));
		lst.push_back(std::make_pair(n1, n2));
    }
	if (i == ac - 1) {
		size_t n = atoll(av[i]);
		std::cout << "|" << n << "|" << std::endl;
		 if (n < 0 || n > INT_MAX || !isdigit(*av[i]))
			throw std::invalid_argument("Error => Bad input: only positive integers within the range '0-INT_MAX' allowed.");
		vec.push_back(std::make_pair(n, n));
		lst.push_back(std::make_pair(n, n));
	}
}

void	PmergeMe::run(int ac, char** av) {

	clock_t	start, end;

	fillContainers(ac, av);

	std::cout << "Before: " << vec << std::endl;
	
	start = clock();
	fordJohnson(vec);
	end = clock();
	printTime(vec, start, end);

	start = clock();
	fordJohnson();
	end = clock();
	printTime(lst, start, end);
	std::cout << "After:  " << vec << std::endl;
}