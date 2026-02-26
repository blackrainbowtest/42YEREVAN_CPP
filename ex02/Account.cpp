#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
/*
TODOS [ ] DONE [X]
[X] Account(int) × 8
[X] displayAccountsInfos() x 1
[X] displayStatus() × 8
[ ] makeDeposit() × 8
[X] displayAccountsInfos() x 1
[X] displayStatus() × 8
[ ] makeWithdrawal() × 8
[X] displayAccountsInfos() x 1
[X] displayStatus() × 8
[X]  ~Account() × 8
*/

int Account::_nbAccounts 			= 0;
int Account::_totalAmount 			= 0;
int Account::_totalNbDeposits		= 0;
int Account::_totalNbWithdrawals	= 0;

Account::Account() {}

Account::Account( int initial_deposit )
{
	this->_accountIndex 		= Account::_nbAccounts;
	Account::_nbAccounts++;
	this->_amount 				= initial_deposit;
	Account::_totalAmount 		+= this->_amount;
	this->_nbDeposits 			= 0;
	this->_nbWithdrawals 		= 0;
	
	Account::_displayTimestamp();
	
	// [19920104_091532] index:0;amount:42;created
	std::cout	<< "index:"		<< this->_accountIndex		<< ";"
				<< "amount:"	<< this->_amount			<< ";"
				<< "created"	<< std::endl;
	
}

Account::~Account( void )
{
	Account::_displayTimestamp();

	// [19920104_091532] index:0;amount:47;closed
	std::cout	<< "index:"		<< this->_accountIndex		<< ";" 
				<< "amount:"	<< this->checkAmount()		<< ";"
				<< "closed"		<< std::endl;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
	Account::_displayTimestamp();
	std::cout	<< "accounts:"		<< Account::getNbAccounts()		<< ";"
				<< "total:"			<< Account::getTotalAmount()	<< ";"
				<< "deposits:"		<< Account::getNbDeposits()		<< ";"
				<< "withdeawals:"	<< Account::getNbWithdrawals()	<< std::endl;
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	// [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
	Account::_displayTimestamp();
	std::cout	<< "index:"			<< Account::_accountIndex		<< ";"
				<< "amount:"		<< Account::checkAmount()		<< ";"
				<< "deposits:"		<< Account::_nbDeposits			<< ";"
				<< "withdeawals:"	<< Account::_nbWithdrawals		<< std::endl;
}

void	Account::makeDeposit( int deposit )
{
	// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	this->_nbDeposits++;	// update number of deposits

	// Bank client balance display block ========================================
	Account::_displayTimestamp();
	std::cout	<< "index:"			<< Account::_accountIndex		<< ";"
				<< "p_amount:"		<< this->_amount				<< ";"
				<< "deposit:"		<< deposit						<< ";"
				<< "amount:"		<< this->_amount + deposit		<< ";"
				<< "nb_deposits"	<< this->_nbDeposits			<< std::endl;

	// Bank client's balance interaction block ==================================
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
	// [19920104_091532] index:5;p_amount:23;withdrawal:refused
	Account::_displayTimestamp();
	std::cout	<< "index:"			<< Account::_accountIndex		<< ";"
				<< "p_amount:"		<< this->_amount				<< ";"
				<< "withdrawal:";
	if (withdrawal > this->checkAmount())
	{
		std::cout	<< "refused"	<< std::endl;
		return (false);
	}
	this->_nbWithdrawals++;
	std::cout	<< ""				<< withdrawal					<< ";"
				<< "amount"			<< this->_amount				<< ";"
				<< "nb_withdrawals"	<< this->_nbWithdrawals			<< std::endl;

	// Bank client's balance interaction block ==================================
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	return (true);
}

void	Account::_displayTimestamp( void )
{
	// [19920104_091532] -> yyyymmdd_hhmmss (%Y%m%d_%H%M%S)
	std::time_t now 			= time_t(NULL);
	std::tm* tm 				= std::localtime(&now);

	std::cout	<< std::put_time(tm, "[%Y%m%d_%H%M%S] ");
}
// Account.cpp