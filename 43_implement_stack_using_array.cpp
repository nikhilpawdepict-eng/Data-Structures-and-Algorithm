#include <iostream>
using namespace std;

#define MAX 100

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Push element
    void push(int value) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }

        top++;
        arr[top] = value;

        cout << value << " pushed into stack.\n";
    }

    // Pop element
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }

        cout << arr[top] << " popped from stack.\n";
        top--;
    }

    // Peek
    void peek() {
        if (top == -1) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Top element: " << arr[top] << endl;
    }

    // Check empty
    bool isEmpty() {
        return top == -1;
    }

    // Check full
    bool isFull() {
        return top == MAX - 1;
    }

    // Display
    void display() {
        if (top == -1) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack elements: ";

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    Stack s;

    int choice, value;

    do {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check Empty\n";
        cout << "5. Check Full\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            if (s.isEmpty())
                cout << "Stack is empty.\n";
            else
                cout << "Stack is not empty.\n";
            break;

        case 5:
            if (s.isFull())
                cout << "Stack is full.\n";
            else
                cout << "Stack is not full.\n";
            break;

        case 6:
            s.display();
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}