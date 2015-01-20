// Zadanie 2
// Wycieraczka: poruszanie serwem po naciśnięciu 1 przycisku w różny sposób. Potrzebne są: 5 kabli, przycisk, serwo

#include <Servo.h>

Servo ser;			// nazywamy serwo

int button;			// zmienna do odczytu przycisku (czytaj BUT-TON)
int tryb;			// tryb działania wycieraczki
int i = 0;			// pozycja serwa

void setup(){
  pinMode(12,INPUT_PULLUP);	// wejście (przycisk) - podłączenie na dwa kable: drugi do masy
  ser.attach(13);		// serwo
  ser.write(0);			// ustawiamy pozycję
}

void loop(){  			// wywołujemy 2 funkcje:
  but();			// sprawdzanie przycisku
  tryby();			// odpalenie wycierania
}

void but(){			// sprawdzamy czy przycisk został wciśnięty
  button = digitalRead(12);
  if(button == LOW){		// jeżeli go naciśniemy
    tryb++;			// zwiększamy numer trybu
    delay(250);			// i zapobiegamy drganiu przycisku
  }
  if (tryb == 4){		// jeżeli naciśniemy 4 razy
    tryb = 0;			// wracamy do stanu wyłączonego
  }
}

void tryby(){			// tryby wycierania (pracy serwa)
  if (tryb ==1){		// 2 sekundy przerwy
    wycieracz(2000);		// wywołujemy funkcję do zmiany pozycji (wycierania)
  }
  if (tryb ==2){		// 1 sekunda przerwy
    wycieracz(1000);
  }
  if (tryb ==3){		// full auto
    wycieracz(1);
  }
}

void wycieracz(int czas){  	// funkcja zmiany położenia serwa (wprowadzamy do niej czas)
  for(i = 0; i < 180;i++){	// obrót
    ser.write(i);
    delay(2);			// czekamy na obrót serwa
    but();    			// sprawdzamy stan przycisku (to ważne)
  }
  for(i = 179; i>=0;i--){	// obrót w drugą stronę
    ser.write(i);
    delay(2);
    but();    
  }
  for(int j = 0; j<czas; j++){	// przerwa w działaniu (tryb 1 i 2)
    delay(1);			// co milisekundę sprawdza czy przycisk jest wciśnięty
    but();    
  }
}