#include "Account.hpp"
#include <iostream>
#include <ctime>

/* -------------------------------------------------------------------------- */
/*                           Constructor/Destructor (Public)                  */
/* -------------------------------------------------------------------------- */

Account::Account( int initial_deposit ) {

	_displayTimestamp();
	std::cout
	<< "index:"  << getNbAccounts()	<< ";"
	<< "amount:" << initial_deposit	<< ";"
	<< "created" << std::endl;

	this->_accountIndex = getNbAccounts();
	_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}

Account::~Account( void ) {

	_displayTimestamp();
	std::cout
	<< "index:" << this->_accountIndex	<< ";"
	<< "amount:"<< this->_amount      	<< ";"
	<< "closed"	<< std::endl;
}

/* -------------------------------------------------------------------------- */
/*                                   Public                                   */
/* -------------------------------------------------------------------------- */

/* --------------------- Accessors of static attributes --------------------- */

int		Account::getNbAccounts( void ) {

	return (_nbAccounts);
}

int		Account::getTotalAmount( void ) {

	return (_totalAmount);
}
int		Account::getNbDeposits( void ) {

	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals( void ) {

	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {

	_displayTimestamp();
	std::cout
	<< "accounts:"    << getNbAccounts()   	<< ";"
	<< "total:"       << getTotalAmount()  	<< ";"
	<< "deposits:"    << getNbDeposits()   	<< ";"
	<< "withdrawals:" << getNbWithdrawals()	<< std::endl;
}

/* ---------------------------- Member Functions ---------------------------- */

void	Account::makeDeposit( int deposit ) {
	
	_displayTimestamp();
	std::cout
	<< "index:"       << this->_accountIndex    	<< ";"
	<< "p_amount:"    << checkAmount()          	<< ";"
	<< "deposit:"     << deposit                	<< ";"
	<< "amount:"      << checkAmount() + deposit	<< ";"
	<< "nb_deposits:" << this->_nbDeposits + 1  	<< std::endl;

	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal ) {

	_displayTimestamp();
	/* account provisions insufficient for withdrawal */
	if (withdrawal > this->_amount)
	{
		std::cout
		<< "index:"				<< this->_accountIndex	<< ";"
		<< "p_amount:"    		<< checkAmount()      	<< ";"
		<< "withdrawal:refused"	<< std::endl;
		return (false);
	}

	std::cout
	<< "index:"       		<< this->_accountIndex       	<< ";"
	<< "p_amount:"    		<< checkAmount()             	<< ";"
	<< "withdrawal:"  		<< withdrawal                	<< ";"
	<< "amount:"     	 	<< checkAmount() - withdrawal	<< ";"
	<< "nb_withdrawals:"	<< this->_nbWithdrawals +1		<< std::endl;

	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;

	return (true);
}

int		Account::checkAmount( void ) const {

	return (this->_amount);
}

void	Account::displayStatus( void ) const {

	_displayTimestamp();
	std::cout
	<< "index:"       << this->_accountIndex 	<< ";"
	<< "amount:"      << checkAmount()       	<< ";"
	<< "deposits:"    << this->_nbDeposits   	<< ";"
	<< "withdrawals:" << this->_nbWithdrawals	<< std::endl;
}

/* -------------------------------------------------------------------------- */
/*                                   Private                                  */
/* -------------------------------------------------------------------------- */

/* -------------------- Constructor/Destructor (Private) -------------------- */

Account::Account( void ) {

}

/* ---------------------------- Static Attributes --------------------------- */

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/* ----------------------------- Member function ---------------------------- */

void	Account::_displayTimestamp( void ) {

	char		str[20];
	time_t		sec = time(NULL);
	struct tm	*current_time;

	current_time = localtime(&sec);
	strftime(str, sizeof(str), "[%Y%m%d_%H%M%S]", current_time);
	std::cout << str << " ";
}