#include "FftwCalculator.h"
#include <fftw3.h>
#include <cmath>

FftwCalculator::FftwCalculator(int samples, const std::vector<double>& values)
    : n(samples), values(values) {
}

void FftwCalculator::calculate() {
    // FFTW input and output arrays
    fftw_complex* in = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * n);
    fftw_complex* out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * n);
    fftw_plan p = fftw_plan_dft_1d(n, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

    for (int i = 0; i < n; ++i) {
        in[i][0] = values[i]; // Real part
        in[i][1] = 0.0;       // Imaginary part
    }

    // Execute the FFT
    fftw_execute(p);

    // Calculate magnitude and normalize
    magnitudes.resize(n);
    for (int k = 0; k < n; ++k) {
        double real = out[k][0]; // Real part
        double imag = out[k][1]; // Imaginary part
        magnitudes[k] = sqrt(real * real + imag * imag);
        magnitudes[k] = (2.0 / n) * magnitudes[k]; // Normalize
    }

    // Handle DC and Nyquist components
    magnitudes[0] /= 2.0; // DC component
    if (n % 2 == 0) {
        magnitudes[n / 2] /= 2.0; // Nyquist component if n is even
    }

    // Generate positive frequencies
    positiveFrequencies.resize(n);
    for (int k = 0; k < n; ++k) {
        positiveFrequencies[k] = (k <= n / 2) ? (k * 1024 / n) : ((k - n) * 1024 / n); // Frequency calculation
    }

    // Free FFTW resources
    fftw_destroy_plan(p);
    fftw_free(in);
    fftw_free(out);
}

const std::vector<double>& FftwCalculator::getMagnitudes() const {
    return magnitudes;
}

const std::vector<double>& FftwCalculator::getFrequencies() const {
    return positiveFrequencies;
}
