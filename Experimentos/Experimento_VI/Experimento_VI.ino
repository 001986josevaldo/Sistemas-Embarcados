/* Este código controla um display de 7 segmentos, exibindo uma sequência de caracteres.
 Os pinos do Arduino são configurados para acionar cada segmento do display.
 A matriz de caracteres define quais segmentos devem ser ativados para cada símbolo.*/

// Definição dos pinos do Arduino conectados aos segmentos do display de 7 segmentos
const int a = 2;
const int b = 3;
const int c = 4;
const int d = 5;
const int e = 6;
const int f = 7;
const int g = 8;

// Matriz para os caracteres desejados
const byte caracteres[][7] = {
  // a  b  c  d  e  f  g
  { 0, 1, 1, 0, 0, 0, 0 }, // 1
  { 1, 1, 0, 1, 1, 0, 1 }, // 2
  { 1, 1, 1, 1, 0, 0, 1 }, // 3
  { 0, 1, 1, 0, 0, 1, 1 }, // 4
  { 1, 0, 1, 1, 0, 1, 1 }, // 5
  { 1, 1, 1, 0, 0, 0, 0 }, // 7
  { 1, 1, 1, 1, 1, 1, 1 }, // 8
  { 1, 1, 1, 1, 0, 1, 1 }, // 9
  { 1, 1, 1, 0, 1, 1, 1 }, // A
  { 0, 0, 1, 1, 1, 1, 1 }, // b
  { 1, 0, 0, 1, 1, 1, 0 }, // C
  { 0, 1, 1, 1, 1, 0, 1 }, // d
  { 1, 0, 0, 1, 1, 1, 1 }, // E
  { 1, 0, 0, 0, 1, 1, 1 }  // F
};

// Lista de caracteres para exibição
char simbolos[] = {'1', '2', '3', '4', '5', '7', '8', '9', 'A', 'b', 'C', 'd', 'E', 'F'};

// Função para exibir um caractere
void exibirCaractere(int indice) {
  digitalWrite(a, caracteres[indice][0]);
  digitalWrite(b, caracteres[indice][1]);
  digitalWrite(c, caracteres[indice][2]);
  digitalWrite(d, caracteres[indice][3]);
  digitalWrite(e, caracteres[indice][4]);
  digitalWrite(f, caracteres[indice][5]);
  digitalWrite(g, caracteres[indice][6]);
}

void setup() {
  // Configuração dos pinos como saída
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop() {
  for (int i = 0; i < 14; i++) {
    exibirCaractere(i); // Exibe o caractere correspondente
    delay(1000);        // Espera 1 segundo antes de mudar para o próximo
  }
}