// Este código simula o funcionamento de um semáforo de dois tempos, com dois conjuntos de LEDs (vermelho, amarelo e verde) representando dois semáforos opostos. 
// O semáforo 1 tem as fases: verde (5 segundos), amarelo (2 segundos), e vermelho. O semáforo 2 possui fases: verde (5 segundos), amarelo (2 segundos) e vermelho.
// Durante cada fase, os LEDs são acesos e apagados de acordo com o tempo de duração especificado, controlando a alternância entre as luzes dos semáforos.
// Definição dos pinos dos LEDs do primeiro semáforo (Principal)
const int vermelho1 = 4;
const int amarelo1 = 3;
const int verde1 = 2;

// Definição dos pinos dos LEDs do segundo semáforo (Oposto)
const int vermelho2 = 7;
const int amarelo2 = 6;
const int verde2 = 5;

void setup() {
  // Configuração dos pinos como saída
  pinMode(vermelho1, OUTPUT);
  pinMode(amarelo1, OUTPUT);
  pinMode(verde1, OUTPUT);

  pinMode(vermelho2, OUTPUT);
  pinMode(amarelo2, OUTPUT);
  pinMode(verde2, OUTPUT);
}

void loop() {
  // Fase 1: Semáforo 1 verde, Semáforo 2 vermelho
  digitalWrite(verde1, HIGH);
  digitalWrite(amarelo1, LOW);
  digitalWrite(vermelho1, LOW);
  
  digitalWrite(verde2, LOW);
  digitalWrite(amarelo2, LOW);
  digitalWrite(vermelho2, HIGH);
  
  delay(5000); // Mantém essa fase por 5 segundos

  // Fase 2: Semáforo 1 amarelo, Semáforo 2 ainda vermelho
  digitalWrite(verde1, LOW);
  digitalWrite(amarelo1, HIGH);
  delay(2000); // Mantém o amarelo por 2 segundos

  // Fase 3: Semáforo 1 vermelho, Semáforo 2 verde
  digitalWrite(amarelo1, LOW);
  digitalWrite(vermelho1, HIGH);
  
  digitalWrite(verde2, HIGH);
  digitalWrite(amarelo2, LOW);
  digitalWrite(vermelho2, LOW);
  
  delay(5000); // Mantém essa fase por 5 segundos

  // Fase 4: Semáforo 1 ainda vermelho, Semáforo 2 amarelo
  digitalWrite(verde2, LOW);
  digitalWrite(amarelo2, HIGH);
  delay(2000); // Mantém o amarelo por 2 segundos
}
