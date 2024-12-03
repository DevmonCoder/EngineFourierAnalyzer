#include "FileGenerator.h"
#include <fstream>
#include <iostream>

double samplingRate = pow(2, 3); // Sampling rate (samples per unit time)

// Constructor implementation
FileGenerator::FileGenerator(const std::string& file)
    : filename(file) {
}

// Method to save data
void FileGenerator::saveData(const std::vector<int>& samples,
    const std::vector<double>& time, const std::vector<double>& values,
    const std::vector<double>& refftw, const std::vector<double>& imfftw) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "Index\tTime\tValue\tFrequency\tFFT Real\tFFT Imaginary\n";
        for (size_t i = 0; i < samples.size(); ++i) {
            double freq = (i <= time.size() / 2) ? (i * samplingRate / time.size()) : ((i - time.size()) * samplingRate / time.size());
            file << samples[i] << "\t"
                << time[i] << "\t" << values[i] << "\t"
                << freq << "\t"
                << refftw[i] << "\t" << imfftw[i] << "\n";
        }
        file.close();
        std::cout << "Data saved to " << filename << std::endl;
    }
    else {
        std::cerr << "Error opening file: " << filename << std::endl;
        throw std::ios_base::failure("File could not be opened");
    }
}