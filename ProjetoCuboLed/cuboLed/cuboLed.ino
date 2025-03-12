
// Este código faz parte de um projeto que utiliza um Cubo de LEDs 4x4x4, controlado por um microcontrolador Arduino Nano. 
// A implementação foi dividida em três arquivos principais: 
// - "CuboLED.h" que contém a definição da classe CuboLED e suas funções.
// - "CuboLED.cpp" que implementa as funções da classe CuboLED definidas em "CuboLED.h".
// - "CuboLED.ino" que contém o código principal do programa, onde o CuboLED é instanciado e 
//  manipulado para realizar diferentes efeitos de luz.
// O código define os pinos das colunas e andares do cubo e utiliza a classe CuboLED para controlar os LEDs, 
//criando efeitos como espiral, sequências de acendimento, ondas verticais, e outros efeitos visuais interessantes.

#include "CuboLED.h"

// Definição dos pinos
int colunas[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
int andares[] = {19, 18, 17, 16};


// Instância da classe CuboLED
CuboLED cubo(colunas, andares);

void setup() {
    cubo.iniciar();
}

void loop() {
    //cubo.espiral();
    cubo.testeLed();
    cubo.vaiAcendendoVoltaApagando();
    cubo.acenderSequencia();
    cubo.acenderTodos();
    delay(100);
    cubo.acenderPorAndar();
    delay(100);
    cubo.ondaVertical();
    delay(100);
    cubo.luzesAleatorias();
    delay(100);
    cubo.chuvaDeLeds(10);
    delay(100);
    // 4 parte
    //cubo.efeitoChuva();
    cubo.efeitoCuboGiratorio(); 
    cubo.efeitoEspiral3D();
    cubo.efeitoExplosao();
    cubo.efeitoOnda3D();
}
