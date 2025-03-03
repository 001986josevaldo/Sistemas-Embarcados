/*
  Código para tocar uma música usando um buzzer passivo no Arduino.

  - O buzzer é conectado a um pino PWM e emite sons de diferentes frequências.
  - A melodia é armazenada em arrays de notas e durações.
  - A função tone() gera os sons e noTone() interrompe antes da próxima nota.
  - O loop toca a música e a repete após um intervalo.
*/

// Definição do pino do buzzer
const int pinoBuzzer = 9;

// Definição das notas musicais (frequências em Hz)

#define NOTE_E4  330
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_G5  784
#define NOTE_A5  880

// Refrão da música (notas e durações)
int melodia[] = { NOTE_E5, NOTE_E5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_B4, 
                  NOTE_E5, NOTE_E5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_A4, NOTE_B4 };

int duracoes[] = { 150, 150, 300, 150, 150, 300, 150, 300,
                   150, 150, 300, 150, 150, 300, 150, 300 };

void setup() {
  pinMode(pinoBuzzer, OUTPUT);
}

void loop() {
  for (int i = 0; i < 24; i++) {
    tone(pinoBuzzer, melodia[i]); // Toca a nota
    delay(duracoes[i]);           // Mantém a duração
    noTone(pinoBuzzer);           // Para o som antes da próxima nota
    delay(50);                    // Pequena pausa entre as notas
  }

  delay(2000); // Pausa antes de repetir a música
}
