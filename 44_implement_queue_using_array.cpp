#include <iostream>
using namespace std;

#define MAX 100

class Queue {
private:
    int arr[MAX];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Enqueue
    void enqueue(int value) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        arr[rear] = value;

        cout << value << " inserted into queue.\n";
    }

    // Dequeue
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << arr[front] << " removed from queue.\n";
        front++;

        // Reset queue when it becomes empty
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    // Peek
    void peek() {
        if (front == -1) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Front element: " << arr[front] << endl;
    }

    // Is Empty
    bool isEmpty() {
        return front == -1;
    }

    // Is Full
    bool isFull() {
        return rear == MAX - 1;
    }

    // Display
    void display() {
        if (front == -1) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    Queue q;

    int choice, value;

    do {
        cout << "\n--- QUEUE MENU ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
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
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            if (q.isEmpty())
                cout << "Queue is empty.\n";
            else
                cout << "Queue is not empty.\n";
            break;

        case 5:
            if (q.isFull())
                cout << "Queue is full.\n";
            else
                cout << "Queue is not full.\n";
            break;

        case 6:
            q.display();
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