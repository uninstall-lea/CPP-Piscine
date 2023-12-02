#include "RPN.hpp"

/* ------------------------- Defining static members ------------------------ */
double RPNCalculator::left = 0;
double RPNCalculator::right = 0;
std::stack<double> RPNCalculator::stack;

/* ----------------------------- Error handling ----------------------------- */
// Check if the input is not a char '0' and if the result of atof is neither a positive or negative number.
// If true, then it's an invalid input.
bool	 RPNCalculator::isBadInput( const std::string& token ) {
	double value = std::atof(token.c_str());

	if ((token != "0" && value)	|| value < 0 || value > 10)
		return (false);
	return (true);
}

// Check if enough value have been received.
// At least 2 are needed to evaluate a mathematical expression.
// Only numbers < 10 allowed.
bool	 RPNCalculator::isValidExpression( void ) {

	return (stack.size() < 2 ? false : true);

}

bool	 RPNCalculator::isValidOperator( const std::string& token ) {
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

// Check if only 'res' is left in 'stack'.
// When all operations have been processed only the result is supposed to remain in 'stack' 
bool	RPNCalculator::isStackNotEmpty( void ) {

	return (stack.size() != 1 ? true : false);
}

/* ---------------------------------- Utils --------------------------------- */

void	 RPNCalculator::printResult( void ) {

	std::cout << stack.top() << std::endl;
}

/* ----------------------------- Core functions ----------------------------- */
// Compute the result of the operation and push it on the stack.
// 'op' defines the operation to be computed: '+', '-', '*', '/'.
void	RPNCalculator::performOperation( const char& op ) {

	right = stack.top();
    stack.pop();
    left = stack.top();
    stack.pop();

	switch (op) {
		case '+': stack.push(left + right); break;
		case '-': stack.push(left - right); break;
		case '*': stack.push(left * right); break;
		case '/':
			if (right == 0) 
				throw std::invalid_argument("Error => division by zero.");
			stack.push(left / right);
	} 
}

void	 RPNCalculator::reversePolishNotation(char *av1) {

    std::string			token;
    std::istringstream 	iss(av1);

    while (iss >> token)
	{

		if (isValidOperator(token)) {
			if (isValidExpression())
				performOperation(token[0]);
			else
				throw std::invalid_argument("Usage => At least 2 numbers '> 0 && < 10' expected.");
		}

		else if (isBadInput(token))
			throw std::invalid_argument("Error => bad input: " + token[0]);
		else
			stack.push(std::atof(token.c_str()));
	}

	if (isStackNotEmpty())
		throw std::invalid_argument("Error => bad input: must end with an operator, 10 value limited.");

	printResult();
}