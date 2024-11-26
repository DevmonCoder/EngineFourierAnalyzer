#include <cstdlib> // to system()
#include <iostream>
#include <fstream>
#include <cmath> // For sin() and M_PI
#include <fftw3.h>

int main() {
    // Parameters for the sine wave
    const int N = 1<<14;             // Number of samples
    const double pi = 3.14159265358979323846;
    const double amplitude = 1.0;  // Amplitude of the sine wave
    const double frequency = 4000.0;  // Frequency in Hz (cycles per sample)
    const double phase = 0.0;      // Phase in radians
    const double samplingRate = pow(2,17); // Sampling rate (samples per unit time)

    // FFTW input and output arrays
    fftw_complex in[N], out[N];
    fftw_plan p = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

    // Generate the sine wave as input
    double dt = 1.0 / samplingRate; // Time step between samples
    for (int i = 0; i < N; i++) {
        double t = i * dt;         // Current time
        in[i][0] = amplitude * std::sin(2 * pi * frequency * t + phase); // Real part
        in[i][1] = 0;              // Imaginary part is 0
    }

    // Execute the FFT
    fftw_execute(p);

    // Save the sine wave and FFT output to a file
    std::ofstream file("fft_data.txt");
    if (file.is_open()) {
        file << "# Index\tFrequency (Hz)\tInput\tFFT Real\tFFT Imaginary\n";
        for (int i = 0; i < N; i++) {
            double freq = (i <= N / 2) ? (i * samplingRate / N) : ((i - N) * samplingRate / N);
            file << i << "\t" << freq << "\t" << in[i][0] << "\t" << out[i][0] << "\t" << out[i][1] << "\n";
        }
        file.close();
        std::cout << "Data saved to fft_data.txt" << std::endl;
    }
    else {
        std::cerr << "Error opening file!" << std::endl;
    }

    // Clean up FFT resources
    fftw_destroy_plan(p);
    fftw_cleanup();
    
    // Execute the Python script from the system
    if (system("python fftw_graphic.py") == 0) {
        std::cout << "Script ejecutado con éxito." << std::endl;
    }
    else {
        std::cerr << "Error al ejecutar el script Python." << std::endl;
    }
    std::cout << "Code successfully executed on x86!" << std::endl;
    return 0;
}