# PIR Cat Exhaust System (Name Pending)

A cat litter ventilation system utilizing an ***Arduino Uno*** and a HC-SR501 Passive Infrared (PIR) motion sensor.

## System Parameters
1. Cat litter volume: 6ft<sup>3</sup>
2. Typical bathroom exhaust: 8 air changes per hour
    - 48ft<sup>3</sup>/hr to be cycled through
    - Will run 47 CFM fan for 10 mins

## Circuit Diagram
![Circuit Diagram](https://github.com/corejola/PIR-Cat-Exhaust/blob/readmeUpdate/PIR_Cat_Exhaust_Diagram%20&%20Notes.png?raw=true)

## System Diagram


## Sequence of Operations (SOO)
1. Initial power up of the  HC-SR501 PIR sensor requires 1 minute for acclimatization to the infrared energy in the room.
    - LED Red Indicator on 60S
    - Motion detected = 0
2. PIR Ready
    - LED Green Indicator on
        * If *push button* pressed during ready period, Fan will run for 5 mins
        * *Push button* is inactive during all Red LED times
3. PIR Detected
    - LED Green Indicator off
    - LED Blue Indicator on, delay 5min, motion detected = 1
    - 12VDC Fan powered on for 10min
4. PIR Reset
    - LED Red on 6S reset, motion dected = 0
    - LED Blue off
    - Fan off
    - Refer back to SOO #2.


### Components:
1. Arduino Uno
2. HC-SR501 PIR Motion Detector
3. [Coolerguys 120x120x25mm 3 Pin Fan 840556091929 Low](https://www.coolerguys.com/products/coolerguys-120mm-ms-fan-3-pin-fan-cg12025m12b2-3y)
    - 12VDC
    - Running Amp Draw .1A
    - 47 CFM
<!-- 4. P2N222A Transistor -->
<!-- 5. Diode model#? -->
