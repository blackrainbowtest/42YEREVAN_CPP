#include "RPN.hpp"

int main(int argc, char **argv)
{
    // 1. Check the number of arguments
    if (argc != 2)
    {
        std::cerr << "Error: invalid arguments" << std::endl;
        return (1);
    }

    // 2. Create RPN object and evaluate expression
    try
    {
        RPN rpn;
        rpn.evaluate(argv[1]);
    }
    // 3. Catch and display errors
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}