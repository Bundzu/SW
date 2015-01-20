// Zadanie 1
// Przy pomocy potencjometru zmieniamy częstotliwość migania LEDa

int czas;               // czas migania

void setup(){ 
pinMode(13, OUTPUT);    // wyjście na LEDa
}

void loop(){ 
czas = analogRead(0);     // odczytujemy wartości z potencjometru podłączonego do wejścia A0 i zapisujemy do zmiennej
digitalWrite(13, HIGH);   // miganie
delay(czas);
digitalWrite(13, LOW);
delay(czas);
}