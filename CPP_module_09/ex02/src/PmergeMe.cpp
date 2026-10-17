#include "PmergeMe.hpp"

namespace
{
    struct FJItem
    {
        int value;
        size_t id;

        FJItem(int v, size_t i) : value(v), id(i) {}
    };

    struct FJPair
    {
        FJItem small;
        FJItem large;

        FJPair(const FJItem &a, const FJItem &b) : small(a), large(b) {}
    };

    std::vector<size_t> makeJacobsthalOrder(size_t size)
    {
        std::vector<size_t> order;

        if (size <= 1)
            return (order);

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

            last = high;
            if (last == size)
                break;
            // Saturate before the Jacobsthal recurrence can overflow.
            if (prev > (static_cast<size_t>(-1) - current) / 2)
            {
                current = size;
                continue;
            }
            size_t next = current + 2 * prev;
            prev = current;
            current = next;
        }
        return (order);
    }

    std::vector<FJItem> fordJohnsonRecursive(const std::vector<FJItem> &input)
    {
        if (input.size() <= 1)
            return (input);

        std::vector<FJPair> pairs;
        std::vector<FJItem> pending;
        std::vector<FJItem> mainChain;
        std::vector<FJItem> large;
        bool hasOdd = (input.size() % 2 != 0);

        // Create pairs with one value comparison per pair.
        for (size_t i = 0; i + 1 < input.size(); i += 2)
        {
            if (input[i].value <= input[i + 1].value)
                pairs.push_back(FJPair(input[i], input[i + 1]));
            else
                pairs.push_back(FJPair(input[i + 1], input[i]));
        }

        // Collect the larger elements.
        for (size_t i = 0; i < pairs.size(); ++i)
            large.push_back(pairs[i].large);

        // Recursively sort larger elements.
        large = fordJohnsonRecursive(large);

        // Restore pair associations using unique IDs.
        for (size_t i = 0; i < large.size(); ++i)
        {
            mainChain.push_back(large[i]);

            for (size_t j = 0; j < pairs.size(); ++j)
            {
                if (pairs[j].large.id == large[i].id)
                {
                    pending.push_back(pairs[j].small);
                    break;
                }
            }
        }

        // Include the unpaired element in the Jacobsthal schedule.
        if (hasOdd)
            pending.push_back(input.back());

        // Place b1 before a1 without another value comparison.
        mainChain.insert(mainChain.begin(), pending[0]);

        // Insert remaining elements in Jacobsthal order.
        std::vector<size_t> order =
            makeJacobsthalOrder(pending.size());

        for (size_t i = 0; i < order.size(); ++i)
        {
            size_t index = order[i];
            size_t limit = mainChain.size();

            // Locate the matching a_i by identity, not by value.
            if (index < large.size())
            {
                for (size_t j = 0; j < mainChain.size(); ++j)
                {
                    if (mainChain[j].id == large[index].id)
                    {
                        limit = j;
                        break;
                    }
                }
            }

            // Search only the prefix before the matching partner.
            std::vector<FJItem>::iterator left = mainChain.begin();
            std::vector<FJItem>::iterator right =
                mainChain.begin() + limit;

            while (left < right)
            {
                std::vector<FJItem>::iterator mid =
                    left + (right - left) / 2;

                if (mid->value < pending[index].value)
                    left = mid + 1;
                else
                    right = mid;
            }
            mainChain.insert(left, pending[index]);
        }
        return (mainChain);
    }

    std::deque<FJItem> fordJohnsonDeque(const std::deque<FJItem> &input)
    {
        if (input.size() <= 1)
            return (input);

        std::deque<FJPair> pairs;
        std::deque<FJItem> pending;
        std::deque<FJItem> mainChain;
        std::deque<FJItem> large;
        bool hasOdd = (input.size() % 2 != 0);

        // Create pairs with one value comparison per pair.
        for (size_t i = 0; i + 1 < input.size(); i += 2)
        {
            if (input[i].value <= input[i + 1].value)
                pairs.push_back(FJPair(input[i], input[i + 1]));
            else
                pairs.push_back(FJPair(input[i + 1], input[i]));
        }

        // Collect the larger elements.
        for (size_t i = 0; i < pairs.size(); ++i)
            large.push_back(pairs[i].large);

        // Recursively sort larger elements.
        large = fordJohnsonDeque(large);

        // Restore pair associations using unique IDs.
        for (size_t i = 0; i < large.size(); ++i)
        {
            mainChain.push_back(large[i]);

            for (size_t j = 0; j < pairs.size(); ++j)
            {
                if (pairs[j].large.id == large[i].id)
                {
                    pending.push_back(pairs[j].small);
                    break;
                }
            }
        }

        // Include the unpaired element in the Jacobsthal schedule.
        if (hasOdd)
            pending.push_back(input.back());

        // Place b1 before a1 without another value comparison.
        mainChain.insert(mainChain.begin(), pending[0]);

        // Insert remaining elements in Jacobsthal order.
        std::vector<size_t> order =
            makeJacobsthalOrder(pending.size());

        for (size_t i = 0; i < order.size(); ++i)
        {
            size_t index = order[i];
            size_t limit = mainChain.size();

            // Locate the matching a_i by identity, not by value.
            if (index < large.size())
            {
                for (size_t j = 0; j < mainChain.size(); ++j)
                {
                    if (mainChain[j].id == large[index].id)
                    {
                        limit = j;
                        break;
                    }
                }
            }

            // Search only the prefix before the matching partner.
            std::deque<FJItem>::iterator left = mainChain.begin();
            std::deque<FJItem>::iterator right =
                mainChain.begin() + limit;

            while (left < right)
            {
                std::deque<FJItem>::iterator mid =
                    left + (right - left) / 2;

                if (mid->value < pending[index].value)
                    left = mid + 1;
                else
                    right = mid;
            }
            mainChain.insert(left, pending[index]);
        }
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

    for (int i = 1; i < argc; ++i)
    {
        std::string str = argv[i];

        if (!isValidNumber(str))
            throw std::runtime_error("Invalid number");

        int num = std::atoi(str.c_str());

        _vector.push_back(num);
    }
}

void PmergeMe::parseDequeArguments(int argc, char **argv)
{
    _deque.clear();
    for (int i = 1; i < argc; ++i)
    {
        std::string str = argv[i];
        if (!isValidNumber(str))
            throw std::runtime_error("Invalid number");
        _deque.push_back(std::atoi(str.c_str()));
    }
}

// Ford-Johnson

void PmergeMe::sortVector()
{
    std::vector<FJItem> items;

    for (size_t i = 0; i < _vector.size(); ++i)
    {
        items.push_back(FJItem(_vector[i], i));
    }

    items = fordJohnsonRecursive(items);

    for (size_t i = 0; i < items.size(); ++i)
    {
        _vector[i] = items[i].value;
    }
}

void PmergeMe::sortDeque()
{
    std::deque<FJItem> items;

    for (size_t i = 0; i < _deque.size(); ++i)
        items.push_back(FJItem(_deque[i], i));

    items = fordJohnsonDeque(items);

    for (size_t i = 0; i < items.size(); ++i)
        _deque[i] = items[i].value;
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
    if (argc < 2)
        throw std::runtime_error("Missing arguments");

    // Exclude console output while including each container's data management.
    clock_t parseStart = std::clock();
    parseArguments(argc, argv);
    clock_t parseEnd = std::clock();
    printBefore();

    clock_t vectorStart = std::clock();
    sortVector();
    clock_t vectorEnd = std::clock();

    clock_t dequeStart = std::clock();
    parseDequeArguments(argc, argv);
    sortDeque();
    clock_t dequeEnd = std::clock();

    double vectorTime = (static_cast<double>(parseEnd - parseStart)
        + static_cast<double>(vectorEnd - vectorStart))
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
