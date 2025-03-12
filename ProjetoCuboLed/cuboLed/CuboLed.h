#ifndef CUBOLED_H
#define CUBOLED_H

#include <Arduino.h>

class CuboLED {
  private:
    int colunas[16];  
    int andares[4];

  public:
    CuboLED(int cols[16], int ands[4]); 
    void iniciar();
    void acenderTodos();
    void apagarTodos();
    void acenderPorAndar();
    void ondaVertical();
    void luzesAleatorias();
    void chuvaDeLeds(int velocidade);
    void efeitoExplosao();
    void efeitoOnda3D();
    void efeitoEspiral3D();
    void efeitoChuva();
    void efeitoCuboGiratorio();
    void acenderSequencia();
    void vaiAcendendoVoltaApagando();
    void testeLed();
    void espiral();
};

#endif
