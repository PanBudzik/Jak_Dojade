#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front, rear, capacity;

public:
    Queue(int size);
    ~Queue();
    void push(int x);
    int pop();
    int toString();
    bool isEmpty();
    bool isFull();
};

#endif
