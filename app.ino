#include <Servo.h>

const int servo1 = 10;      //servo#1 to digital 10~
const int servo2 = 11;      //servo#2 to digital 11~
const int servo3 = 9;       //servo#3 to digital 9~
const int joyB = 2;         //SW(switch) to digital 2
const int joyH = A4;        //x axis to A4
const int joyV = A3;        //y axis to A3

int servoVal;

Servo myservo1;
Servo myservo2;
Servo myservo3;

void setup() {
  // Servo
  myservo1.attach(servo1);
  myservo2.attach(servo2);
  myservo3.attach(servo3);
  pinMode(joyB, INPUT_PULLUP);
  //myservo3.write(0);

  // Initialize Serial
  Serial.begin(9600);
  
}

void loop() {
  //Display Joystick values using the serial monitor
  outputJoystick();

  // Read the horizontal joystick value (between 0 and 1023)
  servoVal = analogRead(joyH);
  servoVal = map(servoVal, 0, 1023, 0, 180);        // scale it to use with the servo (result between 0 and 180);

  myservo1.write(servoVal);                         // sets the servo postion according to the scaled value

  //Read the vertical joystick value (value between 0 and 1023)
  servoVal = analogRead(joyV);
  servoVal = map(servoVal, 0, 1023, 0, 180);

  myservo2.write(servoVal);

  //Read the button joystick
  servoVal = digitalRead(joyB);
  if(servoVal == LOW){
   myservo3.write(180);
  }
  else{
   myservo3.write(0);
  } 
  

  delay(100);
}


/**
* Display joystick values
*/
void outputJoystick(){

    Serial.print(analogRead(joyH));
    Serial.print ("---"); 
    Serial.print(analogRead(joyV));
    Serial.println ("----------------");
    Serial.print(digitalRead(joyB));
    Serial.print ("-------");
}
