#include "PmergeMe.hpp"

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
// Done:
// - Input validation and parsing fill both containers.
// - Vector pair formation stores each pair as (smaller, bigger).
// - Odd element is remembered separately.
// - Basic binary insertion into _vector exists.
//
// Remaining vector steps:
// - Sort pairs by their bigger element (pair.second).
// - Build main chain from pair.second values.
// - Build pending list from pair.first values.
// - Insert the first pending element at the beginning of the main chain.
// - Generate Jacobsthal insertion order for the remaining pending elements.
// - Insert pending elements with bounded binary insertion.
// - Insert the odd element, if there is one.
// - Store the final main chain back into _vector.
//
// Remaining project steps:
// - Repeat the algorithm for std::deque.
// - Implement run() with timing for both containers.
// - Compile with C++98 and test 3000+ values, including duplicates.

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

    // TODO: sortPairsVector(pairs);
    // TODO: create mainChain from pairs[i].second values.
    // TODO: create pendingElements from pairs[i].first values.
    // TODO: move mainChain into _vector before inserting.
    // TODO: insert pendingElements in Jacobsthal order.
    // TODO: insert odd if hasOdd is true.
    // TODO: assign the final sorted chain to _vector.
    (void)pairs;
    (void)odd;
    (void)hasOdd;
}

void PmergeMe::sortPairsVector(std::vector<std::pair<int, int> > &pairs)
{
    // TODO: Sort pairs by pairs[i].second in ascending order.
    // This keeps each smaller value attached to its original bigger partner.
    (void)pairs;
}

void PmergeMe::sortDeque()
{
    // TODO: Implement the same Ford-Johnson steps as sortVector(),
    // but using std::deque and deque iterators/insert operations.
}

// Binary insertion

void PmergeMe::binaryInsertVector(int value)
{
    // TODO later: add an overload/helper that can limit the right boundary.
    // Ford-Johnson should only search up to the paired bigger element.
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
    // TODO: Same binary insertion idea as vector, but for _deque.
    // TODO later: support bounded insertion for Ford-Johnson.
    (void)value;
}

// Jacobsthal sequence

std::vector<size_t> PmergeMe::generateJacobsthal(size_t size)
{
    // TODO: Return pending-element indexes in Jacobsthal insertion order.
    // Example goal: cover every index from 0 to size - 1 exactly once.
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
    // TODO: parseArguments(argc, argv);
    // TODO: printBefore();
    // TODO: copy initial containers if needed before timing.
    // TODO: measure sortVector() time in microseconds.
    // TODO: measure sortDeque() time in microseconds.
    // TODO: printAfter();
    // TODO: print vector and deque timings in the subject format.
    (void)argc;
    (void)argv;
}