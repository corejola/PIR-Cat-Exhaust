# PIR Cat Exhaust System

A cat litter ventilation system utilizing an ***Arduino Uno*** and a HC-SR501 Passive Infrared (PIR) motion sensor.

# System Parameters
1. Cat litter volume: 6ft<sup>3</sup>
2. Typical bathroom exhaust: 8 air changes per hour
    - 48ft<sup>3</sup>/hr to be cycled through
    - Will run 45CFM fan for 10 mins

# Sequence of Operations (SOO)
1. Initial power up of the  HC-SR501 PIR sensor requires 1 minute for acclimatization to the infrared energy in the room.
    - LED Red Indicator on
2. PIR Ready
    - LED Green Indicator on
    - If push button pressed during ready period, Fan will run for 5 mins
    - Push button is inactive during all Red LED times
3. PIR Detected
    - LED Green Indicator off
    - LED Blue Indicator on, delay 5min
    - 12VDC Fan powered on for 10min
4. PIR Reset
    - LED Red on
    - LED Blue off
    - Fan off
    - Refer back to SOO #2.


## Components:
1. Arduino Uno
2. HC-SR501 PIR Motion Detector
3. CG Fan 12VDC 45CFM
4. P2N222A Transistor
