# IR-based-digital-tachometer
Digital tachometer using IR sensor is a contact less method to monitor the speed of a rotating machine.A tachometer is a device used to measure the RPM or Revolutions Per Minute of any rotating body. Tachometers can be contact based or non-contact ones. The non-contact or contact-less optical tachometers usually use laser or Infrared beam to monitor the rotation of any body. This is done by calculating time taken for one rotation.

## Calculation of rpm 
This program basically monitors the IR sensor's value constantly and with the highest priority using Interrupts.

The Arduino Uno has 3 interrupts and the Interrupt 0 is pin 2 on the arduino.

This line attaches an interrupt to pin 2 on arduino in "RISING" mode. This means that whenever the sensor goes from LOW to HIGH , the function RPMCount(); is invoked.

Depending on the type of propeller, the interrupt service routine(isr) will be called for example for twin blade propeller the isr will be called twice where the revolutions are incremented.

The code continuously monitors the revolutions and the time taken for that particular number of revolutions. using the millis() function.
Therefore (revolutions/2)/(millis()-time) will give the revolutions per millisecond to convert to rpm just use the below formula.
=> rpm = 60*1000 / t * actualREV => rpm = 60*1000 / (millis() - time ) * REV/2
=> rpm = 30*1000 / (millis() - time) * REV;

The rpm is then displayed to a serial monitor.
