#include "FftwCalculator.h"
#include <fftw3.h>
#include <vector>

FftwCalculator::FftwCalculator(int samples, const std::vector<double>& val)
    : n(samples), values(val), reOut(samples), imOut(samples) {
}

void FftwCalculator::calculate() {
    // FFTW input and output arrays
    fftw_complex* in = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * n);
    fftw_complex* out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * n);
    fftw_plan p = fftw_plan_dft_1d(n, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

    for (int i = 0; i < n; ++i) {
        in[i][0] = values[i]; // Parte real
        in[i][1] = 0.0;       // Parte imaginaria
    }

    // Execute the FFT
    fftw_execute(p);

    // Almacenar la salida en reOut e imOut
    for (int i = 0; i < n; ++i) {
        reOut[i] = out[i][0]; // Parte real
        imOut[i] = out[i][1]; // Parte imaginaria
    }

    // Limpiar memoria FFTW
    fftw_destroy_plan(p);
    fftw_free(in);
    fftw_free(out);
}

const std::vector<double>& FftwCalculator::getReOut() const {
    return reOut;
}

const std::vector<double>& FftwCalculator::getImOut() const {
    return imOut;
}