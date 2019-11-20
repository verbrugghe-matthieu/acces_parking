/*Programme teste boucle AMONT AVAL et fermeture barriere , ouverture barriere
 * description:test ouverture de la barriere 
 * lors de l'arrivé de la voiture sur la boucle AMONT
 * et fermeture de la barriere lors de l'arrivé de la voiture sur la boucle AVAL
 * date de creation:20/11/2019
 */


#include <Wire.h>
#include "I2C.h"

#define MECANISME 0x20        //0x20 est l'adresse du PCF8574 <<mecanisme>>
#define FERMERBARRIERE 126    //126 permet de fermer la barriere
#define OUVRIRBARRIERE 125    //125 permet d'ouvrir la barriere

void setup() {
  
Wire.begin();       //Permet de lancer l'initialisation I2C
Serial.begin(9600); //permet de lancer la communication avec le superviseur de arduino
initI2C(200);       //initialise la vitesse de la communication avec l'I2C

}

void loop() {
  Wire.beginTransmission(MECANISME); //lance la transmission avec le PCF8574<<mecanisme>>
  Wire.write(0x78);                 //P7|P6|P5|P4|P3|P2|P1|P0
                                    //0 |0 |1 |0 |1 |0 |0 |0
  Wire.endTransmission();           //arrette la transmission avec le PCF8574<<mecanisme>>
  Wire.requestFrom(MECANISME,1);    //demande de recevoir 1 octet a l'adresse de mecanisme
  
  while(Wire.available())           //attend la reponse
  {
    char a=Wire.read();             //recois la reponse octet par octet
    Serial.println(a,BIN);          //affiche l'octet recu avec un saut de ligne
    if(a==0x40)                     //si la voiture est detecte sur la boucle AMONT
    {
      Wire.beginTransmission(MECANISME); //lance la transmission avec le PCF8574<<mecanisme>>
      Wire.write(OUVRIRBARRIERE);        //envoie a l'esclave 125 pour ouvrir la barriere
      delay(1000);                       //delai de 1s
      Wire.endTransmission();            //arrette la transmission avec le PCF8574<<mecanisme>>
    }
    else if(a==0x20)                     //sinon si une voiture est dececte sur la boucle AVAL 
    {
      Wire.beginTransmission(MECANISME); //lance la transmission avec le PCF8574<<mecanisme>>
      Wire.write(FERMERBARRIERE);        //envoie a l'esclave 126 pour fermer la barriere
      delay(1000);                       //delai de 1s
      Wire.endTransmission();            //arrette la transmission avec le PCF8574<<mecanisme>>
    }
  }
  delay(500);                            //delay de 0,5s
 
}
