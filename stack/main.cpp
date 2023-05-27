#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


//что stod ==>Разбирает str, интерпретируя его содержимое как число с плавающей запятой, которое возвращается как значение типа double.




double evaluate_expression(vector<string> pList) {
    // Преобразование списка в обратную польскую запись
    vector<string> output;
    vector<string> stack;
    unordered_map<string, int> priority = {{"+",1}, {"-",1}, {"*",2}, {"/",2}};
    for (auto token : pList) {
        if (isdigit(token[0])) {
            output.push_back(token);
        } else if (priority.find(token) != priority.end()) {
            while (!stack.empty() && priority.find(stack.back()) != priority.end() && priority[stack.back()] <= priority[token]) {
                output.push_back(stack.back());
                stack.pop_back();
            }
            stack.push_back(token);
        }
    }
    while (!stack.empty()) {
        output.push_back(stack.back());
        stack.pop_back();
    }

    // Вычисление значения выражения
    stack.clear();
    for (auto token : output) {
        if (isdigit(token[0])) {
            stack.push_back(token);
        } else {
            double b = stod(stack.back());
            stack.pop_back();
            double a = stod(stack.back());
            stack.pop_back();
                if (token == "+") {
                stack.push_back(to_string(a + b));
            } else if (token == "-") {
                stack.push_back(to_string(a - b));
            } else if (token == "*") {
                stack.push_back(to_string(a * b));
                } else if (token == "/") {
                stack.push_back(to_string(a / b));
            }
        }
    }

    return stod(stack.back());
}

int main() {
    vector<string> pList = {"3", "+", "4", "/", "5", "-", "6","*","3"};  
//vector<string> pList = {"1","+","2"};
//vector<string> pList = {"6","-","2"}; 
    double result = evaluate_expression(pList);
    cout << result << endl;  // Выводит -21
    return 0;
}












#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

int getPriority(char op) {
    if (op == '*' || op == '/') {
        return 1;
    } else if (op == '+' || op == '-') {
        return 2;
    } else {
        return 0;
    }
}

string toRPN(string expression) {
    stack<char> operators;
    string result = "";

    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];

        if (isdigit(c)) {
            result += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                result += operators.top();
                operators.pop();
            }
            operators.pop();
        } else {
            while (!operators.empty() && getPriority(operators.top()) >= getPriority(c)) {
                result += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        result += operators.top();
        operators.pop();
    }

    return result;
}

string addBrackets(string rpn) {
     stack<string> operands;

    for (int i = 0; i < rpn.length(); i++) {
        char c = rpn[i];

        if (isdigit(c)) {
            operands.push(string(1, c));
        } else {
            string op2 = operands.top();
            operands.pop();
            string op1 = operands.top();
            operands.pop();
            operands.push("(" + op1 + c + op2 + ")");
        }
    }

    return operands.top();
}

int main() {
    string expression = "2+3*4/1-5";
    string rpn = toRPN(expression);
    string result = addBrackets(rpn);

    cout << result << endl;

    return 0;
}









