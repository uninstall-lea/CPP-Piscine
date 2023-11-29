#include "PmergeMe.hpp"

/* ------------------------- Initialize static field ------------------------ */
std::list<int>	 PmergeMe::lst;
std::vector<int> PmergeMe::vec;
/* --------------------------- Sorting containers --------------------------- */

void	PmergeMe::sortVec( void ) {

	std::sort(vec.begin(), vec.end());
}

void	PmergeMe::sortLst( void ) {

	lst.sort();
}

/* ----------------------------- Printing output ---------------------------- */
void	PmergeMe::printTime( std::vector<int> vec, clock_t start, clock_t end ) {

	double	time_used	= double(end - start) / CLOCKS_PER_SEC;

	std::cout << "Time to process a range of " << vec.size() << " elements with vector: "
	<< std::fixed << std::setprecision(5) << time_used << " us" << std::endl;
}

void	PmergeMe::printTime( std::list<int> lst, clock_t start, clock_t end ) {

	double	time_used	= double(end - start) / CLOCKS_PER_SEC;

	std::cout << "Time to process a range of " << lst.size() << " elements with vector: "
	<< std::fixed << std::setprecision(5) << time_used << " us" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec) {

	os << "[";
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(os, ", "));
    os << "\b\b]";
	return (os);
}

std::ostream& operator<<(std::ostream& os, const std::list<int>& lst) {

    std::copy(lst.begin(), lst.end(), std::ostream_iterator<int>(os, ", "));
    os << "\b\b";
	return (os);
}

/* ----------------------------- Core functions ----------------------------- */

void	PmergeMe::fillContainers(int ac, char** av) {

	for (int i = 1; i < ac; ++i) {
		int num = atoi(av[i]);
		if (num < 0)
			throw std::invalid_argument("Error => Negative numbers are not allowed.");
		vec.push_back(num);
	}
	lst.insert(lst.end(), vec.begin(), vec.end());
}

void	PmergeMe::run(int ac, char** av) {

	clock_t	start, end;

	fillContainers(ac, av);

	std::cout << "Before: " << vec << std::endl;

	start = clock();
	sortVec();
	end = clock();
	printTime(vec, start, end);

	start = clock();
	sortLst();
	end = clock();
	printTime(lst, start, end);

	std::cout << "After: " << vec << std::endl;
}