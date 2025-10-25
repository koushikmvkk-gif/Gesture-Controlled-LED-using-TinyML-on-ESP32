#include <Wire.h>
#include <MPU6050.h>
#include <Your_EdgeImpulse_Library.h>  // Replace with your library name

MPU6050 mpu;
int ledPin = 2;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  pinMode(ledPin, OUTPUT);

  if (!mpu.begin()) {
    Serial.println("MPU6050 not found!");
    while (1);
  }
  Serial.println("MPU6050 ready!");
}

void loop() {
  // Collect accelerometer data
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  float input_data[3] = {a.acceleration.x, a.acceleration.y, a.acceleration.z};

  // Run inference
  ei_impulse_result_t result = run_classifier(&input_data[0]);

  // Print results
  Serial.print("Prediction: ");
  Serial.println(result.classification[0].value > 0.8 ? "Wave" : "Still");

  // Control LED based on gesture
  if (result.classification[0].value > 0.8) {
    digitalWrite(ledPin, HIGH); // Turn on LED if wave detected
  } else {
    digitalWrite(ledPin, LOW); // Turn off LED otherwise
  }

  delay(200);
}
