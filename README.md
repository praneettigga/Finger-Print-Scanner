# Finger-Print-Scanner

This project focuses on the design and implementation of a fingerprint-based electronic lock system using an Arduino microcontroller. The proposed system utilizes a fingerprint sensor module to capture and verify the identity of the user based on stored biometric data. If the fingerprint matches an enrolled template, the system triggers a relay to activate a 12V solenoid lock, granting access. Otherwise, access is denied and an appropriate message is displayed on a 16x2 LCD screen, providing clear real-time feedback to the user.

**Architecture**
  1.	Arduino Uno R3 Microcontroller:
    •	The Arduino microcontroller serves as the central control unit of the system. It handles all logic and coordination between components, including fingerprint data processing, input/output operations, and signal control.
    •	It is programmed to interact with the fingerprint scanner, process authentication data, manage the LCD display messages, and control the relay module to operate the solenoid lock based on user validation.
  
  2.	Fingerprint Scanner Module:
    •	The fingerprint sensor is the primary component responsible for user authentication. It captures the biometric data (fingerprint) of the user and compares it with stored templates in its memory.
    •	If the fingerprint matches a stored template, it sends a confirmation to the Arduino to trigger the unlocking process. If the match fails, access is denied, and a corresponding message is displayed.
  
  3.	16x2 LCD Display:
    •	The LCD module is used to provide real-time feedback to the user. It displays system status messages such as "Place Finger," "Access Granted," or "Access Denied."
    •	It enhances user interaction by showing clear prompts and system responses throughout the fingerprint verification process.
  
  4.	Relay Module & 12V Solenoid Lock:
    •	The relay module acts as an electronic switch controlled by the Arduino. Upon receiving a valid fingerprint match signal, the relay activates and supplies power to the solenoid lock.
    •	The solenoid lock physically locks or unlocks the door or compartment, depending on the control signal from the relay. It ensures that only authenticated users can gain access.
  
  5.	Breadboard & Jumper Wires:
    •	Used to establish connections between the different modules without soldering. They allow for flexible circuit setup, easy testing, and debugging during development.
