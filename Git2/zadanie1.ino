// Zadanie 1
// Rozjaśnianie i ściemnianie LEDa jak w lampkach choinkowych

int x = 0;                  // zmienna potrzebna do PWM'a (modulacji szerokości impulsu)

void setup(){
  pinMode(11, OUTPUT);      // używamy tylko wyjść z tyldą (~) ponieważ tylko one mają PWM (pin 3, 5, 6, 9, 10, 11)
}

void loop(){
  for(x; x < 255; x++) {    // w tej pętli rozjaśniamy LEDa (maksymalna wartość to 255)
  analogWrite (11,x);       // wartość zmiennej jest wartością wypełnienia 
  delay (40);               // opóźniamy proces aby coś widzieć
   }
   if(x == 255){            // jeżeli mamy maksymalną wartość to przyciemniamy                      
     for(x; x > 0; x--){ 
      analogWrite (11,x);
      delay (40);
     }
   }
  
}
