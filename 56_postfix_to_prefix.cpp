#include <iostream>
#include <stack>
using namespace std;

string postfixToPrefix(string postfix) {

    stack<string> st;

    for (char c : postfix) {

        if (isalnum(c)) {
            st.push(string(1, c));
        }
        else {

            string operand2 = st.top();
            st.pop();

            string operand1 = st.top();
            st.pop();

            string result =
                string(1, c) + operand1 + operand2;

            st.push(result);
        }
    }

    return st.top();
}

int main() {

    string postfix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    cout << "Prefix expression: "
         << postfixToPrefix(postfix);

    return 0;
}