// C++ code
//
#include <Servo.h>

int left = 0;

int right = 0;

int front = 0;

int front_left = 0;

int front_right = 0;

int timer = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_9;

void setup()
{
  servo_9.attach(9);
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);

}

void loop()
{
  left = 0.01723 * readUltrasonicDistance(10, 11);
  right = 0.01723 * readUltrasonicDistance(12, 13);
  front = 0.01723 * readUltrasonicDistance(3, 2);
  servo_9.write(90);

  Serial.print("Left Motor :");
  Serial.println(left);
  Serial.print("Front Motor:");
  Serial.println(front);
  Serial.print("Right Motor:");
  Serial.println(right);
  
  if (front > 1 && front < 10) {
//    delay(1000); // Wait for 1000 millisecond(s)
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
  
      delay(1000);
  
      servo_9.write(0);
      delay(1`000); // Wait for 2000 millisecond(s)
      front_left = 0.01723 * readUltrasonicDistance(2, 1);
      delay(1000);
      Serial.print("Left reading:");
      Serial.println(front_left);
  
      servo_9.write(180);
      delay(1000); // Wait for 2000 millisecond(s)
      front_right = 0.01723 * readUltrasonicDistance(2, 1);
      delay(1000);
      Serial.print("Left reading:");
      Serial.println(front_right);
      
      //  turn left
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, HIGH);
      delay(7000);
  //
  //    if (front_right > front_left) {
  //      // turn right
  //      digitalWrite(4, HIGH);
  //      digitalWrite(5, LOW);
  //      digitalWrite(8, LOW);
  //      digitalWrite(7, HIGH);
  //    }
  //    if (front_right < front_left) {
  //      // turn left
  //      digitalWrite(4, LOW);
  //      digitalWrite(5, HIGH);
  //      digitalWrite(8, HIGH);
  //      digitalWrite(7, LOW);
  //    }
  }
//  if (left > 1 && left < 40) {
//    // turn right
//    digitalWrite(4, HIGH);
//    digitalWrite(5, LOW);
//    digitalWrite(8, LOW);
//    digitalWrite(7, HIGH);
//  }
//  if (right > 1 && right < 40) {
//    // turn left
//    digitalWrite(4, LOW);
//    digitalWrite(5, HIGH);
//    digitalWrite(8, HIGH);
//    digitalWrite(7, LOW);
//  }
// forward motion
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);

  Serial.println("--------------------------------");
}
