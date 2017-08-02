# freezerAlarmNano
A open freezer alarm made with Arduino nano (168)

Uses ky-024 magnetic hall sensor on pin 7, 3 mosfet on pin 6, 9 and 10 to drive a warning rgb led strip, and a ky-006 active buzzer on pin 5 for final alarm

if it does not detect a magnet close to the sensor for 500 ms it lights up the led strip and fades from random color to random color for 10 minutes then it starts to beep until a magnet is detected (could also be a simple switch on pin 7)
