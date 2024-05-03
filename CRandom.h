#ifndef CRANDOM_H
#define CRANDOM_H

#include <random>

class CRandom {
public:
    // Generate a random integer in the range [min, max]
    int getRandomInt(int min, int max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(min, max);
        return dis(gen);
    }
};

#endif // CRANDOM_H
