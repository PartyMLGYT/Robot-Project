#include "functions.h"
#include <Servo.h>

/*
Write functions here:

void example_fun(args1, args2){
    code
}
*/

void findDistance(){
    // int pingPin = 5;
    
    // establish variables for duration of the ping, and the distance result
    // in inches and centimeters:
    long duration, inches, cm;

    // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    pinMode(pingPin, OUTPUT);
    digitalWrite(pingPin, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(pingPin, LOW);

    // The same pin is used to read the signal from the PING))): a HIGH pulse
    // whose duration is the time (in microseconds) from the sending of the ping
    // to the reception of its echo off of an object.
    pinMode(pingPin, INPUT);
    duration = pulseIn(pingPin, HIGH);

    // convert the time into a distance
    inches = microsecondsToInches(duration);
    cm = microsecondsToCentimeters(duration);


    /*
    To test out if it works:

    Serial.print(inches);
    Serial.print("in, ");
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    */
    

    delay(100);


    long microsecondsToInches(long microseconds) {
        // microseconds per inch (i.e. sound travels at 1130 feet per second).
        // This gives the distance travelled by the ping, outbound and return,
        // so we divide by 2 to get the distance of the obstacle.
        // See: https://www.parallax.com/package/ping-ultrasonic-distance-sensor-downloads/
        return microseconds / 74 / 2;
    }

    long microsecondsToCentimeters(long microseconds) {
        // The speed of sound is 340 m/s or 29 microseconds per centimeter.
        // The ping travels out and back, so to find the distance of the object we
        // take half of the distance travelled.
        return microseconds / 29 / 2;
    }
}

void motorController(){
    Servo motor;

    // constants won't change.
    #define PIN_POTENTIOMETER 2
    #define PIN_PWM 9

    int potValue = analogRead(PIN_POTENTIOMETER);
    int speed = map(potValue, 0, 1023, 0, 180);
    
    if(speed == 90) motor.write(LOW);
    
    delay(30);
    motor.write(speed);
    
    delay(300);
}