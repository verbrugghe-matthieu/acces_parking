#include <Wire.h>
#include  
void setup() {
  Wire.begin();
  pinMode(BOUCLEAMONT, INPUT);
  pinMode(BOUCLEAVAL, INPUT);
  pinMode(VALIDATION, INPUT);
  Serial.begin(9600);

}

void loop() 
{
  int tempo = 0, testTempo;
  static int nombreVoiture = 0;

  if (digitalRead(BOUCLEAMONT) == 1 && digitalRead(BOUCLEAVAL)  == 0)
  {
    if (digitalRead(VALIDATION) == 1)
    {
      testTempo = 1;
      commandeBarriere(OUVRIR, 2);
      while (digitalRead(BOUCLEAMONT) == 1 && digitalRead(BOUCLEAVAL) == 0 && testTempo == 1)
      {
        delay(30);
        tempo++;
        if (tempo == 100)
        {
          testTempo = 0;
        }
      }
      delay(20);
      if (digitalRead(BOUCLEAMONT) == 0 || digitalRead(BOUCLEAVAL) == 1)
      {
        if (digitalRead(BOUCLEAMONT) == 1)
        {
          while (digitalRead(BOUCLEAMONT) == 1 || digitalRead(BOUCLEAVAL) == 1);

          nombreVoiture++;
          //Serial.print("il y a dans le parking : ");
          //Serial.print(nombreVoiture);
          //Serial.print("voiture(s)");
        }
        //Serial.print("il y a dans le parking : ");
        //Serial.print(nombreVoiture);
        //Serial.print("voiture(s)");
      }
      commandeBarriere(FERMER, 2);
    }
  }
  if (digitalRead(BOUCLEAVAL) == 1 && digitalRead(BOUCLEAMONT) == 0)
  {
    commandeBarriere(OUVRIR, 2);
    while(digitalRead(BOUCLEAVAL) == 1 && digitalRead(BOUCLEAMONT) == 0);
    if(digitalRead(BOUCLEAVAL) == 1 || digitalRead(BOUCLEAMONT) == 1)
    {
      while(digitalRead(BOUCLEAVAL) == 1 || digitalRead(BOUCLEAMONT) == 1);
       nombreVoiture--;
          //Serial.print("il y a dans le parking : ");
          //Serial.print(nombreVoiture);
          //Serial.print("voiture(s)");
        }
        //Serial.print("il y a dans le parking : ");
        //Serial.print(nombreVoiture);
        //Serial.print("voiture(s)");
      }
      commandeBarriere(FERMER, 2);
}
   
