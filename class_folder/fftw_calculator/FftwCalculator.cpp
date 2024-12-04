#include "FftwCalculator.h"
#include <fftw3.h>
#include <cmath>

FftwCalculator::FftwCalculator(int n, double frequency, const std::vector<double>& values)
    : n(n), frequency(frequency), values(values) {
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
    reFftw.resize(n);
    imFftw.resize(n);
    magnitudes.resize(n);
    for (int k = 0; k < n; ++k) {
        reFftw[k] = out[k][0]; // Real part
        imFftw[k] = out[k][1]; // Imaginary part
        magnitudes[k] = sqrt(reFftw[k] * reFftw[k] + imFftw[k] * imFftw[k]);
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
        positiveFrequencies[k] = (k <= n / 2) ? (k * frequency) : ((k - n) * frequency); // Frequency calculation
    }

    // Free FFTW resources
    fftw_destroy_plan(p);
    fftw_free(in);
    fftw_free(out);
}

const std::vector<double>& FftwCalculator::getFrequencies() const {
    return positiveFrequencies;
}

const std::vector<double>& FftwCalculator::getMagnitudes() const {
    return magnitudes;
}

const std::vector<double>& FftwCalculator::getReFftw() const
{
    return reFftw;
}

const std::vector<double>& FftwCalculator::getImFftw() const
{
    return imFftw;
}
