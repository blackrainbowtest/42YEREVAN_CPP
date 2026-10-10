#ifndef RPN_HPP
# define RPN_HPP

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
# include <stack>
# include <cstring>
# include <sstream>
# include <cstdlib>

class RPN
{
	private:
		std::stack<int> _stack;
		// isOperand()	Проверяет, является ли символ цифрой от 0 до 9
		bool isOperand(char c);
		// isOperator()	Проверяет, является ли символ одним из + - * /
		bool isOperator(char c);
		// calcOperation()	Вычисляет результат операции над двумя числами
		int calcOperation(int a, int b, char op);
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		void evaluate(const std::string &expression);

};


#endif // RPN_HPP