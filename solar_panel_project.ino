/*
This project is a prototype for a solar panel that shifts
towards the direction with more sunlight.

  >Created July 23, 2018
  >By Arvin R. Matabang
*/
//----------------------------------------------------------------------------
//Variable Declarations
#include <Stepper.h>
int rightLDR = A1;                                        //Right light sensor
int leftLDR = A0;                                         //Left light sensor
const int stepsPerRevolution = 200;                       //Should be modified depending on the type of motor used (28BYJ-48 5v DC motor)
int sensorValueLeft = 0;                                  //Variable storage for left sensor
int sensorValueRight = 0;                                 //Variable storage for right sensor
Stepper myStepper (stepsPerRevolution, 1,3,2,4);
//----------------------------------------------------------------------------
//Setup Declaration
void setup() {
  myStepper.setSpeed(60);                                 //Speed set to 60
}
//----------------------------------------------------------------------------
//Main Declaration
void loop() {
  while (1) {
    sensorValueLeft = analogRead(leftLDR);
    sensorValueRight = analogRead(rightLDR);
    delay(500);
    int difference = sensorValueLeft - sensorValueRight;
    difference = ((difference < 0)? difference*-1:difference);
    if (difference > 10 && sensorValueLeft > sensorValueRight) {
      myStepper.step(stepsPerRevolution);
      }
    else if (difference > 10 && sensorValueLeft < sensorValueRight) {
      myStepper.step(-stepsPerRevolution);
      }
    }
}
