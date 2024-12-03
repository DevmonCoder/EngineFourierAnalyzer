#ifndef GRAPHICGENERATOR_H
#define GRAPHICGENERATOR_H

#include <string>

class GraphicGenerator {
private:
    std::string scriptPath; // Path to Python script

public:
    // Constructor
    explicit GraphicGenerator(const std::string& path);

    // Method to execute the script
    void execute(int n, int cycles, double amplitude, double frequency, double phase) const;
};

#endif // GRAPHICGENERATOR_H