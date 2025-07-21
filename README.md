# Virtual Plant Mood Display with Soil Moisture and Light Sensors 🌱💡

This Arduino sketch reads soil moisture and ambient light sensor data, and displays a cute animated face on a 16x2 I2C LCD screen to show the plant's "mood."  
The face changes based on moisture and light levels, cycling through happy, sad, sleeping, and "dead" expressions.

---

## Features

- Reads soil moisture (analog pin A0) and light sensor (analog pin A1)
- Displays mood with 4-frame ASCII animations on an I2C 16x2 LCD (`LiquidCrystal_I2C` library)
- Animated faces for:  
  - Happy 😊  
  - Sad 😢  
  - Sleeping 😴  
  - Dead 💀
- Shows moisture and light percentage values on the bottom line
- Automatically animates the face every 600 ms

---
## Requirements

- **Hardware:**
  - Arduino board (Uno, Nano, Mega, etc.)
  - Soil moisture sensor (analog output)
  - Light sensor (analog output, e.g., photoresistor or photodiode)
  - 16x2 I2C LCD display (compatible with `LiquidCrystal_I2C` library)
  - Connecting wires and breadboard

- **Software:**
  - Arduino IDE (version 1.8.x or newer recommended)
  - Arduino `LiquidCrystal_I2C` library  
    (Install via Library Manager: `Sketch` -> `Include Library` -> `Manage Libraries` -> search "LiquidCrystal_I2C")

- **Power:**
  - Suitable power supply for your Arduino and connected components

---

Make sure your sensors output analog signals compatible with the Arduino analog input pins.

## Wiring

- Connect soil moisture sensor output to **A0**
- Connect light sensor output to **A1**
- Connect the LCD via I2C to your Arduino (usually SDA to A4, SCL to A5 on Uno)

---
