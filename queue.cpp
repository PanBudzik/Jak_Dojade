#include "Queue.h"


    Queue::Queue(int size) {
        arr = new int[size];
        capacity = size;
        front = rear = -1;
    }

    Queue::~Queue() {
        delete[] arr;
    }

    void Queue::push(int x) {
        if (isFull()) {
            int newCapacity = capacity * 2;
            int* newArr = new int[newCapacity];
            int j = 0;
            for (int i = front; i != rear; i = (i + 1) % capacity) {
                newArr[j] = arr[i];
                j++;
            }
            newArr[j] = arr[rear];
            front = 0;
            rear = j;
            capacity = newCapacity;
            delete[] arr;
            arr = newArr;
        }
        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % capacity;
        arr[rear] = x;
    }

    int Queue::pop() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int removedValue = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % capacity;
        return removedValue;
    }

    int Queue::toString() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int result = 0;
        for (int i = front; i <= rear; i++)
        {
            result += arr[i];
        }
        return result;
    }

    bool Queue::isEmpty() {
        return front == -1 && rear == -1;
    }

    bool Queue::isFull() {
        return (rear + 1) % capacity == front;
    }