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

/**
* @brief Reads the database file and populates the database map with date-value pairs.
*
* example of the database file format:
* 2021-01-01,29374.15
*/
void BitcoinExchange::parsePush(std::string data)
{
    std::string date;
    float value;

    date = data.substr(0, data.find(","));
    value = atof(data.substr(data.find(",")+1, data.length()).c_str());

    this->database[date] = value;
}

/**
* @brief Reads the database file and populates the database map with date-value pairs.
*
* example of the database file format:
* 2021-01-01,29374.15
*/
void BitcoinExchange::readDb()
{
    std::ifstream db("data.csv");
    std::string data;


    while(std::getline(db, data))
    {
        if (data != "date,exchange_rate")
            parsePush(data);
    }
}

bool BitcoinExchange::checkDate(std::string date)
{

}

float BitcoinExchange::checkValue(std::string value)
{

}

void BitcoinExchange::findValue(std::string date, std::string value)
{

}

void BitcoinExchange::readParse(const char *file)
{

}