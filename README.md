# 🛴 Hybrid Kickboard: HighKick
> **Finalist of 2025 Inha University Idea Competition**
> *Implementing a sustainable campus mobility solution through user-participation and regenerative power management.*

---

## 📌 Project Overview
This project addresses the frequent battery depletion of shared e-kickboards during peak campus hours. By integrating **manual propulsion** with a **conditional motor boost** and **regenerative braking**, we proposed a solution that drastically extends mileage and enhances energy efficiency.

---

## 🛠 Key Technical Features

### 1. HighKick Mode (Conditional Boost)
To minimize energy waste during initial acceleration, the motor only activates when the user manually reaches a speed of $10 \, \text{km/h}$.
* [cite_start]**Logic:** `if (speed >= 10km/h && throttle == TRUE)` -> `Motor ON (3s Boost)`[cite: 90, 97].
* [cite_start]**Effect:** Prevents high-current draw during startup, the most energy-intensive phase[cite: 21].

### 2. Regenerative Braking System
Recovering kinetic energy during deceleration to recharge the battery.
* [cite_start]**Control:** MCU-based algorithm to manage reverse current and ensure battery safety[cite: 38].
* [cite_start]**Hardware:** Integrated Schottky Diodes and MOSFETs for stable power flow[cite: 168, 169].

---

## 💻 Tech Stack
* [cite_start]**Microcontroller:** Arduino Nano [cite: 252]
* [cite_start]**Design & Simulation:** Fritzing (Circuitry), CATIA (3D Modeling) [cite: 32, 242]
* [cite_start]**Algorithm:** Arduino C++ (Sensor Fusion & Logic Control) [cite: 33]

---

## 📊 Proven Impact (Based on Simulation)
Compared to standard shared kickboards (Beam Mobility):
* [cite_start]**Mileage:** Up to **1,011% increase** at 20% battery level[cite: 227].
* [cite_start]**Energy Efficiency:** **79% reduction** in annual power consumption[cite: 230].
* [cite_start]**Sustainability:** Estimated reduction of **954 kg of $CO_2$** per 200 units annually[cite: 240].

---

## 🧑‍💻 My Contribution
As a core team member, I focused on **Data-Driven Validation** and **Strategic Planning**:
* Conducted field research on battery depletion patterns of 50+ units via the Beam Mobility API/App[cite: 86].
* [cite_start]Performed user demand surveys (n=143) to identify critical pain points[cite: 86].
* [cite_start]Developed the economic feasibility model and break-even point analysis[cite: 252].
