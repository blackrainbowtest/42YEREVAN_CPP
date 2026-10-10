#ifndef PMERGEME_HPP
# define PMERGEME_HPP

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

# include <vector>
# include <deque>

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;

        // Parsing and validation
        bool isValidNumber(const std::string &str) const;
        void parseArguments(int argc, char **argv);

        // Ford-Johnson algorithm
        void sortVector();
        void sortDeque();

        // Binary insertion
        void binaryInsertVector(int value);
        void binaryInsertDeque(int value);

        // Jacobsthal sequence
        std::vector<size_t> generateJacobsthal(size_t size);

        // Output
        void printBefore() const;
        void printAfter() const;

	public:
	    PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void run(int argc, char **argv);

};


#endif // PMERGEME_HPP