Step-by-Step Procedure:
STEP 1: Data Collection (Edge Impulse)

1️⃣ Go to Edge Impulse Studio

2️⃣ Create a new project → “Gesture Recognition ESP32”
3️⃣ Connect your ESP32 or Arduino Nano 33 BLE Sense (for now, collect MPU6050 data manually via serial).
4️⃣ Record motion samples:

Class 1: Still (hand steady)

Class 2: Wave (hand moving side to side)
5️⃣ Collect at least 20 samples per class.

STEP 2: Train the Model

1️⃣ In Edge Impulse → click “Create Impulse”
2️⃣ Add a Spectral Analysis block + Classifier block
3️⃣ Train the model → check accuracy (>85% is good)
4️⃣ Go to Deployment → Arduino Library → Download the .zip

STEP 3: Add Library to Arduino IDE

Open Arduino IDE

Go to Sketch → Include Library → Add .ZIP Library

Import your downloaded Edge Impulse library

STEP 4: Wiring Connections
MPU6050 Pin	ESP32 Pin
VCC	3.3V
GND	GND
SDA	GPIO21
SCL	GPIO22

Connect LED → GPIO2 via 220Ω resistor
