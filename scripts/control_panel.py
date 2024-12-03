import tkinter as tk
from tkinter import ttk

class ControlPanel:
    """Class to manage user controls for adjusting signal parameters."""

    def __init__(self, parent):
        """Initialize the ControlPanel class with a parent Tkinter frame."""
        self.parent = parent

        # Create a frame for the controls
        self.frame = tk.Frame(self.parent)
        self.frame.pack(side=tk.RIGHT, fill=tk.Y, padx=10, pady=10)

        # Add input fields
        self.controls = {}
        self.create_input("Samples:", "samples", 4096, 1, int)
        self.create_input("Cycles:", "cycles", 1, 1, int)
        self.create_input("Amplitude (mm):", "amplitude", 1.0, 0.1, float)
        self.create_slider("Frequency (Hz):", "frequency", 1.0, 10.0, 0.5, 1.0)
        self.create_slider("Phase (deg):", "phase", 0.0, 350.0, 10.0, 0.0)

        # Add update button
        self.update_button = tk.Button(self.frame, text="Update Values", command=self.update_values)
        self.update_button.pack(pady=5)

    def create_input(self, label_text, key, default_value, step, dtype):
        """Create a labeled input field."""
        label = tk.Label(self.frame, text=label_text)
        label.pack(anchor="w")
        entry = tk.Entry(self.frame)
        entry.insert(0, str(default_value))
        entry.pack(fill=tk.X)
        self.controls[key] = {"widget": entry, "default": default_value, "step": step, "dtype": dtype}

    def create_slider(self, label_text, key, min_value, max_value, resolution, default_value):
        """Create a labeled slider."""
        label = tk.Label(self.frame, text=label_text)
        label.pack(anchor="w")
        slider = ttk.Scale(self.frame, from_=min_value, to=max_value, orient=tk.HORIZONTAL, resolution=resolution)
        slider.set(default_value)
        slider.pack(fill=tk.X)
        self.controls[key] = {"widget": slider, "default": default_value, "min": min_value, "max": max_value, "resolution": resolution}

    def get_values(self):
        """Retrieve the current values from the controls."""
        values = {}
        for key, control in self.controls.items():
            widget = control["widget"]
            if isinstance(widget, tk.Entry):
                value = widget.get()
                values[key] = control["dtype"](value)
            elif isinstance(widget, ttk.Scale):
                value = widget.get()
                values[key] = float(value)
        return values

    def reset_defaults(self):
        """Reset all controls to their default values."""
        for key, control in self.controls.items():
            widget = control["widget"]
            if isinstance(widget, tk.Entry):
                widget.delete(0, tk.END)
                widget.insert(0, str(control["default"]))
            elif isinstance(widget, ttk.Scale):
                widget.set(control["default"])

    def update_values(self):
        """Callback for the Update Values button to print the current values."""
        updated_values = self.get_values()
        print("\nUpdated values from ControlPanel:")
        for key, value in updated_values.items():
            print(f"{key.capitalize()}: {value}")