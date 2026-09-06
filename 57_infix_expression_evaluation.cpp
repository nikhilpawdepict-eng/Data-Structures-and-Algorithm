#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;

    if (op == '*' || op == '/')
        return 2;

    return 0;
}

int applyOperation(int a, int b, char op) {

    switch (op) {

    case '+':
        return a + b;

    case '-':
        return a - b;

    case '*':
        return a * b;

    case '/':
        return a / b;
    }

    return 0;
}

int evaluate(string expression) {

    stack<int> values;
    stack<char> operators;

    for (int i = 0; i < expression.length(); i++) {

        char c = expression[i];

        if (isdigit(c)) {

            int num = 0;

            while (i < expression.length() &&
                   isdigit(expression[i])) {

                num = num * 10 + (expression[i] - '0');
                i++;
            }

            i--;

            values.push(num);
        }

        else if (c == '(') {
            operators.push(c);
        }

        else if (c == ')') {

            while (!operators.empty() &&
                   operators.top() != '(') {

                int b = values.top();
                values.pop();

                int a = values.top();
                values.pop();

                char op = operators.top();
                operators.pop();

                values.push(applyOperation(a, b, op));
            }

            operators.pop();
        }

        else {

            while (!operators.empty() &&
                   operators.top() != '(' &&
                   precedence(operators.top()) >= precedence(c)) {

                int b = values.top();
                values.pop();

                int a = values.top();
                values.pop();

                char op = operators.top();
                operators.pop();

                values.push(applyOperation(a, b, op));
            }

            operators.push(c);
        }
    }

    while (!operators.empty()) {

        int b = values.top();
        values.pop();

        int a = values.top();
        values.pop();

        char op = operators.top();
        operators.pop();

        values.push(applyOperation(a, b, op));
    }

    return values.top();
}

int main() {

    string expression;

    cout << "Enter expression: ";
    cin >> expression;

    cout << "Result: "
         << evaluate(expression);

    return 0;
}