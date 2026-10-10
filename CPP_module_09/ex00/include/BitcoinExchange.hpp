#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# define BLACK		"\033[30m"
# define GREEN		"\033[32m"
# define BLUE		"\033[34m"
# define RED		"\033[31m"
# define YELLOW		"\033[33m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"

# define BG_RED		"\033[41m"
# define BG_YELLOW	"\033[43m"
# define BG_MAGENTA	"\033[45m"
# define BG_CYAN	"\033[46m"

#define RESET		"\033[0m"

# include <iostream>
# include <fstream>
# include <map>
# include <cstdlib>
# include <string>
# include <ctime>
# include <cctype>
# include <cstring> // memset

class BitcoinExchange
{
	private:
		std::map<std::string, float> _db;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void readDb();
		void parsePush(const std::string &line);
		void readParse(const char *file);

		bool checkDate(const std::string &date);
		float checkValue(const std::string &value);
		void findValue(const std::string &date, const std::string &value);
};

#endif // BITCOIN_EXCHANGE_HPP