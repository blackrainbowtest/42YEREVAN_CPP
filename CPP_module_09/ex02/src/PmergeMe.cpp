#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <climits>
#include <ctime>

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
        if (!std::isdigit(str[i]))
            return (false);
    }

    char *endptr;
    errno = 0;
    long value = std::strtol(str.c_str(), &endptr, 10);

    if (errno == ERANGE || *endptr != '\0' || value < 0 || value > INT_MAX)
        return (false);
    return (true);
}

void PmergeMe::parseArguments(int argc, char **argv)
{
    // TODO: Validate and fill both containers
    (void)argc;
    (void)argv;
}

// Ford-Johnson

void PmergeMe::sortVector()
{
    // TODO: Ford-Johnson using vector
}

void PmergeMe::sortDeque()
{
    // TODO: Ford-Johnson using deque
}

// Binary insertion

void PmergeMe::binaryInsertVector(int value)
{
    // TODO: Binary insertion
    (void)value;
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
}

void PmergeMe::printAfter() const
{
    // TODO: Print sorted sequence
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
