#ifndef FILEGENERATOR_H
#define FILEGENERATOR_H

#include <string>
#include <vector>

class FileGenerator {
private:
    std::string filename;  // Name of the file to manage
    std::vector<int> samples;
    std::vector<double> time;
    std::vector<double> values;
    std::vector<double> magnitude;
    std::vector<double> positiveFrequencies;

public:
    // Constructor
    FileGenerator(const std::string& file);

    // Method to save data
    void saveData(const std::vector<int>& samples,
        const std::vector<double>& time, const std::vector<double>& values,
        const std::vector<double>& magnitude, const std::vector<double>& positiveFrequencies) const;
};

#endif // FILEGENERATOR_H