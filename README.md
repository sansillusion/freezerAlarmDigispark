# freezerAlarmDigispark
A open freezer alarm made with digispark arduino

Uses ky-024 magnetic hall sensor on pin 0, A mosfet on pin 1 to drive a warning led strip, and a ky-006 active buzzer on pin 3 for final alarm

if it does not detect a magnet on close to the sensor for 5 minutes it lights up the led strip and after 10 minutes a beep patern starts until a magnet is detected (could also be a simple switch on pin 0)
