class LedController {
    private:
      int numLeds;          // Número de LEDs
      int primeiroPino;     // Primeiro pino onde os LEDs estão conectados
      int delayTime;        // Tempo de delay entre as transições
    
    public:
      // Construtor
      LedController(int num, int primeiro, int delay) {
        numLeds = num;
        primeiroPino = primeiro;
        delayTime = delay;
    
        // Configura os pinos como saída
        for (int i = 0; i < numLeds; i++) {
          pinMode(primeiroPino + i, OUTPUT);
        }
      }
    
      // Efeito: Dos extremos para o meio e volta para os extremos
      void extremosParaMeio() {
        for (int i = 0; i < numLeds / 2; i++) {
          digitalWrite(primeiroPino + i, HIGH);         // Acende o LED da esquerda
          digitalWrite(primeiroPino + (numLeds - 1 - i), HIGH); // Acende o LED da direita
          delay(delayTime);
          digitalWrite(primeiroPino + i, LOW);          // Apaga o LED da esquerda
          digitalWrite(primeiroPino + (numLeds - 1 - i), LOW);  // Apaga o LED da direita
        }
    
        for (int i = numLeds / 2 - 1; i >= 0; i--) {
          digitalWrite(primeiroPino + i, HIGH);         // Acende o LED da esquerda
          digitalWrite(primeiroPino + (numLeds - 1 - i), HIGH); // Acende o LED da direita
          delay(delayTime);
          digitalWrite(primeiroPino + i, LOW);          // Apaga o LED da esquerda
          digitalWrite(primeiroPino + (numLeds - 1 - i), LOW);  // Apaga o LED da direita
        }
      }
    
      // Efeito: Vai e volta ímpar
      void vaiVoltaImpar() {
        for (int i = 0; i < numLeds; i += 2) {         // Percorre os índices ímpares
          digitalWrite(primeiroPino + i, HIGH);         // Acende o LED
          delay(delayTime);
          digitalWrite(primeiroPino + i, LOW);          // Apaga o LED
        }
    
        for (int i = numLeds - 1; i >= 0; i -= 2) {    // Percorre os índices ímpares de volta
          digitalWrite(primeiroPino + i, HIGH);         // Acende o LED
          delay(delayTime);
          digitalWrite(primeiroPino + i, LOW);          // Apaga o LED
        }
      }
    
      // Efeito: Super Máquina (Knight Rider)
      void efeitoSuperMaquina() {
        for (int i = 0; i < numLeds; i++) {            // Ida
          digitalWrite(primeiroPino + i, HIGH);         // Acende o LED
          delay(delayTime);
          digitalWrite(primeiroPino + i, LOW);          // Apaga o LED
        }
    
        for (int i = numLeds - 2; i > 0; i--) {        // Volta (ignora o último LED)
          digitalWrite(primeiroPino + i, HIGH);         // Acende o LED
          delay(delayTime);
          digitalWrite(primeiroPino + i, LOW);          // Apaga o LED
        }
      }
    };
    
    // Cria um objeto da classe LedController
    LedController leds(10, 2, 300); // 10 LEDs, começando no pino 2, com delay de 100ms
    
    void setup() {
      // Nada a fazer aqui, a configuração é feita no construtor da classe
    }
    
    void loop() {
      // Executa os efeitos em sequência
      leds.extremosParaMeio();  // Efeito dos extremos para o meio
      delay(500);               // Pausa entre os efeitos
    
      leds.vaiVoltaImpar();     // Efeito vai e volta ímpar
      delay(500);               // Pausa entre os efeitos
    
      leds.efeitoSuperMaquina(); // Efeito Super Máquina
      delay(500);               // Pausa entre os efeitos
    }