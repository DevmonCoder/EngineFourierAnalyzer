import matplotlib.pyplot as plt

class SignalPlotter:
    def __init__(self, time, values, samples, cycles, amplitude, frequency, phase, frequencies, magnitudes):
        self.time = time
        self.values = values
        self.samples = samples
        self.cycles = cycles
        self.amplitude = amplitude
        self.frequency = frequency
        self.phase = phase
        self.frequencies = frequencies
        self.magnitudes = magnitudes

    def plot_signal(self):
        """
        Plot the signal using the provided data.
        """
        plt.figure(figsize=(12, 6))
        plt.subplot(2, 1, 1)
        plt.plot(self.time, self.values, color='red', linewidth=1.5, label="Input Signal")
        plt.axhline(0, color='black', linewidth=1, linestyle='-')  # Horizontal axis
        plt.title("Signal Graph")
        plt.xlabel("Time (s)")
        plt.ylabel("Amplitude (mm)")
        plt.grid()

        # Adjust x-axis and y-axis limits
        plt.xlim(0, max(self.time))
        y_min, y_max = min(self.values), max(self.values)
        plt.ylim([y_min * 1.1, y_max * 1.1])

        # Add text annotations with parameters
        text = (f"Samples: {self.samples}\n"
                f"Cycles: {self.cycles}\n"
                f"Amplitude: {self.amplitude} mm\n"
                f"Frequency: {self.frequency} Hz\n"
                f"Period: {1/self.frequency} s\n"
                f"Phase: {self.phase} deg")
        plt.text(1.01 * max(self.time), y_max * 0.83, text, fontsize=10, color='blue')

        # Plot the FFT output
        plt.subplot(2, 1, 2)
        plt.stem(self.frequencies, self.magnitudes, markerfmt='r.', label="Real Part")  # Removed use_line_collection
        #plt.stem(frequencies, reFftw, markerfmt='r.', label="Real Part")  # Removed use_line_collection
        #plt.stem(frequencies, imFftw, markerfmt='r.', label="Real Part")  # Removed use_line_collection
        plt.title("FFT Output")
        plt.xlabel("Frequency")
        plt.ylabel("Amplitude")
        plt.legend()

        # Set x-axis limits to start at 0
        plt.xlim(0, self.frequency * 4 / 3)  # Defines the x-axis to start from 0 to maximum index

        plt.tight_layout()
        plt.show()