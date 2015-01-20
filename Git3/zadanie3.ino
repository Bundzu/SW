// Zadanie 3
// Ten sam przycisk ma działać jako włącznik i wyłącznik LEDa
// schemat podłączenia: rysunek 4

int led = LOW;            // aktualny stan LEDa (wyłączony)
int button;               // czytanie stanu przycisku

void setup(){ 
  pinMode(13, OUTPUT);    	 // wyjście na LEDa
  pinMode(12, INPUT_PULLUP);     // wejście do którego podpinamy przycisk (jest w stanie wysokim)
}

void loop(){ 
  button = digitalRead(12);    // odczytujemy wartość z przycisku

  if (button == LOW){          // jeżeli przycisk jest wciśnięty to:
    if (led == HIGH){          // jeżeli stan leda jest wysoki
      led = LOW;               // to przestaje świecić
    }
      else{
      led = HIGH;              // w przeciwnym wypadku zaczyna świecić
      }
  }
digitalWrite(13,led);          // zapisujemy stan leda
}
// LED w tym przypadku nie będzie działał tak jak potrzeba, przyczyną tego są drgania przycisku, fajnie to widać na oscyloskopie (rys. 5)