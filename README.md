# Haptic-Lab-Safety-Device
Course: BIOE 240 - Haptics Final Project


### Abstract: 

University-level biological laboratories often require laboratory coats and safety glasses to protect users from chemical splashes or burns and prevent biological contamination. Despite the utility of these engineering controls, many high school labs do not have flame-resistant lab coats to protect students from Bunsen burner accidents. Here we describe a modular haptic lab safety device that provides another layer of protection against Bunsen burner accidents. This device delivers haptic feedback to a user’s hand if it gets too close to a dangerous, pre-defined, region near the Bunsen burner flame -- warning them to move their hand away from possible danger. This prototype could have widespread use across many labs and universities, and reduce the incidence rate of burner-related lab accidents. 

### Live Demonstration

[![Haptic Safety Device Demo](https://img.youtube.com/vi/iQ_7F2jJDRw.jpg)](https://youtu.be/iQ_7F2jJDRw)




### Software Architecture: 

The software is divided into two distinct parts -- one part for each ESP32 module. 

1. **Sensor Station Module**: This module reads distances for all three ultrasonic sensors and transmits the data to the second ESP32 via WiFi. 

2. **Wearable Haptic Feedback Module**: This module receives distances from three sensors and, using a pre-defined threshold range, delivers haptic feedback to the user by sending a pulse through a vibration motor mounted on the user's wrist. 




