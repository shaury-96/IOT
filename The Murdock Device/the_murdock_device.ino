#include <Arduino.h>
#define trigPin 12
#define echoPin 11
#define motor 9
void setup() {
 Serial.begin(9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(motor,OUTPUT);
}
void loop() {
 long duration, distance;
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH); // For sending trigger signal out of the trx
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
 distance = duration * 0.0340 / 2;
 Serial.println(distance);
 if (distance <= 75) 
 {
 analogWrite(motor,254- distance); 
 }
 if (distance > 75) 
 {
 analogWrite(motor,0); 
 }
delay(500);
}