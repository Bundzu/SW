// Zadanie 2b
// Dioda będzie świeciła tak długo jak naciskamy przycisk (button)
// Inne podłączenie: po naciśnięciu przycisku będzie wartość LOW, patrz rysunek 4

int button;             // czytaj "BUT-TON"

void setup(){ 
pinMode(13, OUTPUT);    // wyjście na LEDa
pinMode(12, INPUT);     // wejście do którego podpinamy przycisk
digitalWrite(12,HIGH);  // Ustawiamy stan wysoki na wejściu, po naciśnięciu będzie stan niski
			// zamiast tych dwóch powyższych linii można poprostu dać "pinMode(12, INPUT_PULLUP);"
}

void loop(){ 

button = digitalRead(12);  // odczytujemy wartość z przycisku

if (button == LOW){        // jeżeli przycisk będzie wciśnięty (stan niski)
  digitalWrite(13, HIGH);  // świecimy LEDem
}
else {                     // w przeciwnym wypadku
  digitalWrite(13, LOW);   // nic się niedzieje
}
}