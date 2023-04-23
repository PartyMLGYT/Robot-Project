#include "functions.h"
#include <Servo.h>


void setup() {
    Serial.begin(9600);
    motor.attach(PIN_PWM);
}

void loop() {
    motorController();
    findDistance();
}

