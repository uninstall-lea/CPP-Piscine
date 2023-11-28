#include <iostream>
#include <stack>
#include <cstdlib>
#include <sstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }

    std::stack<double> s;
    std::istringstream iss(argv[1]);
    std::string token;

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (s.size() < 2) {
                std::cerr << "Error: insufficient values in expression." << std::endl;
                return 1;
            }
            double right = s.top();
            s.pop();
            double left = s.top();
            s.pop();
            switch (token[0]) {
                case '+': s.push(left + right); break;
                case '-': s.push(left - right); break;
                case '*': s.push(left * right); break;
                case '/':
                    if (right == 0) {
                        std::cerr << "Error: division by zero." << std::endl;
                        return 1;
                    }
                    s.push(left / right);
                    break;
            }
        } else {
            s.push(atof(token.c_str()));
        }
    }

    if (s.size() != 1) {
        std::cerr << "Error: too many values provided." << std::endl;
        return 1;
    }

    std::cout << s.top() << std::endl;

    return 0;
}