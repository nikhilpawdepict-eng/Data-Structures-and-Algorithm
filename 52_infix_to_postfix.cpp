#include <iostream>
#include <stack>
using namespace std;

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;

    return 0;
}

string infixToPostfix(string infix) {

    stack<char> st;
    string postfix;

    for (char c : infix) {

        // Operand
        if (isalnum(c)) {
            postfix += c;
        }

        // Opening bracket
        else if (c == '(') {
            st.push(c);
        }

        // Closing bracket
        else if (c == ')') {

            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }

            st.pop();
        }

        // Operator
        else {

            while (!st.empty() &&
                   st.top() != '(' &&
                   precedence(st.top()) >= precedence(c)) {

                postfix += st.top();
                st.pop();
            }

            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {

    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix expression: "
         << infixToPostfix(infix);

    return 0;
}