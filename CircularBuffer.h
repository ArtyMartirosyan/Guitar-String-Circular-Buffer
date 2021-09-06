// Artyom Martirosyan Copyright 2021
#pragma once

#include <iostream>
#include <vector>



class CircularBuffer {
 public:
    CircularBuffer();
    explicit CircularBuffer(int);

    int bufferSize() const;
    bool isEmpty();
    bool isFull();
    void enqueue(int16_t x);
    int16_t dequeue();
    int16_t peek();
    std::string out() const;
 private:
    std::vector<int16_t> buffer;
    int size;
    int capacity;
    int firstElement;
    int lastElement;
};
