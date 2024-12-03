#include <cstdlib> // to system()
#include <iostream>
#include <fstream>
#include <cmath> // For sin() and M_PI
#include <fftw3.h>
#include <SignalGenerator.h>
#include <vector>
#include <FftwCalculator.h>
#include <string>
#include <FileGenerator.h>

int main() {
    // Parameters for the sine wave
    const int n = 1<<12;             // Number of samples
    const double amplitude = 1.0;  // Amplitude of the sine wave
    const double frequency = 1.0;  // Frequency in Hz (cycles per sample)
    const double phase = 0.0;      // Phase in radians
    
    // Parameters to set up the txt file
    std::string fileName = "fft_data.txt";

    // Create the signal
    SignalGenerator signalGenerator(amplitude, frequency, phase, n);
    signalGenerator.generate();

    const std::vector<int>& samples = signalGenerator.getSamples();
    const std::vector<double>& time = signalGenerator.getTime();
    const std::vector<double>& values = signalGenerator.getValues();

    // Calculates the FFTW of the signal
    FftwCalculator fftwCalculator(n, values);
    fftwCalculator.calculate();

    const std::vector<double>& refftw = fftwCalculator.getReOut();
    const std::vector<double>& imfftw = fftwCalculator.getImOut();
    
    // Generates the txt file with the input signal data and the FFTW
    FileGenerator fileGenerator(fileName);
    fileGenerator.saveData(samples, time, values, refftw, imfftw);

    // Execute the Python script from the system
    if (system("python ../scripts/fftw_graphic.py") == 0) {
        std::cout << "Script ejecutado con éxito." << std::endl;
    }
    else {
        std::cerr << "Error al ejecutar el script Python." << std::endl;
    }
    std::cout << "Code successfully executed on x86!" << std::endl;
    return 0;
}