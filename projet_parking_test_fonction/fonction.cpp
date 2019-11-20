#include "fonction.h"
#include <Wire.h>


void ouvrirBarriere(int adress, int valeur){
  Wire.beginTransmission(adress);
  Wire.write(valeur);
  delay(1000);
  Wire.endTransmission();  
}

void fermerBarriere(int adress,int valeur){
  Wire.beginTransmission(adress);
  Wire.write(valeur);
  delay(1000);
  Wire.endTransmission();   
}
char lireBoucle(){
  Wire.beginTransmission(MECANISME);
  Wire.write(ES);
  Wire.endTransmission();
  Wire.requestFrom(MECANISME,1);
}
