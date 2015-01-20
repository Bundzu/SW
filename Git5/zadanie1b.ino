// Zadanie 1b
// przy pomocy terminala (ctrl + shift + M) wpisujemy tekst który pojawi się na wyświetlaczu 2x16 znaków, potrzebna biblioteka liquidcrystal

#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);    // wybieramy piny potrzebne do podłączenia wyświetlacza: pierwszy z lewej: RS, drugi: E, ostatnie cztery: od D4 do D7
String str;
String letters;

void setup(){
  lcd.begin(16, 2);                     // rozmiar wyświetlacza
  lcd.noCursor();                       // wyłączamy kursor
  Serial.begin(9600);                   // połączenie szeregowe
  Serial.println("Install Gentoo!");    // tekst powitalny
}

void loop(){
  lcd.setCursor(0, 0);                  // pozycja kursora

  if(Serial.available()) {              // odczytujemy z komputera tylko wtedy gdy coś wpisujemy
    str = Serial.readStringUntil('\n'); // odczytujemy do momentu entera
    letters=str;                        // zapisujemy do innego stringa aby trzymał nam napis
  }

  lcd.print(letters);                   // wypisujemy na wyświetlaczu
  delay(100);                           // czekamy (wyświetlacz jest dosyć wolny)
  lcd.clear();                          // czyścimy (potrzebne jak wpisaliśmy coś nowego)
}