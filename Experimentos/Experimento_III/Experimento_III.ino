/*Este código define uma classe chamada 
LedController para controlar um conjunto de LEDs 
conectados ao Arduino. A classe implementa diferentes 
efeitos de iluminação, como deslocamento sequencial, 
movimentação de extremos para o centro e o 
famoso efeito "Super Máquina" (Knight Rider). 
No loop principal, os efeitos são executados em sequência, 
criando padrões de iluminação dinâmicos e interativos.*/
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
  
    // Efeito: Vai volta
    void vaiVolta() {
      for (int i = 0; i < numLeds; i++) {            // Ida
        digitalWrite(primeiroPino + i, HIGH);         // Acende o LED
        delay(delayTime);
        digitalWrite(primeiroPino + i, LOW);          // Apaga o LED
      }
  
      for (int i = numLeds - 1; i >= 0; i--) {       // Volta
        digitalWrite(primeiroPino + i, HIGH);         // Acende o LED
        delay(delayTime);
        digitalWrite(primeiroPino + i, LOW);          // Apaga o LED
      }
    }
  
    // Efeito: Vai fica aceso
    void vaiFicaAceso() {
      for (int i = 0; i < numLeds; i++) {            // Ida
        digitalWrite(primeiroPino + i, HIGH);         // Acende o LED
        delay(delayTime);
      }
      apagarTodosLeds(); // Apaga todos os LEDs ao final
    }
  
    // Efeito: Vai fica aceso, volta apagando
    void vaiFicaAcesoVoltaApagando() {
      for (int i = 0; i < numLeds; i++) {            // Ida
        digitalWrite(primeiroPino + i, HIGH);         // Acende o LED
        delay(delayTime);
      }
  
      for (int i = numLeds - 1; i >= 0; i--) {       // Volta
        digitalWrite(primeiroPino + i, LOW);          // Apaga o LED
        delay(delayTime);
      }
    }
  
    // Efeito: Vai dos extremos para o meio
    void extremosParaMeio() {
      for (int i = 0; i < numLeds / 2; i++) {
        digitalWrite(primeiroPino + i, HIGH);         // Acende o LED da esquerda
        digitalWrite(primeiroPino + (numLeds - 1 - i), HIGH); // Acende o LED da direita
        delay(delayTime);
        digitalWrite(primeiroPino + i, LOW);          // Apaga o LED da esquerda
        digitalWrite(primeiroPino + (numLeds - 1 - i), LOW);  // Apaga o LED da direita
      }
    }
  
    // Efeito: Vai dos extremos para o meio e volta para os extremos
    void extremosParaMeioVolta() {
      for (int i = 0; i < numLeds / 2; i++) {        // Ida: extremos para o meio
        digitalWrite(primeiroPino + i, HIGH);         // Acende o LED da esquerda
        digitalWrite(primeiroPino + (numLeds - 1 - i), HIGH); // Acende o LED da direita
        delay(delayTime);
      }
  
      for (int i = numLeds / 2 - 1; i >= 0; i--) {   // Volta: meio para os extremos
        digitalWrite(primeiroPino + i, LOW);          // Apaga o LED da esquerda
        digitalWrite(primeiroPino + (numLeds - 1 - i), LOW);  // Apaga o LED da direita
        delay(delayTime);
      }
    }
  
    // Efeito: Vai par volta ímpar
    void vaiVoltaImpar() {
      for (int i = 0; i < numLeds; i += 2) {         // Ida: LEDs ímpares
        digitalWrite(primeiroPino + i, HIGH);         // Acende o LED
        delay(delayTime);
        digitalWrite(primeiroPino + i, LOW);          // Apaga o LED
      }
  
      for (int i = numLeds - 1; i >= 0; i -= 2) {    // Volta: LEDs ímpares
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
    // Método para apagar todos os LEDs
  void apagarTodosLeds() {
      for (int i = 0; i < numLeds; i++) {
        digitalWrite(primeiroPino + i, LOW); // Apaga o LED
        }
  }
  };
  
  // Cria um objeto da classe LedController
  LedController leds(10, 2, 300); // 10 LEDs, começando no pino 2, com delay de 100ms
  
  void setup() {
    // Nada a fazer aqui, a configuração é feita no construtor da classe
  }
  
  void loop() {
      leds.vaiVolta();                  // 3.1. Vai volta
      delay(500);
    
      leds.vaiFicaAceso();              // 3.2. Vai fica aceso
      delay(500);
    
      leds.vaiFicaAcesoVoltaApagando(); // 3.3. Vai fica aceso, volta apagando
      delay(500);
    
      leds.extremosParaMeio();          // 3.4. Vai dos extremos para o meio
      delay(500);
    
      leds.extremosParaMeioVolta();     // 3.5. Vai dos extremos para o meio e volta
      delay(500);
    
      leds.vaiVoltaImpar();             // 3.6. Vai par volta ímpar
      delay(500);
    
      leds.efeitoSuperMaquina();        // 3.7. Efeito Super Máquina
      delay(500);
    }