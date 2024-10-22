# EZ Distancing

![badge](https://img.shields.io/badge/Status-In_Development-red)
![licence](https://img.shields.io/badge/Licence-MIT-green)

## EZ Distancing is an Arduino project that encourages users to follow social distancing protocols
This Arduino project uses 2 Passive Infrared Sensors (PIR) and 2 Ultrasonic Distance Sensors to detect if another person is within the users 2 meter social distancing bubble. If the device detects that a person is within a 2 meter radius of the user, it will alert them, letting them know that they should move away to maintain social distancing. If the person is maintaining their social distancing, it will let them know that they are the recommended distance away from others.

## How it works

- The 2 Ultrasonic sensors measure the distance of the target object by emitting ultrasonic sound waves. The sensor determines the distance of an object by calculating the time it takes to send and receive a pulse.

- The Passive Infrared sensors measure the amount of IR light (or heat) that an object gives off. These sensors are being used to differentiate between non-living and living things. 

- When the device detects that another person is too close, it will give the user alerts via an OLED or LCD display and a LED/vibration motor.

- The DIP switches allow the user to choose which alerts they want to receive. Individual components can be turned off, like the LED or vibration motor.

## Component Usage

- Arduino Uno:
Microcontroller that will be handling all of the code, data, and inputs/outputs


- OLED or LCD Screen:
To give the user different text based alerts


- Distance Sensors:
Ultrasonic sensor that measures distance from 2cm - 400cm


- Motion Sensors:
Passive Infrared Sensor that measures 6 to 7 meters at 110 degrees


- Vibration Motor:
Vibration to physically alert the user 


- LED:
Light to visually alert the user 

- DIP switches:
This is to turn off any specific components, such as the LCD, OLED display, or vibration motor. This component is optional and wont require any changes to the code.

- Switch:
This will be used to turn the whole system on or off.





## Components List

#### All of the components used can be easily sourced on Amazon for about $100USD or $130 CAD
  - 1x Arduino R3 | [Arduino](https://store.arduino.cc/usa/arduino-uno-rev3) | [Amazon](https://amzn.to/39Mofgh) | [Arduino Datasheet](https://github.com/hightechu/hightechu-ez-distancing/blob/readme-updates/Datasheets/Arduino%20Datasheet.pdf)
  - 1x OLED Display | [Amazon](https://amzn.to/3oUkh9T) |  [OLED Datasheet](https://github.com/hightechu/hightechu-ez-distancing/blob/readme-updates/Datasheets/OLED%20Datasheet.pdf) This Diplay is also an option: [Adafruit](https://www.adafruit.com/product/1447)
  - 2x PIR Sensors | [Amazon](https://amzn.to/3jdQJ5E) | [Digikey](https://www.digikey.ca/en/products/detail/parallax-inc/555-28027/1774435?utm_adgroup=Sensors%2C%20Transducers&utm_source=google&utm_medium=cpc&utm_campaign=Smart%20Shopping_Product_Sensors%2C%20Transducers&utm_term=&productid=1774435&gclid=Cj0KCQiA34OBBhCcARIsAG32uvMqh89rxO9f6xbPtkStzS1uTOP_4cBgo2jJ0Yx7L0SRGLpPSkWOQioaAnQyEALw_wcB) | [PIR Datasheet](https://github.com/hightechu/hightechu-ez-distancing/blob/readme-updates/Datasheets/PIR%20Datasheet.pdf)
  - 2x Ultrasonic Distance Sensors | [Amazon](https://amzn.to/3cDDKZL) | [Digikey](https://www.digikey.ca/en/products/detail/parallax-inc/28015/1774419?utm_adgroup=Sensors%2C%20Transducers&utm_source=google&utm_medium=cpc&utm_campaign=Smart%20Shopping_Product_Sensors%2C%20Transducers&utm_term=&productid=1774419&gclid=Cj0KCQiA34OBBhCcARIsAG32uvNk1lc0XfCvlnqHobZl1Lc-1du7r6fmTYBBKW3S_xN-guYmEQOqYQAaAvb3EALw_wcB) | [Ultrasonic Datasheet](https://github.com/hightechu/hightechu-ez-distancing/blob/readme-updates/Datasheets/Ultrasonic%20Datasheet.pdf)
  - 1x Vibration Motor | [Amazon](https://amzn.to/2O4mnXT) | [Banggood](https://usa.banggood.com/Vibration-Motor-Module-Mini-Flat-Vibrating-DC-Motor-p-1334091.html?utm_source=googleshopping&utm_medium=cpc_organic&gmcCountry=CA&utm_content=minha&utm_campaign=minha-cag-en-pc&currency=CAD&cur_warehouse=CN&createTmp=1&utm_source=googleshopping&utm_medium=cpc_bgcs&utm_content=haosen&utm_campaign=haosen-ssc-cag-newcustom-ncv95-all-1102-11sale&ad_id=476723707835&gclid=Cj0KCQiA34OBBhCcARIsAG32uvMU1VkPf0bBRYoDsNWxX3LmyqV14ncTnp0zzH0OvhrRb4vWF30xCygaAnIaEALw_wcB)
  - 1x LED Light | [Amazon](https://amzn.to/2MWNaoA) | Any basic LED light will work
  - 1x 330 Ohm Resistor | [Amazon](https://amzn.to/2MNKfhM) | Any 330 ohm resistor will work
  - 1x Power Switch | [Amazon](https://amzn.to/2O3LQ3I) | This can be any type of basic switch
  - 1x DIP Switches | [Amazon](https://amzn.to/3je81Q0) | For the dipswitches, you can also use multiple normal switches
  - 1x Arduino 9v Battery Clip | [Amazon](https://amzn.to/3aAL9Gw) | This needs to be a 9V battery clip to 5.5mm barrel jack adapter
  - 1x 9 Volt Battery | [Amazon](https://amzn.to/36EQhbG) | Any 9V battery will work


 ## Diagrams | [See the Digital Circuit Here](https://www.tinkercad.com/things/4oZ3T0bb2it)
![EZ Social Distancing](https://github.com/hightechu/hightechu-ez-distancing/blob/readme-updates/Images/nolabels.png)
![EZ Social Distancing Labels](https://github.com/hightechu/hightechu-ez-distancing/blob/readme-updates/Images/lables.png)

## Schematic | Drawn using [Fritzing](https://fritzing.org/)
![EZ Social Distancing Schematic](https://github.com/hightechu/hightechu-ez-distancing/blob/readme-updates/Images/schematic.png)



## Wiring List
### LCD (Note: This is for the Arduino 16x2 display. This will need the [LCD specific code](https://github.com/hightechu/hightechu-ez-distancing/blob/development/Arduino%20Code/EZ%20Social%20Distance%20(LCD16x2)/EZ%20Social%20Distance%20(LCD16x2).ino))
- GND → Ground
- VCC → Positive
- V0 → potentiometer wiper pin → Positive (5V) + Ground
- RS → Digital 2
- R/W → Ground
- E → Digital 6
- D0 → Nothing
- D1 → Nothing
- D2 → Nothing
- D3 → Nothing
- D4 → Digital 5
- D5 → Digital 4
- D6 → Digital 3
- D7 → Digital 7
- A (Anode) → 220 Ohm resistor → Positive (5V)
- K (Cathode) → Ground


### OR


### OLED (Note: This wiring list is for the OLED. This will need the [OLED specific code](https://github.com/hightechu/hightechu-ez-distancing/blob/development/Arduino%20Code/EZ%20Social%20Distance%20(OLED)/EZ%20Social%20Distance%20(OLED).ino))
- GND → Dipswitch 2 → Ground
- VCC → Positive (5V)
- SCK → Analog 4
- SDA → Analog 5

### LED:
- Cathode (Long Side) → Dipswitch 3 → Ground
- Anode (Short Side) → 330 Ohm resistor → Digital 10


### Vibration Motor:
- GND → Ground
- VCC → Positive (5V)
- IN → Digital 9


### DIP switches:
- Switch 1 (LED Resistor) → Digital 10 (This dipswitch is to turn the LED alerts on/off)
- Switch 2 (Vibration Motor In) → Digital 9 (This dipswitch is to turn the vibration alerts on/off)

### PIR Sensor 1:
- Signal → Digital 11
- Power → Positive (5V)
- GND → Ground

### PIR Sensor 2:
- Signal → Digital 12
- Power → Positive (5V)
- GND → Ground

### Ultrasonic Distance Sensor 1:
- VCC → Positive (5V)
- Trig → Analog 2
- Echo → Analog 3
- GND → Ground

### Ultrasonic Distance Sensor 2:
- VCC → Positive (5V)
- Trig → Analog 1
- Echo → Analog 0
- GND → Ground
