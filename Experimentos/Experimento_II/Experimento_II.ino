const int numLeds = 10;
const int primeiroPino = 2;

void setup() {
  // Configura os pinos de 2 a 11 como saída
  for (int i = 0; i < numLeds; i++) {
    pinMode(primeiroPino + i, OUTPUT);
  }
}

void loop() {
  // Acende cada LED em sequência
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(primeiroPino + i, HIGH); // Acende o LED
    delay(200); // Aguarda 200 milissegundos
    digitalWrite(primeiroPino + i, LOW);  // Apaga o LED
  }

  // Pausa antes de repetir a sequência
  delay(500);
}