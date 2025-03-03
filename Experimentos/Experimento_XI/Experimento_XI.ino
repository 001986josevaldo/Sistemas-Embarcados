/* Este código utiliza um sensor ultrassônico HC-SR04 
para medir distâncias em centímetros e exibir os valores 
no monitor serial.*/

#define TRIG_PIN 9
#define ECHO_PIN 10

void setup() {
    Serial.begin(9600); // Inicializa a comunicação serial
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void loop() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);
    float distance = (duration * 0.0343) / 2; // Converte para centímetros
    
    Serial.print("Distancia: ");
    Serial.print(distance);
    Serial.println(" cm");
    
    delay(500); // Pequeno atraso para evitar leituras instáveis
}
