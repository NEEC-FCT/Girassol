#include <Servo.h>


Servo myservoX;
Servo myservoY;

int pos1 = 90;
int pos2 = 90;

void setup() {
  myservoX.attach(9);
  myservoY.attach(10);
  Serial.begin(9600);
  myservoX.write(pos1);
  myservoY.write(pos2);  
}

void loop() {
  int sensorValue1 = analogRead(A0);
  int sensorValue2 = analogRead(A1);
  int sensorValue3 = analogRead(A2);
  int sensorValue4 = analogRead(A3);

  int difSensor1 = sensorValue1 - sensorValue2;
  int difSensor2 = sensorValue3 - sensorValue4;

  if (abs(difSensor2) > 60) {
    if (sensorValue4 < sensorValue3) {
      if(pos1<170) {
      myservoX.write(pos1);
      pos1++;
      }
    }
    else {
      if(pos1>5) {
      myservoX.write(pos1);
      pos1--;
      }
    }
  }

  if (abs(difSensor1) > 60) {
    if (sensorValue1 < sensorValue2) {
      if(pos2<170) {
      myservoY.write(pos2);
      pos2++;
      }
    }
    else {
      if(pos2>5) {
      myservoY.write(pos2);
      pos2--;
      }
    }
  }
  delay(10);



    

  }

