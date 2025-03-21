#include <esp_now.h>
#include <WiFi.h>

#define VIBRATION_PIN 25  // GPIO pin for the vibration module

// Define the number of ultrasonic sensors (same as sender)
const int numSensors = 3;  // Changed from 2 to 3

// Define a struct to receive distance readings
typedef struct struct_message {
    float distances[numSensors];  // Store received distances
} struct_message;

// Create a struct_message instance to store incoming data
struct_message receivedData;

// Callback function when data is received
void OnDataRecv(const esp_now_recv_info_t *recv_info, const uint8_t *incomingData, int len) {
    memcpy(&receivedData, incomingData, sizeof(receivedData));

    Serial.println("Received Distance Data:");
    bool shouldVibrate = false;  // Flag to track if vibration should be ON

    for (int i = 0; i < numSensors; i++) {
        Serial.print("Sensor ");
        Serial.print(i + 1);
        Serial.print(": ");
        Serial.print(receivedData.distances[i]);
        Serial.println(" cm");

        // Check if the distance is within 10-15 cm range
        if (receivedData.distances[i] >= 10 && receivedData.distances[i] <= 15) {
            shouldVibrate = true;  // Set flag to turn on vibration
        }
    }

    // Control the vibration motor based on flag
    if (shouldVibrate) {
        digitalWrite(VIBRATION_PIN, HIGH);  // Turn vibration ON
        Serial.println("Vibration ON");
    } else {
        digitalWrite(VIBRATION_PIN, LOW);   // Turn vibration OFF
        Serial.println("Vibration OFF");
    }
}

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);  // Set ESP32 to Station mode

    // Initialize vibration motor pin
    pinMode(VIBRATION_PIN, OUTPUT);
    digitalWrite(VIBRATION_PIN, LOW);  // Start with vibration OFF

    // Initialize ESP-NOW
    if (esp_now_init() != ESP_OK) {
        Serial.println("ESP-NOW Init Failed");
        return;
    }

    // Register receive callback
    esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
    // Nothing needed here, messages are received via callback
}
