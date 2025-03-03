/*  Este código controla um LED RGB para exibir mais de 256 cores diferentes,
 * usando PWM para controlar a intensidade de cada componente de cor.
 * Versão sem comunicação Serial para maior eficiência.*/

// Definição dos pinos PWM para cada cor
const int pinoVermelho = 4;  // Pino para componente vermelho (deve ser PWM)
const int pinoVerde = 6;    // Pino para componente verde (deve ser PWM)
const int pinoAzul = 8;     // Pino para componente azul (deve ser PWM)

// Tipo de LED RGB
const bool ANODO_COMUM = false;  // true para ânodo comum, false para cátodo comum

void setup() {
  // Configura os pinos como saída
  pinMode(pinoVermelho, OUTPUT);
  pinMode(pinoVerde, OUTPUT);
  pinMode(pinoAzul, OUTPUT);
  
  // Inicialmente, desligue o LED
  setColor(0, 0, 0);
}

void loop() {
  // 1. Demonstração de cores básicas
  
  // Vermelho
  setColor(255, 0, 0);
  delay(1000);
  
  // Verde
  setColor(0, 255, 0);
  delay(1000);
  
  // Azul
  setColor(0, 0, 255);
  delay(1000);
  
  // Amarelo (Vermelho + Verde)
  setColor(255, 255, 0);
  delay(1000);
  
  // Magenta (Vermelho + Azul)
  setColor(255, 0, 255);
  delay(1000);
  
  // Ciano (Verde + Azul)
  setColor(0, 255, 255);
  delay(1000);
  
  // Branco (Todas as cores)
  setColor(255, 255, 255);
  delay(1000);
  
  // 2. Transição suave entre cores (demonstração de várias cores)
  
  // Ciclo de arco-íris - transição suave entre centenas de cores
  for (int i = 0; i < 768; i++) {
    // Este algoritmo gera um efeito arco-íris suave
    if (i <= 255) {
      setColor(255 - i, i, 0);  // Vermelho para Verde
    } else if (i <= 511) {
      setColor(0, 511 - i, i - 256);  // Verde para Azul
    } else {
      setColor(i - 512, 0, 768 - i);  // Azul para Vermelho
    }
    delay(10);  // Ajuste para velocidade da transição
  }
  
  // 3. Demonstração de 216 cores web-safe (6 níveis de R, G e B)
  
  // Níveis: 0, 51, 102, 153, 204, 255
  for (int r = 0; r <= 255; r += 51) {
    for (int g = 0; g <= 255; g += 51) {
      for (int b = 0; b <= 255; b += 51) {
        setColor(r, g, b);
        delay(100);  // Breve pausa para visualizar cada cor
      }
    }
  }
  
  // Apaga o LED antes de reiniciar
  setColor(0, 0, 0);
  delay(1000);
}

// Função para definir a cor do LED RGB
void setColor(int vermelho, int verde, int azul) {
  // Para LED de ânodo comum, inverte os valores
  if (ANODO_COMUM) {
    vermelho = 255 - vermelho;
    verde = 255 - verde;
    azul = 255 - azul;
  }
  
  // Aplica os valores aos pinos
  analogWrite(pinoVermelho, vermelho);
  analogWrite(pinoVerde, verde);
  analogWrite(pinoAzul, azul);
}
