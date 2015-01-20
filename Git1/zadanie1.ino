// 1 zadanie: 
// W tym zadaniu zaświecamy i gasimy na 1 sekundę LED'a który się znajduje już na arduino (takie pomarańczowe koło pinu 13)

void setup(){			// funkcja setup
  pinMode (13, OUTPUT);		// ustawiamy 13 pin na wyjście
}

void loop(){			// funkcja loop
  digitalWrite(13, HIGH);	// zaświecamy
  delay(1000);			// czekamy 1 sekundę
  digitalWrite(13, LOW);	// gasimy
  delay(1000);			// czekamy 1 sekundę
}
