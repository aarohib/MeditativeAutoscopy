/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

#include <Servo.h>


Servo myservo;                                       // create servo object to control a servo
const int numReadings = 15;
int readings[numReadings];                           // the readings from the analog input
int readIndex = 0;                                   // the index of the current reading
int total = 0;                                       // the running total
int average = 0;                                     // the average
int sensorValue = A0;                                // sensor value attached ot pin A0
int pos = 0;                                         // variable to store the servo position
int poschng;

// the setup routine runs once when you press reset:
void setup() 
{
  Serial.begin(9600);                                // initialize serial communication at 9600 bits per second:
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  for (int thisReading = 0; thisReading < numReadings; thisReading++) 
  {
    readings[thisReading] = 0;
  }
}

// the loop routine runs over and over again forever:

void loop()
{
  total = total - readings[readIndex];               // subtract the last reading:
  readings[readIndex] = analogRead(sensorValue);     // read from the sensor:
  total = total + readings[readIndex];               // add the reading to the total:
  readIndex = readIndex + 1;                         // advance to the next position in the array:
  if (readIndex >= numReadings)                      // if we're at the end of the array...
  {
    readIndex = 0;                                   // ...wrap around to the beginning:
  }
  average = total / numReadings;                     // calculate the average:
 Serial.println(average);                            // send it to the computer as ASCII digits
 delay(1);                                           // delay in between reads for stability
 poschng = map(average, 600, 800, 0, 180);
 analogWrite(9, poschng);
 myservo.write(poschng);                             // tell servo to go to position in variable 'poschng'
 delay(15); 
}
