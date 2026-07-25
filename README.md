# 🤖 Gesture-Controlled LED using TinyML on ESP32

> **Train an ESP32 to recognize hand gestures using TinyML and control an LED completely offline.**

![License](https://img.shields.io/badge/License-MIT-blue.svg)
![Platform](https://img.shields.io/badge/Platform-ESP32-red)
![TinyML](https://img.shields.io/badge/TinyML-Edge%20Impulse-success)
![Language](https://img.shields.io/badge/Language-Embedded%20C-blue)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

An embedded AI project that demonstrates **real-time hand gesture recognition** using an **ESP32**, **MPU6050 accelerometer**, and **Edge Impulse TinyML model**. The system learns motion patterns such as **Wave** and **Still**, performs **on-device inference**, and controls an LED based on the detected gesture—all without requiring an internet connection after deployment.

Designed as a beginner-friendly TinyML project, it showcases how machine learning can be integrated into low-power embedded systems for intelligent automation.

---

# 📖 Project Overview

Traditional gesture recognition systems often rely on cloud computing, resulting in increased latency and privacy concerns. This project solves that problem by running a trained machine learning model directly on the ESP32.

Motion data from the MPU6050 accelerometer is captured in real time and passed through an Edge Impulse TinyML model. The ESP32 then predicts the performed gesture and instantly controls an LED according to the prediction.

This project demonstrates the practical implementation of:

- TinyML on resource-constrained hardware
- Embedded AI inference
- Motion sensing using IMU sensors
- Offline gesture recognition
- Real-time decision making

---

# ✨ Features

- 🧠 TinyML inference running completely on ESP32
- 📡 Offline gesture recognition (No cloud required)
- ⚡ Real-time prediction with low latency
- 🤚 Recognizes multiple hand gestures
- 💡 Controls LED based on AI predictions
- 📈 Trained using Edge Impulse Studio
- 🔋 Low-power embedded AI implementation
- 🛠 Easy to expand for home automation or robotics
- 📊 Serial Monitor displays prediction confidence
- 🎯 Lightweight machine learning model

---

# 🎯 Gesture Classes

Current trained model:

| Gesture | Action |
|----------|---------|
| Still | LED OFF |
| Wave | LED ON |

Additional gestures can easily be added such as:

- Left
- Right
- Up
- Down
- Circle
- Shake
- Double Wave

Simply collect more training data and retrain the model.

---

# 🧰 Hardware Requirements

| Component | Quantity |
|------------|----------|
| ESP32 Dev Board | 1 |
| MPU6050 Accelerometer & Gyroscope | 1 |
| LED | 1 |
| 220Ω Resistor | 1 |
| Breadboard | 1 |
| Jumper Wires | As Required |
| USB Cable | 1 |

---

# 💻 Software Requirements

- Arduino IDE
- Edge Impulse Studio
- ESP32 Board Package
- MPU6050 Library
- Wire Library
- Edge Impulse Arduino Library

---

# 🔌 Circuit Diagram

| MPU6050 | ESP32 |
|----------|-------|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO21 |
| SCL | GPIO22 |

### LED Connection

| LED | ESP32 |
|-----|-------|
| Anode (+) | GPIO2 (through 220Ω resistor) |
| Cathode (-) | GND |

---

# 🏗 Project Architecture

```
Hand Motion
      │
      ▼
 MPU6050 Sensor
      │
      ▼
 ESP32 Reads Motion Data
      │
      ▼
 Edge Impulse TinyML Model
      │
      ▼
 Gesture Prediction
      │
      ▼
 LED ON / OFF
```

---

# 📂 Project Structure

```
Gesture-Controlled-LED-using-TinyML-on-ESP32
│
├── Gesture_Control.ino
├── README.md
├── EdgeImpulse_Model/
│     ├── model_metadata.h
│     ├── model_parameters.h
│     └── edge-impulse-sdk/
│
├── Images/
│     ├── circuit.png
│     ├── setup.jpg
│     └── output.png
│
└── Dataset/
      ├── still.csv
      └── wave.csv
```

---

# ⚙️ How It Works

1. ESP32 initializes the MPU6050 sensor.
2. Accelerometer data is continuously collected.
3. Motion values are sent to the TinyML model.
4. Edge Impulse classifier predicts the gesture.
5. If **Wave** is detected:
   - LED turns ON.
6. If **Still** is detected:
   - LED remains OFF.
7. Prediction confidence is displayed on the Serial Monitor.

---

# 🧠 Machine Learning Workflow

## Step 1 — Data Collection

Create a new project in **Edge Impulse Studio**.

Collect motion data for different gestures.

Recommended dataset:

### Class 1
- Still

### Class 2
- Wave

Collect at least:

- 20–50 samples per gesture
- Different speeds
- Different users
- Multiple orientations

More data generally improves accuracy.

---

## Step 2 — Create Impulse

Inside Edge Impulse:

Add processing block:

```
Spectral Analysis
```

Add learning block:

```
Classification
```

---

## Step 3 — Train the Model

Train until accuracy exceeds:

```
85%+
```

Higher quality datasets can easily reach:

```
95–99%
```

---

## Step 4 — Deployment

Navigate to

```
Deployment
```

Select

```
Arduino Library
```

Download the ZIP library.

---

## Step 5 — Arduino IDE

Open

```
Sketch
→ Include Library
→ Add ZIP Library
```

Import the downloaded Edge Impulse library.

---

## Step 6 — Upload Code

Compile and upload the Arduino sketch.

Open Serial Monitor.

Move your hand.

Observe live predictions.

---

# 📷 Serial Monitor Output

```
MPU6050 Ready!

Prediction:
Wave

Confidence:
0.94

LED ON
```

```
Prediction:
Still

Confidence:
0.98

LED OFF
```

---

# 📈 Example Prediction

| Gesture | Confidence | LED |
|----------|------------|-----|
| Wave | 0.94 | ON |
| Still | 0.98 | OFF |
| Wave | 0.91 | ON |
| Still | 0.95 | OFF |

---

# 🚀 Applications

- Smart Home Automation
- Touchless Switches
- Gesture-Controlled Robots
- IoT Devices
- Healthcare Monitoring
- Assistive Technology
- Interactive Embedded Systems
- Wearable Devices
- Industrial Automation
- Educational TinyML Projects

---

# 🔮 Future Improvements

- Add more gesture classes
- OLED display for live prediction
- Wireless IoT control
- Servo motor control
- Home appliance automation
- Bluetooth communication
- Wi-Fi dashboard
- TensorFlow Lite Micro optimization
- Battery-powered wearable version
- Multi-user gesture recognition

---

# 📚 Libraries Used

- Wire.h
- MPU6050 Library
- Edge Impulse Arduino Library

---

# 🛠 Technologies Used

- Embedded C
- ESP32
- TinyML
- Edge Impulse
- Arduino IDE
- MPU6050 IMU Sensor
- I2C Communication
- Machine Learning
- Sensor Data Processing
- Embedded AI

---

# 🎓 Learning Outcomes

This project demonstrates:

- TinyML deployment on embedded hardware
- Motion data acquisition
- Accelerometer signal processing
- Embedded AI inference
- Offline machine learning
- Real-time sensor integration
- Edge computing concepts
- Embedded systems programming

---

# 👨‍💻 Author

## **Koushik M**

**Mechatronics Engineer | Embedded Systems | Robotics | TinyML | IoT | Edge AI**

🔗 **LinkedIn**

https://www.linkedin.com/in/koushikmvkk/

🔗 **GitHub**

https://github.com/koushikmvkk-gif

---

# ⭐ Support

If you found this project helpful:

⭐ Star this repository

🍴 Fork the repository

🐞 Report issues

💡 Suggest improvements

---

# 📄 License

This project is licensed under the **MIT License**.

Feel free to use, modify, and distribute this project for educational and research purposes.

---

## 🌟 Project Highlights

- ✅ TinyML-based Gesture Recognition
- ✅ Fully Offline AI Inference
- ✅ ESP32 Embedded Machine Learning
- ✅ Real-Time Motion Classification
- ✅ Edge Impulse Deployment
- ✅ Intelligent LED Control
- ✅ Beginner-Friendly TinyML Project
- ✅ Expandable to Robotics and Home Automation

---

**Made with ❤️ by Koushik M**
