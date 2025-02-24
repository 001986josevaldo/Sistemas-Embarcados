const int pinoLed = 12; // Pino do LED
const int ledStatus = 13; // LED de status
int tempoDelay = 500; // Tempo inicial de atraso (em ms)

unsigned long tempoAnteriorLed = 0;
unsigned long tempoAnteriorLedStatus = 0;
const int intervaloLedStatus = 500;

void setup() {
    pinMode(pinoLed, OUTPUT); // Define o pino como saída
    pinMode(ledStatus, OUTPUT); // Define o LED de status como saída
}

void loop() {
    unsigned long tempoAtual = millis();
    
    // Controle do LED principal
    if (tempoAtual - tempoAnteriorLed >= tempoDelay) {
        tempoAnteriorLed = tempoAtual;
        digitalWrite(pinoLed, !digitalRead(pinoLed));
    }
    
    // Controle do LED de status de forma independente
    if (tempoAtual - tempoAnteriorLedStatus >= intervaloLedStatus) {
        tempoAnteriorLedStatus = tempoAtual;
        digitalWrite(ledStatus, !digitalRead(ledStatus));
    }
    
    // Altera a frequência (exemplo: diminui o tempo de delay gradualmente e depois reinicia)
    static unsigned long ultimaAtualizacao = 0;
    if (tempoAtual - ultimaAtualizacao >= 2000) { // Atualiza a frequência a cada 2 segundos
        ultimaAtualizacao = tempoAtual;
        tempoDelay -= 50; // Reduz a velocidade progressivamente
        if (tempoDelay < 100) {
            tempoDelay = 500; // Reseta para o valor inicial
        }
    }
}