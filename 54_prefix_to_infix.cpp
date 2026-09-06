#include <iostream>
#include <stack>
using namespace std;

string prefixToInfix(string prefix) {

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

            string result =
                "(" + operand1 + c + operand2 + ")";

            st.push(result);
        }
    }

    return st.top();
}

int main() {

    string prefix;

    cout << "Enter prefix expression: ";
    cin >> prefix;

    cout << "Infix expression: "
         << prefixToInfix(prefix);

    return 0;
}