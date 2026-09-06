#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

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

int evaluatePostfix(string postfix) {

    stack<int> st;

    for (char c : postfix) {

        if (isdigit(c)) {

            st.push(c - '0');
        }

        else {

            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            int result = applyOperation(a, b, c);

            st.push(result);
        }
    }

    return st.top();
}

int main() {

    string postfix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    cout << "Result: "
         << evaluatePostfix(postfix);

    return 0;
}