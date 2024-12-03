#ifndef FFTWAPPLICATION_H
#define FFTWAPPLICATION_H

#include <string>

class FftwApplication {
private:
    int n, cycles;
    double amplitude, frequency, phase;
    std::string fileName, scriptPath;
public:
    // Constructor to initialize the application parameters
    FftwApplication(int n, int cycles, double amplitude, double frequency, double phase,
        const std::string& fileName, const std::string& scriptPath);

    // Method for executing the main application logic
    void run();
};

#endif // FFTWAPPLICATION_H