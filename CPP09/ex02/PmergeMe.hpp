#include <list>
#include <ctime>
#include <climits>
#include <vector>
#include <utility>
#include <iomanip>
#include <iterator>
#include <iostream>
#include <algorithm>

typedef std::vector<std::pair<int,int> > t_vecPair;
typedef std::list<std::pair<int,int> > t_lstPair;

class PmergeMe {
public:
	static t_vecPair	vec;
	static t_lstPair	lst;
	/* Printing result */
	static void			printTime( const t_vecPair& vec, clock_t start, clock_t end );
	static void			printTime( const t_lstPair& lst, clock_t start, clock_t end );

	/* Core functions */
	static void			fordJohnson( void );
	static void			fordJohnson( t_vecPair& v );
	static void			fillContainers( int ac, char** av);
	static void 		run( int ac, char** av );
};

std::ostream& operator<<( std::ostream& os, const t_vecPair& vec );
std::ostream& operator<<( std::ostream& os, const t_lstPair& lst );