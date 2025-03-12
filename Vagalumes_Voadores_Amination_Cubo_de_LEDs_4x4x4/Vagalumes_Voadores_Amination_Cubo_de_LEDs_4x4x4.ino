
/****** Programação Cubo de LEDs 4x4x4 com Arduino NANO *******/

/* Pinos Arduino NANO: RX = 0; TX = 1; D2 = 2; D2 = 2; D3 = 3; D4 = 4; D5 = 5;
D6 = 6; D7 = 7; D8 = 8; D9 = 9; D10 = 10; D11 = 11; D12 = 12; D13 = 13; A0 = 14;
A1 = 15; A2 = 16; A3 = 17; A4 = 18; A5 = 19; A6 = 20; A7 = 21; */

//Posição no vetor:
//               0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15
int Colunas[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,14,15,16,17}; 
//Posição no vetor:
//                0   1   2   3  
int Andares[] = {18,19,20,21};
   
int RandColuna;  
int RandAndares;
   
void setup()
{
int contador;
   
for (int contador = 0; contador < 17; contador++){
  pinMode(Colunas[contador], OUTPUT); }
   
for (int contador = 0; contador < 5; contador++){
  pinMode(Andares[contador], OUTPUT); }

digitalWrite(Colunas[0], LOW);
}
   
void loop()
{
RandLed();
}
   
void RandLed()
{
RandAndares = random(0,4);
RandColuna = random(0,16);
   
digitalWrite(Andares[RandAndares], HIGH);
digitalWrite(Colunas[RandColuna], HIGH);
   
delay(75);
   
digitalWrite(Andares[RandAndares], LOW);
digitalWrite(Colunas[RandColuna], LOW);
   
delay(50);
}
