/* Este código controla um servo motor, 
movimentando-o por uma sequência de 
ângulos predefinidos de forma repetitiva.*/

#include <Servo.h>

Servo meuServo; // Cria um objeto Servo
int angulos[] = {0, 15, 30, 45, 60, 75, 90, 105, 120, 135, 150, 165, 180, 0};
int tamanho = sizeof(angulos) / sizeof(angulos[0]);

void setup() {
    meuServo.attach(9); // Define o pino 9 como saída para o servo
}

void loop() {
    for (int i = 0; i < tamanho; i++) {
        meuServo.write(angulos[i]); // Define o ângulo do servo
        delay(500); // Aguarda meio segundo para movimentação
    }
}
