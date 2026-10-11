#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <climits>
#include <ctime>
#include <cstdlib>
#include <cerrno>
#include <cctype>
#include <utility>

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

void PmergeMe::sortVector()
{
    if (_vector.size() <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;

    for (size_t i = 0; i + 1 < _vector.size(); i += 2)
    {
        if (_vector[i] < _vector[i + 1])
            pairs.push_back(std::make_pair(_vector[i], _vector[i + 1]));
        else
            pairs.push_back(std::make_pair(_vector[i + 1], _vector[i]));
    }
}

void PmergeMe::sortDeque()
{
    // TODO: Ford-Johnson using deque
}

// Binary insertion

void PmergeMe::binaryInsertVector(int value)
{
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
    // TODO: Binary insertion
    (void)value;
}

// Jacobsthal sequence

std::vector<size_t> PmergeMe::generateJacobsthal(size_t size)
{
    // TODO: Generate insertion order
    (void)size;
    return (std::vector<size_t>());
}

// Output

void PmergeMe::printBefore() const
{
    // TODO: Print original sequence

    std::cout << "Before:";

    for (size_t i = 0; i < _vector.size(); ++i)
    {
        std::cout << " " << _vector[i];
    }
    std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
    // TODO: Print sorted sequence

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
    // TODO: Parse arguments
    // TODO: Print Before
    // TODO: Measure vector processing time
    // TODO: Measure deque processing time
    // TODO: Print After
    // TODO: Print timings
    (void)argc;
    (void)argv;
}
