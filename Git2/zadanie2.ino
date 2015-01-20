// Zadanie 2
// Przy pomocy potencjometru zmieniamy jasność świecenia diody LED
// Potrzebne: potencjometr, LED, mały opornik, kable

int pot;                  // zmienna z której odczytujemy wartości napięcia na potencjometrze
void setup(){             // funkcja setup
  pinMode(11, OUTPUT);    // możemy użyć wyłącznie pinu ze znakiem tyldy (~) ponieważ tylko one pozwalają na PWM (modulację szerokości impulsów)
}
void loop(){              // funkcja loop
pot = analogRead(0);      // odczytujemy wartości napięcia z potencjometru podłączonego do pinu analogowego numer 0 (A0) i zapisujemy do zmiennej "pot", wartości te będą osiągać od 0 do 1023
analogWrite (11, pot/4);  // teraz podajemy na pin 11 (do którego jest podłączony LED) falę kwadratową o wypełnieniu podanym przez wartość na potencjometrze.
                          // ponieważ wartość wypełnienia jest z zakresu od 0 do 255 to wartości z potencjometru dzielimy przez 4 (więc wynik z potencjometru też będzie miał wartości od 0 do 255)
}
