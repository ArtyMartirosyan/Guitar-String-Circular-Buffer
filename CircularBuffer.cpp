// Artyom Martirosyan Copyright 2021
#include <stdexcept>
#include <sstream>
#include <string>
#include "CircularBuffer.h"

CircularBuffer::CircularBuffer() {
    capacity = 0;
    firstElement = 0;
    lastElement = 0;
    size = 0;
}

CircularBuffer::CircularBuffer(int newCapacity) {
    if (newCapacity <= 0) {
        throw std::invalid_argument("Capacity must be greater than zero.");
    }

    buffer.resize(newCapacity, 0);

    capacity = newCapacity;
    firstElement = 0;
    lastElement = 0;
    size = 0;
}

int CircularBuffer::bufferSize() const {
    return size;
}

bool CircularBuffer::isEmpty() {
    return (size == 0);
}

bool CircularBuffer::isFull() {
    return (size == capacity);
}

void CircularBuffer::enqueue(int16_t x) {
    if (isFull()) {
        throw std::runtime_error("Can't enqueue to a full ring. ");
    }

    if (lastElement == capacity - 1)
        lastElement = 0;
    else
        lastElement++;
    buffer[lastElement] = x;
    size++;
}


int16_t CircularBuffer::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error(" Can't dequeue to an empty ring. ");
    }
    int16_t value = peek();
    if (firstElement == capacity - 1)
        firstElement = 0;
    else
        firstElement++;
    size--;
    return value;
}

int16_t CircularBuffer::peek() {
    if (isEmpty()) {
        throw std::runtime_error(" Buffer is empty ");
    }
    if (firstElement >= capacity) {
        std::stringstream ss;
        ss << "firstElement >= capacity, firstElement: "
            << firstElement << ", capacity: " << capacity;
        throw std::runtime_error(ss.str());
    }
    return buffer[firstElement];
}


std::string CircularBuffer::out() const {
    std::stringstream ss;
    ss << "firstel: " << firstElement << ", lastel: " << lastElement
    << ", capacity: " << capacity << ", size: " << size <<std::endl;
    for (int i=firstElement; i<= lastElement; i++)
        ss << buffer[i] << ",";
    ss<< std::endl;

    return ss.str();
}
