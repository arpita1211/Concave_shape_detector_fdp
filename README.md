# Concave Detector Bot

## Overview
The **Concave Detector Bot** is an autonomous robot designed to navigate environments while detecting concave surfaces. It uses ultrasonic sensors to measure distances and adjust movement accordingly. The robot employs motor-driven mobility with intelligent decision-making to maneuver around obstacles and respond to different surface types.

## Features
- Uses **ultrasonic sensors** for front and side distance measurement.
- Autonomous navigation with **obstacle avoidance**.
- **Concave surface detection** for improved path planning.
- Motor control for **forward, backward, and turning movements**.
- LED indicators for status signaling.
- Implemented using **Arduino and motor driver circuitry**.

## Project Video
Watch the project in action here:  
[Google Drive Link](https://drive.google.com/drive/folders/1lhsMXzJ-cibm2QbUYWzw19V2VRejsfO1?usp=sharing)

## Hardware Components
- **Arduino Uno** (Microcontroller)
- **HC-SR04 Ultrasonic Sensors** (Front & Side)
- **L298N Motor Driver Module**
- **DC Motors** (Right & Left)
- **LED Indicator**
- **Power Supply** (Battery)
- **PCB for Circuit Integration**

## Software Implementation
- Programmed in **C++ (Arduino IDE)**.
- Utilizes **pulseIn() function** for distance measurement.
- Implements **PWM motor control** for precise movements.
- Includes **custom movement functions** (turning, stopping, reversing).

## Circuit and PCB Design
The robot’s circuit was designed and fabricated using a **custom PCB** to integrate all components efficiently. The PCB layout was created through a collaborative effort to ensure optimal sensor and motor connections.

## My Contributions
- **Implemented the core Arduino code** for sensor data processing and motor control.
- **Developed movement algorithms** for obstacle avoidance and concave detection.
- **Collaborated with teammates on PCB design and fabrication**, ensuring proper hardware integration.

## How to Use
1. **Upload the code** to the Arduino Uno using the **Arduino IDE**.
2. **Connect the circuit components** as per the PCB design.
3. **Power the bot** using a suitable battery pack.
4. **Observe the movement** and concave detection functionality in action!

## Potential Enhancements
- Exploring **machine learning-based terrain recognition**.
- Integrating **infrared sensors** for improved accuracy.
- Enhancing **real-time feedback and logging** for better analysis.

