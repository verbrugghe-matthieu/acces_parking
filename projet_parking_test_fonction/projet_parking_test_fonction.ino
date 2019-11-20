/*Programme testant la boucle AMONT, AVAL et la fermeture , ouverture barriere
 * description:test ouverture de la barriere
 * lors de l'arrivé de la voiture sur la boucle AMONT
 * et fermeture de la barriere lors de l'arrivé de la voiture sur la boucle AVAL
 * date de creation:20/11/2019
 * ajout de fonction et des prototype non incluse au precedent programme.
 */

#include <Wire.h>
#include "I2C.h"
#include "fonction.h"

void setup() {
  
Wire.begin();       //Permet de lancer l'initialisation I2C
Serial.begin(9600); //permet de lancer la communication avec le superviseur de arduino
initI2C(200);       //initialise la vitesse de la communication avec l'I2C
}

void loop() {

  lireBoucle(); //permet de lire l'etat des boucles
  while(Wire.available()){  //attend la reponse
    char a=Wire.read();     //recois la reponse octet par octet
    Serial.println(a,BIN);  //affiche l'octet recu avec un saut de ligne
    if(a==0x40)             //si la voiture est detecte sur la boucle AVAL
    {
      fermerBarriere(MECANISME,FERMERBARRIERE); //ferme la barriere
    }
        
    else if(a==0x20)  //sinon si la voiture est detecte sur la bouche AMONT
    {
      ouvrirBarriere(MECANISME,OUVRIRBARRIERE); //ouvre la barriere
      while(a==0x00){
        lireBoucle(); 
        a=Wire.read();
        Serial.println(a,BIN); 
      }
    }
  }
  delay(500);
}
