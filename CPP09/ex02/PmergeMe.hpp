#include <list>
#include <ctime>
#include <vector>
#include <utility>
#include <iomanip>
#include <iterator>
#include <iostream>
#include <algorithm>

class PmergeMe {
public:
	static std::list<int>	lst;
	static std::vector<int>	vec;

	/* Printing result */
	static void				printTime( const std::vector<int>& vec, clock_t start, clock_t end );
	static void				printTime( const std::list<int>& lst, clock_t start, clock_t end );

	/* Core functions */
	static void				fillContainers( int ac, char** av);
	static void				fordJohnson( void );
	static void 			run( int ac, char** av );
};

std::ostream& operator<<( std::ostream& os, const std::list<int>& lst );
std::ostream& operator<<( std::ostream& os, const std::vector<int>& vec );
