#include <dht.h>
//the signal pin is connected to pin 7 for humidity and temperature sensor
dht DHT;

#define DHT11_PIN 7

#include <Wire.h>    //Include wire library 
#include <MPU6050_light.h>  //Include library for MPU communication

MPU6050 mpu(Wire);   //Create object mpu

unsigned long timer = 0;    


int Moisture_signal = A0;

void setup(){
  Serial.begin(9600);

  Wire.begin();     
  mpu.begin();     
//  Serial.print(F("MPU6050 status: "));
//  Serial.println(F("Calculating offsets, do not move MPU6050"));   
  delay(1000);
  mpu.calcGyroOffsets();     //Calibrate gyroscope
//  Serial.println("Done!\n");

}

void loop(){
  delay(1000);
  int chk = DHT.read11(DHT11_PIN);
//  Serial.print("Temperature = ");
  Serial.print(DHT.temperature);
  Serial.print(" ");
//  Serial.print("Humidity = ");
  Serial.print(DHT.humidity);
  Serial.print(" ");
  delay(1000);

    mpu.update();    //Get values from MPU
//    Serial.print("Angle x = ");
    Serial.print(int(mpu.getAngleX()));
    Serial.print(" ");
//    Serial.print("Angle y = ");
    Serial.print(int(mpu.getAngleY()));
    Serial.print(" ");
//    Serial.print("Angle Z = ");
    Serial.print(int(mpu.getAngleZ()));
    Serial.print(" ");
    delay(100);

  int Moisture = analogRead(Moisture_signal);
//  Serial.print("Soil Moisture Level: ");
  Serial.print(Moisture);
  Serial.print("\n");
  delay(200);
//  Serial.println("---------------------------------------------");
  
}
