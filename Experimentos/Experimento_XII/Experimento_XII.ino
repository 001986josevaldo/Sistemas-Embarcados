/*
  Código para medir temperatura com um NTC e exibi-la em um display de 7 segmentos (cátodo comum).

  - O NTC forma um divisor de tensão com um resistor de 10kΩ para leitura analógica.
  - A temperatura é convertida e mapeada de 0 a 9 para exibição no display.
  - O display de 7 segmentos é acionado via pinos digitais.
*/

const int pinoNTC = A0; // Pino analógico do sensor NTC
const float resistorRef = 10000.0; // Resistor de 10kΩ usado no divisor
const float beta = 3950.0; // Coeficiente beta do NTC
const float tempRef = 298.15; // Temperatura de referência (25°C em Kelvin)
const float resistenciaNTC25 = 10000.0; // Resistor do NTC a 25°C

// Pinos do display de 7 segmentos (cátodo comum)
const int segmentos[7] = {2, 3, 4, 5, 6, 7, 8};

// Mapas dos números (0-9) para os segmentos
const byte digitos[10] = {
  B0111111, // 0
  B0000110, // 1
  B1011011, // 2
  B1001111, // 3
  B1100110, // 4
  B1101101, // 5
  B1111101, // 6
  B0000111, // 7
  B1111111, // 8
  B1101111  // 9
};

// Função para exibir um número no display de 7 segmentos
void exibirNumero(int numero) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentos[i], (digitos[numero] >> i) & 1);
  }
}

void setup() {
  // Configura pinos do display como saída
  for (int i = 0; i < 7; i++) {
    pinMode(segmentos[i], OUTPUT);
  }
  
  Serial.begin(9600);
}

void loop() {
  // Lê a tensão no divisor de tensão do NTC
  int leitura = analogRead(pinoNTC);
  float tensao = (leitura / 1023.0) * 5.0;
  
  // Calcula a resistência do NTC
  float resistenciaNTC = (tensao * resistorRef) / (5.0 - tensao);
  
  // Calcula a temperatura usando a equação de Steinhart-Hart
  float temperaturaK = 1.0 / ((1.0 / tempRef) + (1.0 / beta) * log(resistenciaNTC / resistenciaNTC25));
  float temperaturaC = temperaturaK - 273.15; // Converte para Celsius
  
  // Mapeia a temperatura de 0 a 90°C para o intervalo 0-9 do display
  int valorDisplay = map(temperaturaC, 0, 90, 0, 9);
  
  // Garante que o valor fique dentro da faixa 0-9
  valorDisplay = constrain(valorDisplay, 0, 9);

  // Exibe o número correspondente à temperatura no display
  exibirNumero(valorDisplay);

  // Exibe a temperatura no Monitor Serial
  Serial.print("Temperatura: ");
  Serial.print(temperaturaC);
  Serial.print(" °C  ");
  Serial.print("| Tensao: ");
  Serial.println(tensao);

  delay(1000); // Atualiza a cada 1 segundo
}
