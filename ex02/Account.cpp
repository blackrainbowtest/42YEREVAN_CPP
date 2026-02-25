#include "Account.hpp"
#include <iostream>
/*
Account(int) × 8

displayAccountsInfos()

displayStatus() × 8

makeDeposit() × 8

displayAccountsInfos()

displayStatus() × 8

makeWithdrawal() × 8

displayAccountsInfos()

displayStatus() × 8

~Account() × 8
*/


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account() {}

Account::Account( int initial_deposit )
{
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	this->_amount = initial_deposit;
	Account::_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout	<< "index:"		<< this->_accountIndex		<< ";"
				<< "amount:"	<< this->_amount			<< ";"
				<< "created"	<< std::endl;
	
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout	<< "index:"		<< this->_accountIndex		<< ";" 
				<< "amount:"	<< this->checkAmount()		<< ";"
				<< "closed"		<< std::endl;
}

void	Account::_displayTimestamp( void )
{

	std::cout	<< "["
	// cout time like this here [19920104_091532]
	// yyyymmdd_hhmmss
				<< "]";
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}
// Account.cpp