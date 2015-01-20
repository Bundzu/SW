// Zadanie 2a
// Dioda będzie świeciła tak długo jak naciskamy przycisk (button)
// Podłączenie takie jak na stronie arduino.cc (trzy kable) patrz rysunek 3
// ta metoda ma taką zaletę że po prostu odczytujemy wartości z BUTTONa i nie bawimy się w ustawianie stanów na wejściu (bo domyślnie są na LOW)

int button;             // czytaj "BUT-TON"

void setup(){ 
pinMode(13, OUTPUT);    // wyjście na LEDa
pinMode(12, INPUT);     // wejście do którego podpinamy przycisk
Serial.begin(9600);     // bardzo przydatna opcja, możemy dzięki niej sprawdzać czy nasz BUTTON dobrze działa (sprawdzanie stanów i wartości), aby odczytać te wartości trzeba wejść w narzędzia → serial monitor
                        // można to oczywiście pominąć
}

void loop(){ 
button = digitalRead(12);  // odczytujemy wartość z przycisku
if (button == HIGH){       // jeżeli przycisk jest wciśnięty
  digitalWrite(13, HIGH);  // to zaświecamy LED'a
}
else {                     // w przeciwnym wypadku
  digitalWrite(13, LOW);   // LED będzie wyłączony
}
Serial.println(button);    // odczyt wartości ze zmiennej BUTTON, w terminalu będą widzone wartości 0 lub 1, można pominąć tą linię
}