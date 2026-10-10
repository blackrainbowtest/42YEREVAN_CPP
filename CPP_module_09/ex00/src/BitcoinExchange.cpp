#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
   this->_db = other._db;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		this->_db = other._db;
	return (*this);
}

/**
* @brief Reads the database file and populates the database map with date-value pairs.
*
* example of the database file format:
* 2021-01-01,29374.15
*/
void BitcoinExchange::parsePush(const std::string &data)
{
    std::string date;
    float value;

    date = data.substr(0, data.find(","));
    value = atof(data.substr(data.find(",")+1, data.length()).c_str());

    this->_db[date] = value;
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

	if (!db.is_open())
	{
		std::cerr << "Error: could not open data.csv." << std::endl;
		return ;
	}
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
	t_date.tm_isdst = -1; // Not set by mktime; tells mktime to determine whether daylight saving time is in effect

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
	errno = 0; // Reset errno before calling strtof

    // catch empty string
    if (value.empty())
        return (-1.0f);

    float val = strtof(value.c_str(), &end);

	// catch out of range values
	if (errno == ERANGE)
        return (-1.0f);

    // catch invalid float values (e.g., "abc", "12.34abc")
    if (end == value.c_str() || *end != '\0')
        return (-1.0f);

    // catch NaN (Not a Number) values
    if (val != val)
        return (-1.0f);

    // catch negative values
    if (val < 0)
        return (-2.0f);

    if (val > 1000)
        return (-3.0f);

    return (val);
}

/**
*	@brief Finds the value of Bitcoin for a given date and amount.
*	@param date The date for which to find the Bitcoin value.
*	@param value The amount of Bitcoin to convert.
*	@note The function checks if the date and value are valid, finds the closest date
*		in the database, and calculates the equivalent value in USD.
*
*	call checkDate(date) and validate the date.
*	call checkValue(value) and validate the amount.
*	find the closest date in the database.
*	multiply the exchange rate by the amount of Bitcoin.
*	print the result or an error message.
*/

void BitcoinExchange::findValue(const std::string &date, const std::string &value)
{
	// 1. Declare the necessary variables
	float amount;
	float exchange_rate;

	// 2. Validate the date using checkDate()
	//    If the date is invalid, print an error message and return
	if (!checkDate(date))
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return;
	}

	// 3. Validate the value using checkValue()
	//    If -1 -> invalid value
	//    If -2 → not a positive number
	//    If -3 → too large a number
	amount = checkValue(value);
	if (amount == -1.0f)
	{
		std::cout << "Error: Invalid value format." << std::endl;
		return;
	}
	if (amount == -2.0f)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return;
	}
	if (amount == -3.0f)
	{
		std::cout << "Error: too large a number." << std::endl;
		return;
	}

	// 4. Find the Bitcoin exchange rate in the database
	//    Use lower_bound()
	//    If the exact date exists, use its exchange rate
	//    If the exact date does not exist, use the closest earlier date
	//    If the date is earlier than the first entry, handle the error
	if (_db.empty())
	{
		std::cout << "Error: Database is empty." << std::endl;
		return;
	}
	std::map<std::string, float>::const_iterator it = _db.lower_bound(date);
	if (it != _db.end() && it->first == date)
	{
		exchange_rate = it->second;
	}
	else if (it != _db.begin())
	{
		--it;
		exchange_rate = it->second;
	}
	else
	{
		std::cout << "Error: Date is earlier than the first entry in the database." << std::endl;
		return;
	}

	// 5. Calculate the result
	//    result = amount * exchange_rate
	float result = amount * exchange_rate;


	// 6. Print the result
	//    date => amount = result
	std::cout << date << " => " << amount << " = " << result << std::endl;
}

void BitcoinExchange::readParse(const char *file)
{
	// 1. Declare the necessary variables
	std::ifstream inputFile(file);
	std::string line;
	std::string date;
	std::string value;
	std::string::size_type pos;

	// 2. Check if the file was opened successfully
	if (!inputFile.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	// 3. Read and validate the header
	if (!std::getline(inputFile, line) || line != "date | value")
	{
		std::cerr << "Error: invalid file header." << std::endl;
		return;
	}

	// 4. Read the remaining lines
	while (std::getline(inputFile, line))
	{
		// 5. Find the separator '|'
		pos = line.find('|');
		if (line.find('|', pos + 1) != std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		// 6. Extract date and value
		date = line.substr(0, pos);
		value = line.substr(pos + 1);

		// 7. Handle spaces around date and value
		date.erase(0, date.find_first_not_of(' '));
		date.erase(date.find_last_not_of(' ') + 1);
		value.erase(0, value.find_first_not_of(' '));
		value.erase(value.find_last_not_of(' ') + 1);

		// 8. Validate the line structure
		if (date.empty() || value.empty())
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		// 9. Call findValue(date, value)
		findValue(date, value);
	}
}