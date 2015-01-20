int led = LOW;          
int button;            

void setup(){ 
  pinMode(13, OUTPUT);    	 
  pinMode(12, INPUT_PULLUP);
}

void loop(){ 
  button = digitalRead(12);    // odczytujemy wartość z przycisku

  if (button == LOW){  
    delay(250);                // jedyna zmiana w programie: ignorujemy przycisk przez ćwierć sekundy (w zależności od przycisku wartości te wachają się od 180 do 300 ms)
    if (led == HIGH){   
      led = LOW;         
    }
      else{
      led = HIGH;         
      }
  }
digitalWrite(13,led);      
}
