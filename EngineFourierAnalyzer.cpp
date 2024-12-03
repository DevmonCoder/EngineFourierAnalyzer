#include <FftwApplication.h>
#include <iostream>

int main() {
    // Parameters for the sine wave
    const int n = 1<<12;             // Number of samples
    const int cycles = 1;           // Number of cycles
    const double amplitude = 1.0;  // Amplitude of the sine wave
    const double frequency = 2.0;  // Frequency in Hz (cycles per sample)
    const double phase = 0.0;      // Phase in radians
    
    // Parameters to set up the txt file
    std::string fileName = "fft_data.txt";
    std::string scriptPath = "../scripts/fftw_graphic.py";

    FftwApplication fftwApplication(n, cycles,
        amplitude, frequency, phase,
        fileName, scriptPath);
    
    fftwApplication.run();

    std::cout << "Code successfully executed on x86!" << std::endl;
    return 0;
}