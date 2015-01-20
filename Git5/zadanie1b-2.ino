// Zadanie 1b-2
// przy pomocy terminala (ctrl + shift + M) wpisujemy tekst który pojawi się na wyświetlaczu 2x16 znaków, potrzebna biblioteka liquidcrystal
// + sterujemy podświetleniem przy pomocy znaków + i -

#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

String str;
String letters;

void setup() {
  pinMode (8, OUTPUT);
  lcd.begin(16, 2);
  lcd.noCursor();
  Serial.begin(9600);
  Serial.println("Wpisz tekst:");
  digitalWrite(8, HIGH);				// podpinamy do tego pinu podświetlenie (pin 15 na wyświetlaczu)
}

void loop() {
  lcd.setCursor(0, 0);
  literki();
  lcd.print(letters);
  delay(50); 
  lcd.clear();
}

void literki() {
  if (Serial.available()) {
    str = Serial.readStringUntil('\n');
    if (str == "+" || str == "-") {			// jeżeli wpiszemy + lub -
      raito();						// odpalamy funkcję "raito"
    }
    else {
      letters = str;
      Serial.println(letters);
    }
  }
}

void raito() {						// funkcja sterująca podświetleniem
  if (str == "-") {
    digitalWrite(8, LOW);
  }
  if (str == "+") {
    digitalWrite(8, HIGH);
  }
}