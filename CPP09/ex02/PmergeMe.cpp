#include "PmergeMe.hpp"

/* ------------------------- Initialize static field ------------------------ */
std::list<int>	PmergeMe::lst;
t_vecPair		PmergeMe::vec;

/* ----------------------------- Printing output ---------------------------- */
void	PmergeMe::printTime( const t_vecPair& vec, clock_t start, clock_t end ) {

	double	time_used	= double(end - start) / CLOCKS_PER_SEC;

	std::cout << "Time to process a range of " << vec.size() << " elements with vector: "
	<< std::fixed << std::setprecision(5) << time_used << " us" << std::endl;
}

void	PmergeMe::printTime( const std::list<int>& lst, clock_t start, clock_t end ) {

	double	time_used	= double(end - start) / CLOCKS_PER_SEC;

	std::cout << "Time to process a range of " << lst.size() << " elements with vector: "
	<< std::setprecision(1) << time_used << " us" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const t_vecPair& vec) {

	os << "[";
	for (t_vecPair::const_iterator i = vec.begin(); i != vec.end(); ++i) {
		os << i->first;
        if (i != vec.end() - 1)
            os << ", ";
	}
    os << "]"; 
	return (os);
}

std::ostream& operator<<(std::ostream& os, const std::list<int>& lst) {

    std::copy(lst.begin(), lst.end(), std::ostream_iterator<int>(os, ", "));
    os << "\b\b";
	return (os);
}

/* ----------------------------- Core functions ----------------------------- */

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


	for (int i = 1; i < ac - 1; ++i) {
		int n1 = atoi(av[i]);
		int n2 = atoi(av[i + 1]);
        if (n1 < 0 || n2 < 0 || !isdigit(*av[i]) || !isdigit(*av[i + 1]))
            throw std::invalid_argument("Error => Bad input: only positive integers allowed.");
        vec.push_back(std::make_pair(n1, n2));
    }
    if (ac % 2 == 0) {
        int n = atoi(av[ac - 1]);
        if (n < 0)
            throw std::invalid_argument("Error => Negative numbers are not allowed.");
        vec.push_back(std::make_pair(n, n));
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
	printTime(lst, start, end);
	std::cout << "After: " << vec << std::endl;
}