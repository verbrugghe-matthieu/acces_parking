#include <Wire.h>
#include "I2C.h"

#define MECANISME 0x20  //0x20 est l'adresse du PCF8574 <<mecanisme>>
#define MOTEUR 125    //125 permet d'ouvrir la barrière|126 permet de fermer la barriere

void setup() {
  
Wire.begin();       //Permet de lancer l'initialisation I2C
Serial.begin(9600); //permet de lancer la communication avec le superviseur de arduino
initI2C(200);       //initialise la vitesse de la communication avec l'I2C

}

void loop() {

  Wire.beginTransmission(MECANISME); //lance la transmission avec le PCF8574<<mecanisme>>
  Wire.write(MOTEUR);                 
                                     //P7|P6|P5|P4|P3|P2|P1|P0
                                     //X |1 |1 |1 |1 |0 |0 |0
  delay(1000);
  Wire.endTransmission();            //termine la transmission avec le PCF8574<<mecanisme>>
  

}
