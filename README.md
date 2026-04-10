# Bio-Contractor
Synth / drum machine with Arduino

---

## Demo
https://www.youtube.com/watch?v=Z5vrkXOSQN8

---

## Overview
Bio-Contractor is a hardware hacking project that converts a 1990s electrostimulator into a playable drum machine / synthesizer using Arduino.

Instead of building an instrument from scratch, this project reuses the original enclosure, knobs, switches, and interface of an existing device, turning its physical controls into a sound engine.

---

## Hardware

- Arduino Nano R4 (UNO / UNO R4 WiFi also compatible)
- 5 potentiometers (reused from original device)
- 2 switches (reused)
- 1 LED
- 1 audio output jack
- DC input (optional)

The original electrostimulator electronics are not required for the system to function.

---

## Circuit

- Potentiometers → Analog inputs  
- Switches → Digital inputs  
- LED → Digital output  
- Audio jack → DAC output  

Power:
- USB-C **or**
- 5V via VIN and GND  

---

## Sound Engine

Audio is generated directly from the Arduino:

- Samples encoded as **raw, headerless, signed 8-bit PCM @ 16384 Hz**
- Stored in Flash memory as arrays
- Playback handled with **Mozzi**

---

## Samples

- Drum sounds from **Boss DR-110**
- Voice samples:
  - “Arduino”
  - “Open Source”

---

## Controls

- Bottom-right knob → BPM  
- Main switch → Play / Stop  
- Remaining knobs → Pattern + sample triggering  
- LED → BPM indicator  
- Secondary switch → FM synthesis with random variations  

---

## Calibration

Old potentiometers have inconsistent ranges.

A calibration script maps real min/max values to usable ranges.  
(Not required with new components)

---

## Upload

1. Connect Arduino  
2. Open Arduino IDE  
3. Upload firmware  

Audio output connects to:
- Mixer
- Amplified speakers

---

## Improvements

- Reduce output noise  
- Add switches for distortion / modulation  
- Replace unused panel elements  

---

## Notes

This project focuses on reusing existing hardware rather than designing new instruments.  
The constraints of the original device become part of the sound and interaction model.

---

## Author

Roni Bandini
