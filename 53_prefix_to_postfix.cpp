#include <iostream>
#include <stack>
using namespace std;

string prefixToPostfix(string prefix) {

    stack<string> st;

    for (int i = prefix.length() - 1; i >= 0; i--) {

        char c = prefix[i];

        if (isalnum(c)) {
            st.push(string(1, c));
        }
        else {

            string operand1 = st.top();
            st.pop();

            string operand2 = st.top();
            st.pop();

            string result = operand1 + operand2 + c;

            st.push(result);
        }
    }

    return st.top();
}

int main() {

    string prefix;

    cout << "Enter prefix expression: ";
    cin >> prefix;

    cout << "Postfix expression: "
         << prefixToPostfix(prefix);

    return 0;
}