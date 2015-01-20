// 2 zadanie
// Teraz LED będzie migał coraz szybciej

int czas = 1000;    // tutaj można deklarować zmienne, w tym przypadku to jest zbędne bo można ją zadeklarować w pętli for

void setup(){
  pinMode(13, OUTPUT);      // 13 pin jest wyjściem
}

void loop(){
  for(czas = 1000; czas > 0; czas = czas - 100) {    // funcja for ustawia zmienną czas na 1 sek. a następnie odejmuje czas o 100 ms
   digitalWrite(13, HIGH);                           // świecenie itd.
   delay(czas);
   digitalWrite(13, LOW);
   delay(czas);
   }
  
}
