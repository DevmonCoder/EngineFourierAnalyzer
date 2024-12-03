#ifndef FFTWCALCULATOR_H
#define FFTWCALCULATOR_H

#include <vector>

class FftwCalculator {
private:
    int n;
    std::vector<double> values;
    std::vector<double> reOut; // Real part of the FFT
    std::vector<double> imOut; // Imaginary part of the FFT

public:
    FftwCalculator(int n, const std::vector<double>& values);
    void calculate();
    const std::vector<double>& getReOut() const;
    const std::vector<double>& getImOut() const;
};

#endif // FFTWCALCULATOR_H