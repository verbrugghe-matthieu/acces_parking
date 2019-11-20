#ifndef FONCTION_H
#define FONCTION_H
#define MECANISME 0x20        //0x20 est l'adresse du PCF8574 <<mecanisme>>
#define FERMERBARRIERE 126    //126 permet de fermer la barriere
#define OUVRIRBARRIERE 125    //125 permet d'ouvrir la barriere
#define ES 0x78

#include "Arduino.h"

void ouvrirBarriere(int adress,int valeur);
void fermerBarriere(int adress,int valeur);
char lireBoucle();



#endif
