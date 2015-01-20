// 3 zadanie
// Znowu miganie, najpierw przyspiesza a potem zwalnia, zamiast wewnętrzego LED'a można sobie jakiegoś podłączyć

int czas = 1000;    

void setup(){
  pinMode(13, OUTPUT);      // 13 pin jest wyjściem
}

void loop(){
  for(czas; czas > 0; czas = czas - 100) {    // używamy zmiennej "czas", nic nie musimy ustawiać bo zrobi to za nas 2 pętla
   digitalWrite(13, HIGH);                           // świecenie itd.
   delay(czas);
   digitalWrite(13, LOW);
   delay(czas);
   }
   if(czas == 0){                                // warto pamiętać o dwóch znakach równa się == !
     for(czas; czas < 1000; czas = czas + 100){  // tym razem świecimy coraz wolniej
       digitalWrite(13, HIGH);                           
       delay(czas);
       digitalWrite(13, LOW);
       delay(czas);
     }
   }
  
}
