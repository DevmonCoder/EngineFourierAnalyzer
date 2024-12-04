#include "FftwApplication.h"
#include "SignalGenerator.h"
#include "FftwCalculator.h"
#include "FileGenerator.h"
#include "GraphicGenerator.h"

// Constructor implementation
FftwApplication::FftwApplication(int n, int cycles,
    double amplitude, double frequency, double phase,
    const std::string& fileName, const std::string& scriptPath)
    : n(n), cycles(cycles), amplitude(amplitude), frequency(frequency), phase(phase),
    fileName(fileName), scriptPath(scriptPath) {
}

// run method now doesn't need parameters
void FftwApplication::run() {
    // Create the signal
    SignalGenerator signalGenerator(amplitude, frequency, phase, n);
    signalGenerator.generate();

    // Calculates the FFTW of the signal
    FftwCalculator fftwCalculator(n, frequency, signalGenerator.getValues());
    fftwCalculator.calculate();

    // Generates the txt file with the input signal data and the FFTW
    FileGenerator fileGenerator(fileName);
    fileGenerator.saveData(signalGenerator.getSamples(),
        signalGenerator.getTime(),
        signalGenerator.getValues(),
        fftwCalculator.getFrequencies(),
        fftwCalculator.getReFftw(),
        fftwCalculator.getImFftw(),
        fftwCalculator.getMagnitudes());

    GraphicGenerator graphicGenerator(scriptPath);
    graphicGenerator.execute(n, cycles, amplitude, frequency, phase);
}