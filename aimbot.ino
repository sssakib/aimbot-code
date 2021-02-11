#include <HCSR04.h>
#include <HC05.h>
#include<Servo.h>
#define echoPin 2
#define trigPin 3
#define servopin 4
int duration;
int distance;
  Servo servo1;
void setup()
{
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  servo1.attach(servopin);
  Serial.begin(9600);
}
void loop()
{ digitalWrite(trigPin,LOW);
 
  digitalWrite(trigPin,HIGH);
  delay(3);
  digitalWrite(trigPin,LOW);
  duration =pulseIn(echoPin,HIGH);
  distance=duration*0.017;
  Serial.print(distance);
  Serial.println("cm");
  servo(distance);
 }
 void servo(int distance)

 { servo1.write(0);
  if (distance<=30)
  {servo1.write(60);
   delay(2000);
   servo1.write(0);}
   }
