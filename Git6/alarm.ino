// Zadanie czujnik ruchu i fotorezystor (alarm)
// 1x czujnik ruchu 1x fotorezystor 2x LED 4x rezystor 1x brzęczyk
// jeżeli fotorezystor wykryje noc to włącza czujnik ruchu i czerwonego leda, jak wykryje ruch to brzęczyk piszczy. Aby wyłączyć czujnik należy wpisać w terminalu super tajne hasło i wtedy zapali się ponownie druga dioda
// jeszcze nie robiłem tego ćwiczenia więc nie wiem jak to dokładnie ma się zachowywać
// na czujniku ruchu (HC-SR501) należy przekręcić potencjometry maksymalnie w prawo (jeżeli soczewka jest skierowana w górę)
// http://arduinobasics.blogspot.com/search/label/HC-SR501

#include <pitches.h>   // biblioteka do brzęczyka, może się różnie nazywać

int state, ruch, foto, alarm;
String str;

void setup(){
  Serial.begin(9600);    // terminal
  pinMode(12, INPUT);    // czujnik ruchu
  pinMode(7, OUTPUT);   // brzęczyk
  pinMode(8, OUTPUT);    // zielony LED
  pinMode(9, OUTPUT);    // czerwony LED
}
void loop(){
  ruch= digitalRead(12);   // stan czujnika ruchu
  foto = analogRead(0);    // stan fotorezystora
  fotorezystor();          // funkcja stanu fotorezystora
  pass();                  // funkcja odczytu hasła
  ahtung();                // funkcja alarmu
}

void fotorezystor() {	   // wykrywanie nocy
  if (state == 0) {        // świecenie ledami
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    noTone(7);		   // wyłączenie dźwięku, bardzo ważne
  }
  if (state == 1) {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
  }
  
  if (foto < 20) {         // im mniejsza wartość tym ciemniej, 
    state= 1;              // włączenie czujnika ruchu
  }
}

void pass(){
  str = Serial.readStringUntil('\n');      // odczyt poleceń
  if (str == "install Gentoo"){            // jeżeli wpiszemy hasło
    state = 0;                             // wyłączamy czujnik ruchu
    alarm = 0;
    Serial.println("wylaczono czujnik ruchu");    
  }

  if (str != "install Gentoo" && str != 0){
    Serial.println("command not found");
    str = 0;
  }
}

void ahtung(){
  if (state == 1 && ruch == 1){
    alarm = 1;
    Serial.println("wykryto ruch!");
  }
  
  if (alarm == 1){
    tone (7, 1000);                        // dźwięk alarmu
    Serial.println("alarm!");
  }
}
