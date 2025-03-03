/* Este código controla uma sequência de LEDs usando um potenciômetro para ajustar a velocidade do efeito.
 O potenciômetro define o tempo de delay entre os LEDs, variando de um mínimo a um máximo configurável.
 Cada LED acende em sequência e apaga antes de passar para o próximo.*/


const int numLeds = 10;
const int primeiroPino = 2;
const int potPin = A0;    // Potenciômetro conectado ao pino analógico A0

// Variáveis para controle
int potValue = 0;         // Valor lido do potenciômetro (0-1023)
int delayTime = 0;        // Tempo de delay calculado (em milissegundos)
int minDelay = 50;        // Delay mínimo (LED mais rápido)
int maxDelay = 1000;      // Delay máximo (LED mais lento)

void setup() {
  // Configura os pinos de 2 a 11 como saída
  for (int i = 0; i < numLeds; i++) {
    pinMode(primeiroPino + i, OUTPUT);
  }
  pinMode(potPin, INPUT);         // Define o pino do potenciômetro como entrada


}

void loop() {
    // Lê o valor do potenciômetro (0-1023)
    potValue = analogRead(potPin);
      // Mapeia o valor do potenciômetro para o intervalo de delay desejado
  // map(valor, fromLow, fromHigh, toLow, toHigh)
    delayTime = map(potValue, 0, 1023, minDelay, maxDelay);

  // Acende cada LED em sequência
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(primeiroPino + i, HIGH); // Acende o LED
    delay(delayTime); // Aguarda 200 milissegundos
    digitalWrite(primeiroPino + i, LOW);  // Apaga o LED
  }
}
