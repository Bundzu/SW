// Zadanie 1b-3
// przy pomocy terminala (ctrl + shift + M) wpisujemy tekst który pojawi się na wyświetlaczu 2x16 znaków, potrzebna biblioteka liquidcrystal
// + sterujemy jasnością podświetlenia przy pomocy znaków + i -

#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

String str;
String letters;
int light = 255;

void setup() {
  pinMode (9, OUTPUT);
  lcd.begin(16, 2);
  lcd.noCursor();
  Serial.begin(9600);
  Serial.println("Wpisz tekst:");
  digitalWrite(9, HIGH);		// podpinamy do tego pinu podświetlenie (pin 15 na wyświetlaczu), pin musi być z tyldą (analogWrite)
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
    if (str == "+" || str == "-") {	// jeżeli wpiszemy - lub +
      raito();				// odpalamy funkcję "raito"
    }
    else {
      letters = str;
      Serial.println(letters);
    }
  }
}

void raito() {				// funkcja sterująca podświetleniem
  if (str == "-") {
   light -= 255/4; 			// zmniejszamy jasność o ¼
  }
  if (str == "+") {
    light += 255/4; 
  }
  analogWrite(9, light);		
}