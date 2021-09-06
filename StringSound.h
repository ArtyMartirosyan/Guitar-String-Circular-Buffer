#pragma once

#include <iostream>
#include <vector>

#include <SFML/Audio/SoundBuffer.hpp>

#include "CircularBuffer.h"

using namespace std;

class StringSound {
 public:
    StringSound();
    explicit StringSound(double);
    explicit StringSound(vector<sf::Int16>);
    StringSound(const StringSound&) {};
    ~StringSound();

    void pluck();
    void tic();
    sf::Int16 sample();
    int time();
 private:
    CircularBuffer *cb;
    int _time;
};