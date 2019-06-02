/*****************************
 * Written by Daniel Payne
 * 6/2/2019
 * Servos without using delays
 ***********************************/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo2;

int ServoPinA =44;
int ServoPinB =46;

int servoInterval = 30; //15ms interval
int servoTimer = servoInterval*90; //90 degrees of rotation
long previousServoMillis;

boolean servoStateA = false;
boolean servoStateB = false;
boolean reverse = false;
int pos = 0;    // variable to store the servo position

void openGateA(){
    servoStateA = true;
}
void updateGateA(){
    if (servoState == true) {
        unsigned long currentMillis = millis();
        //forward movement
        if (reverse != true){
            if (currentMillis- previousServoMillis >= servoInterval) {
                previousServoMillis = currentMillis;
                myservo.write(pos);
                pos++;
            }
            if (pos >= 90){
                reverse = true;
            }
        
        }
        else {
            if (currentMillis- previousServoMillis >= servoInterval) {
                previousServoMillis = currentMillis;
                pos--;
                myservo.write(pos);
            }
            if (pos <= 0){
                reverse = false;
                servoState = false;
            }
        }
    }
}
void updateGateB(){
    if (servoStateB == true) {
        unsigned long currentMillis = millis();
        //forward movement
        if (reverse != true){
            if (currentMillis- previousServoMillis >= servoInterval) {
                previousServoMillis = currentMillis;
                myservo2.write(pos);
                pos++;
            }
            if (pos >= 90){
                reverse = true;
            }
        
        }
        else {
            if (currentMillis- previousServoMillis >= servoInterval) {
                previousServoMillis = currentMillis;
                pos--;
                myservo2.write(pos);
            }
            if (pos <= 0){
                reverse = false;
                servoStateB = false;
            }
        }
    }
}

void setup() {
  Serial.begin(115200);
  myservo.attach(ServoPinA);  // attaches the servo on pin 13 to the servo object
  myservo2.attach(ServoPinB);  // attaches the servo on pin 13 to the servo object
  previousServoMillis = millis();
  openGateA();
}

void loop() {
    
    updateGateA();
}
