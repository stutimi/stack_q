#include <iostream>
using namespace std;

class Stack {
public:
    int capacity;
    int top;
    int* arr;

    // Constructor to initialize stack
    Stack(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity]; // Allocate memory for the array
        top = -1; // Stack is initially empty
    }

    // Destructor to free memory
    ~Stack() {
        delete[] arr; // Deallocate memory
    }

    // Push method to add element to the stack
    void push(int element) {
        if (top < capacity - 1) { // Check if stack is not full
            top++;
            arr[top] = element;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    // Pop method to remove the top element from the stack
    void pop() {
        if (top >= 0) {
            top--;
        } else {
            cout << "Stack Underflow" << endl;
        }
    }

    // Peek method to get the top element of the stack
    int peek() {
        if (top >= 0) {
            return arr[top];
        } else {
            return -1; // Indicate that the stack is empty
        }
    }
};

int main() {
    Stack st(5); // Stack with capacity of 5
    st.push(23);
    st.push(24);
    st.push(25);

    cout << st.peek() << endl; // Output: 25
    st.pop();
    cout << st.peek() << endl; // Output: 24

    return 0;
}
