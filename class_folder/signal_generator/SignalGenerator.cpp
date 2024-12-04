#include "SignalGenerator.h"
#include <cmath>

SignalGenerator::SignalGenerator(double amplitude, double frequency, double phase, int n)
    : amplitude(amplitude), frequency(frequency), phase(phase), n(n) {
}

void SignalGenerator::generate() {
    double pi = 3.14159265358979323846;
    time.resize(n);
    values.resize(n);
    samples.resize(n);
    for (int i = 0; i < n; i++) {
        double t = i / (n * frequency);
        time[i] = t;
        values[i] = amplitude * std::sin(2 * pi * frequency * t + phase);
        samples[i] = i;
    }
}

const std::vector<int>& SignalGenerator::getSamples() const {
    return samples;
}

const std::vector<double>& SignalGenerator::getTime() const {
    return time;
}

const std::vector<double>& SignalGenerator::getValues() const {
    return values;
}