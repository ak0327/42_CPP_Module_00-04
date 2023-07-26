#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) {



	return _nbAccounts;
}

int Account::getTotalAmount(void) {
	return _totalAmount;
}

int Account::getTotalNbDeposits(void) {
	return _totalNbDeposits;
}

int Account::getTotalNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void Account::displayAccountsInfos(void) {
    // timestamp
    _displayTimestamp();
    std::cout << " ";

    // total accounts
    std::cout << "accounts:"<< getNbAccounts() << ";";

    // total amount
    std::cout << "total:"<< getTotalAmount() << ";";

    // total deposit ?
    std::cout << "deposits:"<< getTotalNbDeposits() << ";";

    // total withdrawals
    std::cout << "withdrawals:"<< getTotalNbWithdrawals() << std::endl;
}

//Account::Account(void) {
//
//}

Account::Account(int initial_deposit = 0) :
    _accountIndex(_nbAccounts),
    _amount(initial_deposit),
    _nbDeposits(0),
    _nbWithdrawals(0) {

	// timestamp
	_displayTimestamp();
    std::cout << " ";

	// display index
    std::cout << "index:" << _accountIndex << ";";

    // display amount
    std::cout << "amount:" << checkAmount() << ";";

	// created
	std::cout << "created" << std::endl;

    _nbAccounts++;
    _totalAmount+=initial_deposit;
}

Account::~Account(void) {
	// timestamp
	_displayTimestamp();
    std::cout << " ";

	// display index
    std::cout << "index:" << _accountIndex << ";";

    // display amount
    std::cout << "amount:" << checkAmount() << ";";

	// closed
	std::cout << "closed" << std::endl;
}

//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void Account::makeDeposit(int deposit) {
    // timestamp
    _displayTimestamp();
    std::cout << " ";

    // display index
    std::cout << "index:" << _accountIndex << ";";

    // display amount
    std::cout << "p_amount:" << checkAmount() << ";";

    // display deposit
    if (deposit <= 0) {
        std::cout << "deposit:refused" << std::endl;
        return ;
    }
    std::cout << "deposit:" << deposit << ";";


    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    // display amount
    std::cout << "amount:" << checkAmount() << ";";

    // display nb_deposits
    std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

//[19920104_091532] index:0;p_amount:47;withdrawal:refused
//[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool Account::makeWithdrawal(int withdrawal) {
    // timestamp
    _displayTimestamp();
    std::cout << " ";

    // display index
    std::cout << "index:" << _accountIndex << ";";

    // display amount
    std::cout << "p_amount:" << checkAmount() << ";";

    // display withdrawal
    if (withdrawal <= 0 || checkAmount() < withdrawal) {
        std::cout << "withdrawal:refused" << std::endl;
        return false;
    }
    std::cout << "withdrawal:" << withdrawal << ";";

    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    // display amount
    std::cout << "amount:" << checkAmount() << ";";

    // display nb_withdrawals
    std::cout << "nb_withdrawals:" << _nbDeposits << std::endl;

	return true;
}

int Account::checkAmount(void) const {
	return _amount;
}

// index:0;amount:42;deposits:0;withdrawals:0
void Account::displayStatus(void) const {
    // timestamp
    _displayTimestamp();
    std::cout << " ";

    // display index
    std::cout << "index:" << _accountIndex << ";";

    // display amount
    std::cout << "amount:" << checkAmount() << ";";

    // display deposit
    std::cout << "deposits:" << _nbDeposits << ";";

    // display withdrawals
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

// [19920104_091532]
// [YYYYMMDD_HHMMSS]
void Account::_displayTimestamp() {
    std::time_t rawtime;
    std::tm*    timeinfo;
    char        buffer[80];

    std::time(&rawtime);
    timeinfo = std::localtime(&rawtime);

    std::strftime(buffer,80,"%Y%m%d_%H%M%S",timeinfo);
    std::cout << "[" << buffer << "]";
}
