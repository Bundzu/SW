// Zadanie czujnik odbiciowy
// 2x czujniki odbiciowe 1x serwo
// czujniki powodują przesunięcie orczyka jak wykryją nasz palec

#include <Servo.h>              // bibliteka do serwa

Servo ser;

int lewo, prawo;                // 2 zmienne do czujników 
int i = 90;                     // zmienna trzymająca położenie serwa

void setup(){
  pinMode(8, INPUT_PULLUP);     // czujniki odbiciowe
  pinMode(9, INPUT_PULLUP);
  ser.attach(13);               // serwo
  ser.write(i);                 // pozycja początkowa
}

void loop(){
  lewo = digitalRead(8);        // odczyt palca
  prawo = digitalRead(9);
  if (lewo == 0){               // jeżeli wykryto:
    if (i < 180 && i > -1){     // w wybranych wartościach wykonujemy ruch
      ser.write(i);
      i++;
    }
  }
  i--;                          // to zabezpieczenie które nie pozwala aby wartość położenia serwa przekroczyła 180 stopni

  if (prawo == 0){
    if (i < 180 && i > -1){
      ser.write(i);
      i--;
    }
  }
  i++;                          // zabezpieczenie (tylko że na odwrót)
}