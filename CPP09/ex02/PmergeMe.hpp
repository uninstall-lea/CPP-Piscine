#include <list>
#include <ctime>
#include <vector>
#include <iomanip>
#include <iterator>
#include <iostream>
#include <algorithm>

class PmergeMe {
public:
	static std::vector<int>	vec;
	static std::list<int>	lst;

	/* Sorting containers */
	static void				sortVec( void );
	static void				sortLst( void );

	/* Core functions */
	static void				fillContainers(int ac, char** av);
	static void				printTime( std::vector<int> vec, clock_t start, clock_t end);
	static void				printTime( std::list<int> lst, clock_t start, clock_t end);
	static void 			run(int ac, char** av);
};

std::ostream& operator<<( std::ostream& os, const std::vector<int>& vec );
std::ostream& operator<<( std::ostream& os, const std::list<int>& lst );
