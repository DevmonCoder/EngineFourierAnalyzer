#ifndef FFTWCALCULATOR_H
#define FFTWCALCULATOR_H

#include <vector>

class FftwCalculator {
private:
    int n;
    double frequency;
    std::vector<double> values; // Input signal values
    std::vector<double> positiveFrequencies; // Frequencies of the FFT
    std::vector<double> reFftw;
    std::vector<double> imFftw;
    std::vector<double> magnitudes; // Magnitudes of the FFT

public:
    FftwCalculator(int n, double frequency, const std::vector<double>& values);
    void calculate();
    const std::vector<double>& getFrequencies() const;
    const std::vector<double>& getReFftw() const;
    const std::vector<double>& getImFftw() const;
    const std::vector<double>& getMagnitudes() const;
};

#endif // FFTWCALCULATOR_H