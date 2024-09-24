// EngineFourierAnalyzer.cpp
#include <iostream>
#include <fftw3.h>

int main()
{
    std::cout << "Hello FFTW!" << std::endl;
    //Basic example of FFT
    const int N = 16; // Signal size
    fftw_complex in[N], out[N]; // Arrays for the input signal and the output signal
    fftw_plan p = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE); // Create a plan for the FFT
    for (int i = 0; i < N; i++) { // Initialize the input signal with real values
        in[i][0] = i; // Real part
        in[i][1] = 0; // Imaginary part
    }
    fftw_execute(p); // Execute the FFT
    for (int i = 0; i < N; i++) { // Display the FFT result
        std::cout << "out [" << i << "] = (" << out[i][0] << ", " << out[i][1] << ")\n";
    }
    fftw_destroy_plan(p); // Destroy the plan
    fftw_cleanup(); // Clean the plan
    std::cout << "Code successfully executed on x86!" << std::endl;
    return 0;
}