/*
  Código para controlar um LED com um LDR usando um loop while.
  
  - O LDR mede a intensidade da luz ambiente e retorna um valor entre 0 e 1023.
  - Se o valor lido for maior que 500, o LED permanece aceso enquanto essa condição for verdadeira.
  - Assim que o valor do LDR cair abaixo de 500, o LED apaga.
  - O loop while mantém o LED ligado até que a condição mude, garantindo uma resposta contínua à variação de luz.
  - O Monitor Serial exibe os valores lidos do LDR e o estado do LED para depuração.
*/

// Definição dos pinos
const int pinoLDR = A0;  // LDR conectado ao pino analógico A0
const int pinoLED = 9;   // LED conectado ao pino 9 (pino PWM)

// Variáveis para armazenar os valores
int valorLDR = 0;    // Armazena a leitura do LDR
int brilhoLED = 0;   // Armazena o valor de PWM do LED

void setup() {
  pinMode(pinoLED, OUTPUT);  // Define o LED como saída
  Serial.begin(9600);        // Inicializa o monitor serial para depuração
}

void loop() {
  // Lê o valor do LDR (0 a 1023)
  valorLDR = analogRead(pinoLDR);

  // Mapeia o valor do LDR para a faixa de PWM (0 a 255)
  brilhoLED = map(valorLDR, 0, 1023, 0, 255); // Quanto mais escuro, mais brilho

  // Enquanto a leitura do LDR for maior que 500, mantém o LED aceso
  while (valorLDR > 500) {
    digitalWrite(pinoLED, HIGH);
    Serial.println("LED ACESO");
    
    // Atualiza a leitura do LDR dentro do while
    valorLDR = analogRead(pinoLDR);
  }

  // Saiu do while -> O LED deve apagar
  digitalWrite(pinoLED, LOW);
  Serial.println("LED APAGADO");

  // Exibe os valores no monitor serial
  Serial.print("LDR: ");
  Serial.print(valorLDR);
  Serial.print(" | PWM: ");
  Serial.println(brilhoLED);

  delay(100); // Pequeno atraso para estabilizar a leitura
}
