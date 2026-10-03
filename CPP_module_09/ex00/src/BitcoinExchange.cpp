#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
   this->database = copy.database;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& in)
{
    this->database = in.database;
    return (*this);    
}
