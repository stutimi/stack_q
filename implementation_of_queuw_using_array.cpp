#include <iostream>
using namespace std;

class Queue {
public:
    int capacity;
    int front;
    int rear;
    int* arr;

    // Constructor to initialize the queue
Queue(int capacity) {
        this->capacity = capacity;
arr = new int[capacity];
        front = -1; // Set front to -1 indicating an empty queue
        rear = -1;  // Set rear to -1 indicating an empty queue
    }

    // Enqueue: Add an element to the queue
    void push(int element) {
        if (rear + 1 < capacity) { // Check if there's space in the queue
            if (front == -1) { // If queue is empty
                front = 0;     // Initialize front
            }
            rear++;
arr[rear] = element;
        } else {
cout<< "Queue Overflow" <<endl;
        }
    }

    // Dequeue: Remove an element from the queue
    void pop() {
        if (front >= 0) {
            // If there's only one element, reset front and rear
            if (front == rear) {
                front = rear = -1; // Reset to indicate queue is empty
            } else {
                front++;
            }
        } else {
cout<< "Queue Underflow" <<endl;
        }
    }

    // Peek: Get the front element of the queue
    int peek() {
        if (front >= 0) {
            return arr[front];
        } else {
            return -1; // Indicate that the queue is empty
        }
    }

    // Destructor to free allocated memory
    ~Queue() {
delete[] arr;
    }
};

int main() {
    Queue q(5); // Initialize queue with a capacity of 5
q.push(10);
q.push(20);
q.push(30);

cout<< "Front element: " <<q.peek() <<endl; // Should print 10

q.pop(); // Remove 10
cout<< "Front element after pop: " <<q.peek() <<endl; // Should print 20

    return 0;
}