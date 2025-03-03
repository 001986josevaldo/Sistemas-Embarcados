/*
Este código controla uma sequência de 10 LEDs conectados ao Arduino, 
acendendo-os um por um em ordem crescente. 
Cada LED permanece aceso por 200 milissegundos antes de apagar, 
criando um efeito de movimento. Após completar a sequência, há uma pausa de 500 milissegundos antes de reiniciar o ciclo.
*/
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