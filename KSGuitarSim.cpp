// Artyom Martirosyan Copyright 2021

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <math.h>
#include <limits.h>

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

#include "CircularBuffer.h"
#include "StringSound.h"

#define CONCERT_A 440.0
#define SAMPLES_PER_SEC 44100

/*vector<sf::Int16> makeSamples(StringSound &gs) {
    std::vector<sf::Int16> samples;

    gs.pluck();
    int duration = 8;  // seconds
    for (int i= 0; i < SAMPLES_PER_SEC * duration; i++) {
        gs.tic();
        samples.push_back(gs.sample());
    }

    return samples;
}*/

int main() {
    sf::RenderWindow window(sf::VideoMode(300, 200),
                                "SFML Plucked String Sound Lite");
    sf::Event event;
    double freq;
    string keyboardKeys = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";

    vector<vector<int16_t> > samples(37);
    vector<sf::Sound> sounds(37);
    vector<sf::SoundBuffer> soundBuffers(37);

    auto makeSamples = [](StringSound& gs) -> vector<sf::Int16> {
            std::vector<sf::Int16> samples;
            gs.pluck();
            int duration = 8;  // seconds
            for (int i= 0; i < SAMPLES_PER_SEC * duration; i++) {
               gs.tic();
               samples.push_back(gs.sample());
            }

        return samples;
    };

    for (int i = 0; i < 37; i++) {
        freq = CONCERT_A * pow(2, (i - 24) / 12.0);
        StringSound gs(freq);

        samples[i] = makeSamples(gs);

        if (!soundBuffers[i].loadFromSamples(&samples[i][0], samples[i].size(),
                                                         2, SAMPLES_PER_SEC))
            throw std::runtime_error("sf::SoundBuffer: failed to load from samples.");
        sounds[i].setBuffer(soundBuffers[i]);
    }

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::TextEntered:
                if (event.text.unicode < 128) {
                    string temp;
                    temp += static_cast<char>(event.text.unicode);
                    cout << "Playing the key of on keyboard: " << temp << endl;
                    int index = keyboardKeys.find(temp);
                    sounds[index].play();
                }

            default:
                break;
            }
            window.clear();
            window.display();
        }
    }
    return 0;
}
