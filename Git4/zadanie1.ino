// Zadanie1:
// poruszanie serwem przy pomocy potencjometru


#include <Servo.h>      // musimy dać dodatkową bibliotekę do kontroli serwa
 
Servo ser;              // nazywamy serwo
int pot;                // w tej zmiennej będzie zapisana pozycja potencjometru
 
void setup()
{
  ser.attach(13);       // serwo na 13 wyjściu
}
 
void loop(){
  pot = analogRead(0);                  // odczyt poterncjometru z werjścia 0
  pot =  map(pot, 0, 1023, 0, 179);     // konwertujemy wartości z potencjometru do stopni
  ser.write(pot);                       // zapisujemy pozycję
}
