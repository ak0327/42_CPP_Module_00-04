#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::getNbAccounts(void) {
	return 0;
}

int Account::getTotalAmount(void) {
	return 0;
}

int Account::getNbDeposits(void) {
	return 0;
}

int Account::getNbWithdrawals(void) {
	return 0;
}

//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void Account::displayAccountsInfos(void) {
	// timestamp
	_displayTimestamp();

	// accounts infos

}

Account::Account(void) {

}

Account::Account(int initial_deposit) {
	_accountIndex = 0; //これは...?
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	// timestamp
	_displayTimestamp();

	// display index, amount, deposits, withdrawals


	// created
	std::cout << "created" << std::endl;
}

Account::~Account(void) {
	// timestamp
	_displayTimestamp();

	// display index and amount

	// closed
	std::cout << "closed" << std::endl;
}

void Account::makeDeposit(int deposit) {

}

bool Account::makeWithdrawal(int withdrawal) {
	return false;
}

int Account::checkAmount(void) const {
	return 0;
}

// index:0;amount:42;deposits:0;withdrawals:0
void Account::displayStatus(void) const {

}

// [19920104_091532]
// [YYYYMMDD_HHMMSS]
void Account::_displayTimestamp(void) {
	std::time_t	*timeStamp;
	std::localtime(timeStamp);
	std::cout << std::put_time(timeS)
}

