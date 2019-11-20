#include <Wire.h>
#include "I2C.h"

#define MECANISME 0x20

void setup() {

Wire.begin();         //rejoins le bus I2C
Serial.begin(9600);   //Initialise la transmission avec le moniteur série
initI2C(200);
}

void loop() {
      
  Wire.beginTransmission(MECANISME);
  Wire.write(0x78);
  Wire.endTransmission();
  Wire.requestFrom(MECANISME,1);     //demande 1octects de l'esclave a l'adresse de MECHANISME
  
  while(Wire.available())             
  {
    char a=Wire.read();                    
    Serial.println(a,BIN);
  }
  delay(500);

}
