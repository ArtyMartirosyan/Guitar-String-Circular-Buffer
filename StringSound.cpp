// Artyom Martirosyan Copyright 2021

#include <iostream>
#include <cmath>

#include "StringSound.h"

#define SAMP_RATE 44100
#define ENERGY_DECAY_FACTOR 0.996

StringSound::StringSound() {
    _time = 0;
}

StringSound::StringSound(double frequency) {
    _time = 0;
    cb = new CircularBuffer(ceil(SAMP_RATE/frequency));
}

StringSound::StringSound(vector<sf::Int16> init) {
    cb = new CircularBuffer(init.size());
    for (int i = 0; i < static_cast<int>(init.size()); i++) {
        cb->enqueue(init[i]);
    }
    _time = 0;
}

StringSound::~StringSound() {
    delete cb;
}

void StringSound::pluck() {
    while (!(cb->isEmpty())) {
        cb->dequeue();
    }
    while (!(cb->isFull())) {
        cb->enqueue((sf::Int16) (rand() & 0xffff));
    }
}

void StringSound::tic() {
    int a = cb->dequeue();
    int b = cb->peek();
    cb->enqueue((sf::Int16)(ENERGY_DECAY_FACTOR * ((a + b) / 2)));
    _time++;
}

sf::Int16 StringSound::sample() {
    return cb->peek();
}

int StringSound::time() {
    return _time;
}
