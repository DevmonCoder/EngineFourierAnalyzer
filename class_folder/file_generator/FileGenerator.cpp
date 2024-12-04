#include "FileGenerator.h"
#include <fstream>
#include <iostream>
#include <iomanip>

double samplingRate = pow(2, 10); // Sampling rate (samples per unit time)

// Constructor implementation
FileGenerator::FileGenerator(const std::string& file)
    : filename(file) {
}

// Method to save data
void FileGenerator::saveData(const std::vector<int>& samples,
    const std::vector<double>& time, const std::vector<double>& values,
    const std::vector<double>& positiveFrequencies,
    const std::vector<double>& reFftw, const std::vector<double>& imFftw,
    const std::vector<double>& magnitude) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << std::setw(5) << std::right << "Index" << "\t"
            << std::setw(15) << std::right << "Time" << "\t"
            << std::setw(15) << std::right << "Value" << "\t"
            << std::setw(18) << std::right << "Frequency" << "\t"
            << std::setw(18) << std::right << "Real FFTW" << "\t"
            << std::setw(18) << std::right << "Imaginary FFTW" << "\t"
            << std::setw(18) << std::right << "FFTW Magnitude" << "\t"
            << "\n";
        for (size_t i = 0; i < samples.size(); ++i) {
            file << std::setw(5) << std::right << samples[i] << "\t"
                << std::setw(15) << std::right << std::fixed << std::setprecision(8) << time[i] << "\t"
                << std::setw(15) << std::right << std::fixed << std::setprecision(8) << values[i] << "\t"
                << std::setw(18) << std::right << std::scientific << std::setprecision(5) << positiveFrequencies[i] << "\t"
                << std::setw(18) << std::right << std::scientific << std::setprecision(5) << reFftw[i] << "\t"
                << std::setw(18) << std::right << std::scientific << std::setprecision(5) << imFftw[i] << "\t"
                << std::setw(18) << std::right << std::scientific << std::setprecision(5) << magnitude[i] << "\n";
        }
        file.close();
        std::cout << "Data saved to " << filename << std::endl;
    }
    else {
        std::cerr << "Error opening file: " << filename << std::endl;
        throw std::ios_base::failure("File could not be opened");
    }
}