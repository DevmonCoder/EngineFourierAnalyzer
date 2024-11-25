import numpy as np
import matplotlib.pyplot as plt

# Load the data
data = np.loadtxt("C:/Users/CODER/_CPP/EngineFourierAnalyzer/Debug/fft_data.txt", skiprows=1)  # Skip the header row
indices = data[:, 0]  # Index column
frequencies = data[:, 1]  # Frequency column
input_signal = data[:, 2]  # Input values
fft_real = data[:, 3]  # Real part of FFT
fft_imag = data[:, 4]  # Imaginary part of FFT

# Plot the input signal with a continuous line only
plt.figure(figsize=(12, 6))
plt.subplot(2, 1, 1)
plt.plot(indices*4, input_signal, color='red', linewidth=1.5, label="Input Signal")  # Continuous line
plt.axhline(0, color='black', linewidth=1, linestyle='-')  # Horizontal line at y=0
plt.title("Input Signal")
plt.xlabel("Time (s)")
plt.ylabel("Amplitude (mm)")
plt.legend()  # Add a legend to identify the line
plt.grid()  # Add a grid for better visualisation

# Set x-axis limits to start at 0
plt.xlim(0, max(indices/10))  # Defines the x-axis to start from 0 to maximum index

# Set the y-axis limits so that the x-axis cuts at y=0.
y_min, y_max = min(input_signal), max(input_signal)  # Calculate data limits
plt.ylim([y_min * 1.1, y_max * 1.1])  # Adjust with a 10% margin for clarity

# Determine the relevant maximum frequency (frequency where there are significant components)
fft_magnitude = np.sqrt(fft_real**2 + fft_imag**2)  # Spectrum magnitude (optional, to verify)
threshold = 0.01 * max(fft_magnitude)  # Defines a threshold for detecting significant frequencies
max_frequency = max(frequencies[fft_magnitude > threshold])  # Find the maximum significant frequency

# Plot the FFT output
plt.subplot(2, 1, 2)
plt.stem(frequencies, fft_real, markerfmt='r.', label="Real Part")  # Removed use_line_collection
plt.stem(frequencies, fft_imag, markerfmt='b.', label="Imaginary Part")  # Removed use_line_collection
plt.title("FFT Output")
plt.xlabel("Frequency Index")
plt.ylabel("Amplitude")
plt.legend()

# Set x-axis limits to start at 0
plt.xlim(0, max_frequency*4/3)  # Defines the x-axis to start from 0 to maximum index

# Display the plots
plt.tight_layout()
plt.show()