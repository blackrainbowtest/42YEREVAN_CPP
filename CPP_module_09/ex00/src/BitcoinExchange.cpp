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

bool BitcoinExchange::checkDate(const std::string &date)
{
	int year, month, day;
	struct tm t_date;
	time_t cal;

	/** 
		tm_sec   = 0
		tm_min   = 0
		tm_hour  = 0
		tm_mday  = 0
		tm_mon   = 0
		tm_year  = 0
	*/
	memset(&t_date, 0, sizeof(struct tm));

	if (date.length() != 10)
        return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return (false);
	}

	year = atoi(date.substr(0, 4).c_str());
	month = atoi(date.substr(5, 2).c_str());
	day = atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);
	
	t_date.tm_year = year - 1900;
	t_date.tm_mon = month - 1;
	t_date.tm_mday = day;
	cal = mktime(&t_date);

	if (cal == -1)
		return (false);
	if (t_date.tm_year != year - 1900 || t_date.tm_mon != month - 1 || t_date.tm_mday != day)
		return (false);

	return (true);
}

/**
* @brief Checks if the value is a valid float and returns it.
* @param value The string representation of the value to check.
* @return The valid float value.
*         The value must be a valid float and greater than 0 and less than 1000.
*/
float BitcoinExchange::checkValue(const std::string &value)
{
    char *end;

    // catch empty string
    if (value.empty())
        return (-1.0f);

    float val = strtof(value.c_str(), &end);

    // catch invalid float values (e.g., "abc", "12.34abc")
    if (end == value.c_str() || *end != '\0')
        return (-1.0f);

    // catch NaN (Not a Number) values
    if (val != val)
        return (-1.0f);

    // catch infinity values
    if (val < 0)
        return (-2.0f);

    if (val > 1000)
        return (-3.0f);

    return (val);
}

void BitcoinExchange::findValue(const std::string &date, const std::string &value)
{

}

void BitcoinExchange::readParse(const char *file)
{

}