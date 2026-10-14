#include "PmergeMe.hpp"

namespace
{
    template <typename Container>
    // done 
    void binaryInsert(Container &container, int value, size_t limit)
    {
        typename Container::iterator left = container.begin();

        // typename Container::iterator right = container.end();
        typename Container::iterator right = container.begin() + limit;

        while (left < right)
        {
            typename Container::iterator mid = left + (right - left) / 2;

            if (*mid < value)
                left = mid + 1;
            else
                right = mid;
        }
        container.insert(left, value);
    }

    // done
    std::vector<size_t> makeJacobsthalOrder(size_t size)
    {
        std::vector<size_t> order;

        if (size <= 1)
            return (order);

        // order.push_back(0); // b1 уже находится в mainChain

        size_t prev = 1;
        size_t current = 3;
        size_t last = 1;

        while (last < size)
        {
            size_t high = current;

            if (high > size)
                high = size;
            for (size_t i = high; i > last; --i)
                order.push_back(i - 1);

            size_t next = current + 2 * prev;
            prev = current;
            current = next;
            last = high;
        }
        return (order);
    }

    std::vector<int> fordJohnsonVector(const std::vector<int> &input)
    {
        if (input.size() <= 1)
            return (input);

        std::vector<std::pair<int, int> > pairs;
        std::vector<int> pending;
        std::vector<int> mainChain;
        bool hasOdd = false;
        int odd = 0;

        for (size_t i = 0; i + 1 < input.size(); i += 2)
        {
            if (input[i] < input[i + 1])
                pairs.push_back(std::make_pair(input[i], input[i + 1]));
            else
                pairs.push_back(std::make_pair(input[i + 1], input[i]));
        }

        if (input.size() % 2 != 0)
        {
            odd = input.back();
            hasOdd = true;
        }

        for (size_t i = 0; i < pairs.size(); ++i)
        {
            pending.push_back(pairs[i].first);
            mainChain.push_back(pairs[i].second);
        }

        mainChain = fordJohnsonVector(mainChain);

        std::vector<size_t> order = makeJacobsthalOrder(pending.size());
        for (size_t i = 0; i < order.size(); ++i)
            binaryInsert(mainChain, pending[order[i]]);

        if (hasOdd)
            binaryInsert(mainChain, odd);

        return (mainChain);
    }

    std::deque<int> fordJohnsonDeque(const std::deque<int> &input)
    {
        if (input.size() <= 1)
            return (input);

        std::deque<std::pair<int, int> > pairs;
        std::deque<int> pending;
        std::deque<int> mainChain;
        bool hasOdd = false;
        int odd = 0;

        for (size_t i = 0; i + 1 < input.size(); i += 2)
        {
            if (input[i] < input[i + 1])
                pairs.push_back(std::make_pair(input[i], input[i + 1]));
            else
                pairs.push_back(std::make_pair(input[i + 1], input[i]));
        }

        if (input.size() % 2 != 0)
        {
            odd = input.back();
            hasOdd = true;
        }

        for (size_t i = 0; i < pairs.size(); ++i)
        {
            pending.push_back(pairs[i].first);
            mainChain.push_back(pairs[i].second);
        }

        mainChain = fordJohnsonDeque(mainChain);

        std::vector<size_t> order = makeJacobsthalOrder(pending.size());
        for (size_t i = 0; i < order.size(); ++i)
            binaryInsert(mainChain, pending[order[i]]);

        if (hasOdd)
            binaryInsert(mainChain, odd);

        return (mainChain);
    }
}

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
    _vector = fordJohnsonVector(_vector);
}

void PmergeMe::sortPairsVector(std::vector<std::pair<int, int> > &pairs)
{
    for (size_t i = 1; i < pairs.size(); ++i)
    {
        std::pair<int, int> key = pairs[i];
        size_t j = i;

        while (j > 0 && pairs[j - 1].second > key.second)
        {
            pairs[j] = pairs[j - 1];
            --j;
        }
        pairs[j] = key;
    }
}

void PmergeMe::sortDeque()
{
    _deque = fordJohnsonDeque(_deque);
}

// Binary insertion

void PmergeMe::binaryInsertVector(int value)
{
    binaryInsert(_vector, value);
}

void PmergeMe::binaryInsertDeque(int value)
{
    binaryInsert(_deque, value);
}

// Jacobsthal sequence

std::vector<size_t> PmergeMe::generateJacobsthal(size_t size)
{
    return (makeJacobsthalOrder(size));
}

// Output

void PmergeMe::printBefore() const
{
    std::cout << "Before:";

    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout << " " << _vector[i];
    std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
    std::cout << "After:";

    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout << " " << _vector[i];
    std::cout << std::endl;
}

// Main execution

void PmergeMe::run(int argc, char **argv)
{
    parseArguments(argc, argv);
    printBefore();

    clock_t vectorStart = std::clock();
    sortVector();
    clock_t vectorEnd = std::clock();

    clock_t dequeStart = std::clock();
    sortDeque();
    clock_t dequeEnd = std::clock();

    double vectorTime = static_cast<double>(vectorEnd - vectorStart)
        * 1000000.0 / CLOCKS_PER_SEC;
    double dequeTime = static_cast<double>(dequeEnd - dequeStart)
        * 1000000.0 / CLOCKS_PER_SEC;

    printAfter();
    std::cout << "Time to process a range of " << _vector.size()
              << " elements with std::vector: " << std::fixed
              << std::setprecision(5) << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size()
              << " elements with std::deque:  " << std::fixed
              << std::setprecision(5) << dequeTime << " us" << std::endl;
}