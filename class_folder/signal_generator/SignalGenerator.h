#ifndef SIGNALGENERATOR_H
#define SIGNALGENERATOR_H

#include <vector>

class SignalGenerator {
private:
    double amplitude;
    double frequency;
    double phase;
    int n;
    std::vector<double> time;
    std::vector<double> values;
    std::vector<int> samples;

public:
    SignalGenerator(double amp, double freq, double ph, int samp);
    void generate();
    const std::vector<int>& getSamples() const;
    const std::vector<double>& getTime() const;
    const std::vector<double>& getValues() const;
};

#endif // SIGNALGENERATOR_H