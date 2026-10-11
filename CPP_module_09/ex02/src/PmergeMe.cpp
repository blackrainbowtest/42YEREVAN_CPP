#include "PmergeMe.hpp"

/*
    CPP Module 09 - ex02: PmergeMe

    Obiasnenie proekta:
    - programma prinimaet positive integers iz command-line arguments;
    - odna i ta zhe posledovatelnost hranitsia v std::vector i std::deque;
    - obe posledovatelnosti dolzhny sortirovatsia algoritmom Ford-Johnson;
    - nuzhno vyvesti Before, After i vremia obrabotki dlia kazhdogo container.

    Chto uzhe sdelano:
    - Orthodox Canonical Form;
    - proverka positive int v isValidNumber();
    - parsing argumentov v parseArguments();
    - vyvod Before/After;
    - pervyi shag sortVector(): formirovanie par (smaller, bigger);
    - sohranenie odd element pri nechetnom kolichestve chisel;
    - prostaya binary insertion v _vector.

    Chto poka ostavleno kommentariiami:
    - recursive Ford-Johnson sorting;
    - preserve pair/group relationships during recursion;
    - build main chain and pending elements;
    - Jacobsthal insertion order;
    - bounded binary insertion;
    - std::deque version;
    - run() with timing.
*/

// Orthodox Canonical Form

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}

// Parsing and validation

bool PmergeMe::isValidNumber(const std::string &str) const
{
    if (str.empty())
        return (false);

    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return (false);
    }

    char *endptr;
    errno = 0;
    long value = std::strtol(str.c_str(), &endptr, 10);

    if (errno == ERANGE || *endptr != '\0' || value <= 0 || value > INT_MAX)
        return (false);
    return (true);
}

void PmergeMe::parseArguments(int argc, char **argv)
{
    _vector.clear();
    _deque.clear();

    for (int i = 1; i < argc; ++i)
    {
        std::string str = argv[i];

        if (!isValidNumber(str))
            throw std::runtime_error("Invalid number");

        int num = std::atoi(str.c_str());

        _vector.push_back(num);
        _deque.push_back(num);
    }
}

// Ford-Johnson
// This is the beginning of merge-insertion sort.
// Current implemented step: split numbers into pairs.
// Each pair is stored as (smaller, bigger), so the relationship is preserved.

void PmergeMe::sortVector()
{
    if (_vector.size() <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;

    int odd = 0;
    bool hasOdd = false;

    for (size_t i = 0; i + 1 < _vector.size(); i += 2)
    {
        if (_vector[i] < _vector[i + 1])
            pairs.push_back(std::make_pair(_vector[i], _vector[i + 1]));
        else
            pairs.push_back(std::make_pair(_vector[i + 1], _vector[i]));
    }

    if (_vector.size() % 2 != 0)
    {
        odd = _vector.back();
        hasOdd = true;
    }

    // Next steps:
    // 1. Sort pairs by second, meaning by the bigger element.
    // 2. Create mainChain from pairs[i].second.
    // 3. Create pendingElements from pairs[i].first.
    // 4. Move mainChain into _vector.
    // 5. Insert pendingElements in Jacobsthal order.
    // 6. Use bounded binary search for each insertion.
    // 7. If hasOdd == true, insert odd.
    // 8. After all insertions, _vector must be sorted.
    (void)pairs;
    (void)odd;
    (void)hasOdd;
}

void PmergeMe::sortPairsVector(std::vector<std::pair<int, int> > &pairs)
{
    // Sort pairs by pairs[i].second in ascending order.
    // Important: sort whole pairs, not only second values.
    // Otherwise the smaller value loses its bigger partner.
    //
    // Example:
    // Before: (3, 8) (2, 7) (1, 5)
    // After:  (1, 5) (2, 7) (3, 8)
    //
    // Insertion sort is a simple C++98-friendly first implementation.
    (void)pairs;
}

void PmergeMe::sortDeque()
{
    // Same logic as sortVector(), but for std::deque.
    // Steps:
    // 1. Form deque pairs.
    // 2. Sort pairs by bigger element.
    // 3. Build main chain and pending elements.
    // 4. Insert pending elements in Jacobsthal order.
    // 5. Insert odd element if it exists.
}

// Binary insertion

void PmergeMe::binaryInsertVector(int value)
{
    // Current version: normal binary insertion into the whole _vector.
    // Later Ford-Johnson needs an overload/helper with a right search boundary.
    size_t left = 0;
    size_t right = _vector.size();

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;

        if (_vector[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }

    _vector.insert(_vector.begin() + left, value);
}

void PmergeMe::binaryInsertDeque(int value)
{
    // Binary insertion for _deque will go here.
    // Start with the same idea as binaryInsertVector().
    // Later add bounded insertion for Ford-Johnson.
    (void)value;
}

// Jacobsthal sequence

std::vector<size_t> PmergeMe::generateJacobsthal(size_t size)
{
    // Return pendingElements indexes in Jacobsthal insertion order.
    // Goal: every index from 0 to size - 1 appears exactly once.
    // Jacobsthal numbers: 1, 3, 5, 11, 21...
    (void)size;
    return (std::vector<size_t>());
}

// Output

void PmergeMe::printBefore() const
{
    std::cout << "Before:";

    for (size_t i = 0; i < _vector.size(); ++i)
    {
        std::cout << " " << _vector[i];
    }
    std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
    std::cout << "After:";

    for (size_t i = 0; i < _vector.size(); ++i)
    {
        std::cout << " " << _vector[i];
    }
    std::cout << std::endl;
}

// Main execution

void PmergeMe::run(int argc, char **argv)
{
    // Final order:
    // 1. parseArguments(argc, argv);
    // 2. printBefore();
    // 3. Measure sortVector() time in microseconds.
    // 4. Measure sortDeque() time in microseconds.
    // 5. printAfter();
    // 6. Print vector/deque timings in the subject format.
    //
    // parseArguments() already fills both containers with the same numbers,
    // so vector and deque can be sorted independently.
    (void)argc;
    (void)argv;
}