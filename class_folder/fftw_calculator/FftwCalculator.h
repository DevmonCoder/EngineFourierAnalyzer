#ifndef FFTWCALCULATOR_H
#define FFTWCALCULATOR_H

#include <vector>

class FftwCalculator {
private:
    int n;
    std::vector<double> values; // Input signal values
    std::vector<double> magnitudes; // Magnitudes of the FFT
    std::vector<double> positiveFrequencies; // Frequencies of the FFT

public:
    FftwCalculator(int n, const std::vector<double>& values);
    void calculate();
    const std::vector<double>& getMagnitudes() const;
    const std::vector<double>& getFrequencies() const;
};

#endif // FFTWCALCULATOR_H