// Zadanie 1a-2
// Sensor odczytuje odległość i sygnalizuje ją przy pomocy brzęczyka i 2 LEDów, wersja bez przycisku
// Potrzebne: czujnik ultradźwiękowy, 2xdioda, 1 brzęczyk
// ten czujnik ma tylko 1 wyjście/wejście http://www.seeedstudio.com/wiki/Ultra_Sonic_range_measurement_module nie poletzam tego modelu, tańszy i popularniejszy jest model HC-SR04 (2 osobne piny)


void setup() {
  pinMode (10, OUTPUT);        // zielony LED
  pinMode (11, OUTPUT);        // czerwony LED
}

void loop() {
  long duration, cm;           // tworzymy 2 zmienne przy pomocy 1 linii
  pinMode(13, OUTPUT);         // 13 pin jest używany przez sensor ultradźwiękowy
  digitalWrite(13, LOW);
  delayMicroseconds(2);
  digitalWrite(13, HIGH);
  delayMicroseconds(5);
  digitalWrite(13, LOW);

  pinMode(13, INPUT);
  duration = pulseIn(13, HIGH);
  cm = microsecondsToCentimeters(duration);
  delay(100);

  if (cm > 20) {              // jeżeli jest więcej niż 20 cm
    digitalWrite(10, HIGH);   // włączamy zielonego LEDa
    digitalWrite(11, LOW);
  }
  if (cm <= 20 && cm > 10) {  // między 10-20 cm
    digitalWrite(11, LOW);    
    digitalWrite(10, HIGH);   // migamy zielonym LEDem
    delay(100);
    digitalWrite(10, LOW);
    delay(100);
    tone(12,  200, 10);       // puszczamy sygnał dźwiękowy
  }
  if (cm < 10) {              // poniżej 10 cm:
    digitalWrite(11, HIGH);   // zaświecamy czerwonego LEDa
    digitalWrite(10, LOW);
    tone(12,  1000, 10);      // sygnał dźwiękowy
  }
}


long microsecondsToCentimeters(long microseconds) {    // przelicznik potrzebny do działania czujnika
  return microseconds / 29 / 2;
}
