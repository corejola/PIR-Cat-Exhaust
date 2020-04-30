# PIR Cat Exhaust System

A cat litter ventilation system utilizing an ***Arduino Uno*** and a HC-SR501 Passive Infrared (PIR) motion sensor.

# System Parameters
1. Cat litter volume: 70ft<sup>3</sup>
2. Typical bathroom exhaust: 8 air changes per hour
    - 560ft<sup>3</sup>/hr to be cycled through
    - Looking up fan speed to ~50CFM to reduce run time

# Questions:
- Volumetric Flow Rate: Q = ?
    - How long will the fan run? - 17mins (w/ a 32CFM fan)
    - Duct sizing. Diameter ~ 2-4"
- How will fan speed be determined? pre-determined resistance?
    - How to measure the CFM? Static Pressure?
- Pressure loss through duct system?
- Onshap model squar-round duct transition pieces to be 3D printed.

# Sequence of Operations (SOO)
1. Initial power up of the  HC-SR501 PIR sensor requires 1 minute for acclimatization to the infrared energy in the room.
    - LED Red Indicator on
2. PIR Ready
    - LED Green Indicator on
3. PIR Detected
    - LED Blue Indicator, delay 3s
    - Fan powered on for ~ 30s
4. PIR Reset
    - LED Blue off
    - Fan off
    - Refer back to SOO #2.

## Components:
1. Arduino Uno
2. HC-SR501 PIR Motion Detector
3. Cosair AF120 Fan
4. P2N222A Transistor

# Refereneces
- DroneBot Workshop