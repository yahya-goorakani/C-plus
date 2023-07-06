#include<iostream>

void func();

int main() {
        func();
        func();
        func();

        std::cin.get();
        return 0;
}
void func() {
        static int x = 0;
        ++x;
        std::cout<< "x = "<< x <<std::endl;
}






#include <iostream>

#define MAX_SIZE 1000

class Stack {
private:
    int top;    int arr[MAX_SIZE];
public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top >= MAX_SIZE - 1) {
            std::cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (top < 0) {
            std::cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int peek() {
        if (top < 0) {
            std::cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top < 0;
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << s.peek() << "\n";
    s.pop();
    std::cout << s.peek() << "\n";
    s.pop();
    std::cout << s.peek() << "\n";
    s.pop();
    std::cout << s.isEmpty() << "\n";
    return 0;
}









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
