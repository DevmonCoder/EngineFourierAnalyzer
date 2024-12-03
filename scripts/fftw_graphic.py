import os
import numpy as np
import matplotlib.pyplot as plt

# Define the relative path to the file "C:\Users\CODER\_CPP\EngineFourierAnalyzer\Debug\fft_data.txt"
file_path = os.path.join(os.path.dirname(__file__), "../Debug/fft_data.txt")
data = np.loadtxt(file_path, skiprows=1)  # Skip the header row

# Load the data
indices = data[:, 0]  # Index column
time = data[:, 1]  # Time column
input_signal = data[:, 2]  # Input values
frequencies = data[:, 3]  # Frequency column
magnitudes = data[:, 4]  # Real part of FFT

# Plot the input signal with a continuous line only
plt.figure(figsize=(12, 6))
plt.subplot(2, 1, 1)
plt.plot(time, input_signal, color='red', linewidth=1.5, label="Input Signal")  # Continuous line
plt.axhline(0, color='black', linewidth=1, linestyle='-')  # Horizontal line at y=0
plt.title("Input Signal")
plt.xlabel("Time (s)")
plt.ylabel("Amplitude (mm)")
plt.grid()  # Add a grid for better visualisation

# Set x-axis limits to show only two cycles
plt.xlim(0, max(time))  # Show two cycles of the signal

# Set the y-axis limits so that the x-axis cuts at y=0.
y_min, y_max = min(input_signal), max(input_signal)  # Calculate data limits
plt.ylim([y_min * 1.1, y_max * 1.1])  # Adjust with a 10% margin for clarity

# Plot the FFT output
plt.subplot(2, 1, 2)
plt.stem(frequencies, magnitudes, markerfmt='r.', label="Real Part")  # Removed use_line_collection
plt.title("FFT Output")
plt.xlabel("Frequency")
plt.ylabel("Amplitude")
plt.legend()

# Set x-axis limits to start at 0
plt.xlim()  # Defines the x-axis to start from 0 to maximum index

# Display the plots
plt.tight_layout()
plt.show()