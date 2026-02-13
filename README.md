
<div align="center">
  <img src="https://i.imgur.com/8T0b9uv.png" alt="Front View" height="300">
  <img src="https://i.imgur.com/PClQnu1.png" alt="Perspective View" height="300">
  
  <p><em>Concept images rendered in Blender</em></p>

  # RZK Flame Spark Bloom (FS-B1)

  ![Status](https://img.shields.io/badge/Status-Early_Development-%23b1fc03)
  ![Version](https://img.shields.io/badge/Version-0.0.0-orange)
  ![Hardware](https://img.shields.io/badge/Hardware-Teensy_4.1-blue)

[![License: CC BY-NC-SA 4.0](https://licensebuttons.net/l/by-nc-sa/4.0/80x15.png)](https://creativecommons.org/licenses/by-nc-sa/4.0/)
This work is licensed under a [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](https://creativecommons.org/licenses/by-nc-sa/4.0/).

  ---

## ⚠️❗Attention! This project is in early development. Many things are still being planned and may (And will) change without notice.

  <p>
    A DIY sampler based on the Teensy 4.1 development board, focused on beatmaking, sampling, and live music production.
  </p>
</div>

---

## 📋 Contents

1. [About](#-about)
2. [Features](#-features)
3. [Components](#-components)
4. [Technologies](#-technologies)
5. [Instructions](#-instructions)
6. [Roadmap](#-roadmap)
7. [License](#-license)

---

## 📖 About

This project was born out of three of my great passions: **beatmaking, electronics, and design**. 

Currently, there are many hardware alternatives that serve similar purposes (like the SP-404 or MPCs), but almost none of them are truly open source. This project aims to bridge that gap with the following philosophy:

- **Open Source:** Code and schematics are available for anyone to experiment with, modify, and reinvent their own machine.
- **Budget Friendly:** Designed using components easily found in standard electronics stores (except for the Teensy board, available at Sparkfun or similar distributors).
- **DIY Enclosure:** The casing is designed to be adaptable. You can use any plastic container or 3D print your own, as long as you have the tools for cutting and drilling.
- **Expandable:** Modifications are welcome! I highly value feedback from the beatmaking, electronics, and maker communities. 

---

## 🎛 Features

### Hardware
- **16 Mechanical Switches:** Used for finger drumming and live performance. I chose mechanical key switches (Cherry MX style) for that tactile clicky sensation and durability.
- **8 Potentiometers:** For real-time control of effects, volume, and parameters.
- **4 Encoders:** Endless rotary encoders for ADSR control, menu navigation, and fine-tuning values.
- **3 Joysticks:** Why not make it fun and expressive? Map values to X and Y axes to manipulate effects while playing live.
- **9 Function Buttons:** System controls including "Save", "Open", "Undo", "Quantize", and Shift shortcuts.

### Software (Planned)
- **Sample Playback:** Low latency triggering from SD card.
- **Sequencer:** Step sequencer and live recording.
- **Effects:** Reverb, Delay, and Bitcrusher implementation.

---

## 🔌 Components

List of main components used in this build:

* **1x**- Teensy 4.1
* **1x**- Teensy Audio Shield
* **1x**- 2.0 inch TFT Display OLED LCD 
* **16x**- Cherry MX Mechanical Switches
* **16x**- Key caps
* **8x**- B10k potentiometers
* **4x**- Rotary encoders with switch
* **3x**- Joystick module
* **9x**- Push Button (Or more mechanical switches)
* **3x**- CD74HC4067 16-Channel Digital Multiplexer Breakout Board Module
* **1x**- Enclosure. You can use plastic containers, metal containers, recycled boxes, 3D printed case, or even make your own cardboard box using the template in this repository. Get creative and make something amazing and original!

---

## 🛠 Technologies

I am using the following technologies and libraries. Big thanks to their creators and maintainers:

* [Arduino IDE](https://www.arduino.cc/en/software/) - Main development environment.
* [Teensy Audio Library](https://www.pjrc.com/teensy/td_libs_Audio.html) - The core engine for audio processing.
* **KiCad** - Used for schematic capture and PCB design.

---

## 🚀 Instructions

### **Assembly and Wiring**
> 🚧 **Work in Progress:** Detailed wiring diagrams and assembly guide coming soon. 
### You can view the current schematics [HERE](https://i.imgur.com/oImRSiw.png).

The interactive wiring diagram is hosted on Cirkit Designer. Since GitHub doesn't allow interactive embeds, **click the image below to open the interactive viewer**: 

<a href="https://app.cirkitdesigner.com/project/12ed71a3-bdbf-4b91-8f72-1112bf8fde8e?view=interactive_preview" target="_blank"> 
  <img src="https://i.imgur.com/oImRSiw.png" alt="Interactive Wiring Diagram" width="100%"> 
</a> 

<p align="center">   
  <a href="https://app.cirkitdesigner.com/project/12ed71a3-bdbf-4b91-8f72-1112bf8fde8e" target="_blank">Edit in Cirkit Designer</a>
</p>

### **Flashing the Firmware**

1. Clone the repository:
```bash 
git clone [https://github.com/tu-usuario/tu-proyecto.git](https://github.com/tu-usuario/tu-proyecto.git)
```
2.   Open the `.ino` file in Arduino IDE.
    
3.  Select **Teensy 4.1** from the board manager.
    
4.   Compile and Upload.
 
 ### Turtorial can be found [HERE](URLexample).
---

## 🗺 Roadmap

Cosas por hacer XD

---
## 📄 License

Aún por definir, debo investigar XDe

---
