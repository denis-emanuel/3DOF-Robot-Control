#include <Servo.h>
#include <math.h>

Servo servo1;
Servo servo2;
Servo servo3;

//pini joystick
int joystickX=0;
int joystickY=1;

//valori de intrare de la joystick
int valJoyX;
int valJoyY;

double Px, Py, Pz;
double q1, q2, q3;
double cosq1;
double pi = 3.14;

void setup() {
  Serial.begin(9600);
  servo1.attach(3);
  servo2.attach(10);
  servo3.attach(11);
}

void loop() {
  //citire valori servo
  valJoyX=analogRead(joystickX);
  valJoyY=analogRead(joystickY);
  Serial.println(valJoyX);
  Serial.println(valJoyY);
//  if(valJoyY<512)
//    valJoyY=512;

//  Px=map(valJoyX, 0, 1023, -0.08, 0.08); 
//  Py=map(valJoyY, 1023, 512, 0.00001, 0.08); 
  Px= ((valJoyX-512)* 8/512) ;
  Py= ((valJoyY -512) * (8/512));
  Py=((valJoyY -512)*8)/512;
  Serial.println("Px:");
  Serial.print(Px);
  Serial.println(" ");
  Serial.println("Py:");
  Serial.print(Py);
  Serial.println(" ");
  Pz=0.139; //constanta, 14cm

  q1=-atan2(Px,Py);
  Serial.println("q1:");
  Serial.print(q1);
  Serial.println(" ");
  cosq1=1/( sqrt( pow(Px/Py, 2) + 1 ) ) + 0.001;
//  Serial.println("cosq1:");
//  Serial.print(cosq1);
//  Serial.println(" ");


  double Q2;
  Q2=( (pow(Pz/2-0.07,2) - 3*Py/cosq1 + pow(Py/(2*cosq1),2)) / (3*(Pz-0.14)) );
//  Serial.println("Q2:");
//  Serial.print(Q2);
//  Serial.println(" ");


  q2=asin(Q2);
//  Serial.println("q2:");
//  Serial.print(q2);
//  Serial.println(" ");
  double aux3;
  aux3=Pz/2-0.07-3*Q2;
//  Serial.println("aux3:");
//  Serial.print(aux3);
//  Serial.println(" ");

  q3=asin(aux3)-q2;
//  Serial.println("q3:");
//  Serial.print(q3);
//  Serial.println(" ");
  
  q1=q1*180/pi;
  q2=q2*180/pi;
  q3=q3*180/pi;
  
  servo1.write(q1);
  servo2.write(q2);
  servo3.write(q3);

//  Serial.print(q1);
//  Serial.print(q2);
//  Serial.print(q3);

  

  Serial.println("-------");

  delay(2000);
  
}
