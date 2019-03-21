/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo1;                                       // create servo object to control a servo
Servo myservo2; 
//Servo myservo3; 
//Servo myservo4;

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);                                // initialize serial communication at 9600 bits per second:
  myservo1.attach(10);  // attaches the servo 1 on pin 9 to the servo object
  myservo2.attach(11);  // attaches the servo 2 on pin 8 to the servo object
 // myservo3.attach(12);  // attaches the servo 3 on pin 10 to the servo object
 // myservo4.attach(13);  // attaches the servo 3 on pin 10 to the servo object
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
 // myservo3.write(pos);              // tell servo to go to position in variable 'pos'
 // myservo4.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
  //myservo3.write(pos);              // tell servo to go to position in variable 'pos'
  //myservo4.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
}
