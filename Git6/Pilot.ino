// Zadanie pilot
// podłączamy diodę RGB, odbiornik podczerwieni. Pilota trzymamy w ręce
// jeżeli nie będzie biblioteki to można ją ściągnąć tutaj: https://github.com/shirriff/Arduino-IRremote
// mogą powstać różne błędy, więc trzeba przytrzymywać przycisk pilota aby arduino zdążyło odczytać 2 kody.

#include <IRremote.h>      // musimy dać tą bibliotekę

IRrecv irrecv(12);         // podłączenie odbiornika IR
decode_results results;
unsigned long kod;         // to kod który wysyła pilot jak naciśniemy przycisk

int red, green, blue;      // zmienne trzymające stan LED'a

void setup()
{
  Serial.begin(9600);    // odczytujemy kod pilota w terminalu, bardzo potrzebne
  irrecv.enableIRIn();   
  pinMode (9, OUTPUT);   // LED
  pinMode (10, OUTPUT);  // LED
  pinMode (11, OUTPUT);  // LED
}

void loop() {
  if (irrecv.decode(&results)) {     
    kod = results.value, DEC;
    irrecv.resume();                        
    Serial.println(results.value);          // w terminalu będą drukowane 2 wartości, nas obchodzi tylko ta pierwsza (to zależy od użytego pilota)
  }
  redf();                                   // każdy przycisk jest przypisany osobnej funkcji
  greenf();
  bluef();
  killall();
}

void redf(){
  if(kod == 50167935){          // inna wartość dla innego przycisku
    if (red == 1){
      red = 0;
    }
    else{
      red = 1;
    }
  }
  digitalWrite(9, red);
}

void greenf(){
  if(kod == 50151615){          // inna wartość dla innego przycisku
    if (green == 1){
      green = 0;
    }
    else{
      green = 1;
    }    
  }
  digitalWrite(10, green);
}

void bluef(){
  if(kod == 50184255 ){          // inna wartość dla innego przycisku
    if (blue == 1){
      blue = 0;
    }
    else{
      blue = 1;
    }    
  }
  digitalWrite(11, blue);
}

void killall(){                 // wyłączenie świecenia
  if(kod == 50153655){          // inna wartość dla innego przycisku
    blue = 0, red = 0, green = 0;
  }
}