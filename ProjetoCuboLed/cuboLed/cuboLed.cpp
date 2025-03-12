#include "CuboLED.h"
// Definição da variável global
const int tamanhoSequencia = 16; // Tamanho da sequência
int Sequencia[tamanhoSequencia] = {1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10};
CuboLED::CuboLED(int cols[16], int ands[4]) {
    for (int i = 0; i < 16; i++) {
        colunas[i] = cols[i];
    }
    for (int i = 0; i < 4; i++) {
        andares[i] = ands[i];
    }
}

void CuboLED::iniciar() {
    for (int i = 0; i < 16; i++) {
        pinMode(colunas[i], OUTPUT);
        digitalWrite(colunas[i], LOW);
    }

    for (int i = 0; i < 4; i++) {
        pinMode(andares[i], OUTPUT);
        digitalWrite(andares[i], LOW);
    }
}

void CuboLED::acenderTodos() {
    for (int i = 0; i < 4; i++) digitalWrite(andares[i], HIGH);
    for (int i = 0; i < 16; i++) digitalWrite(colunas[i], HIGH);
    delay(500);
    apagarTodos();
}

void CuboLED::apagarTodos() {
    for (int i = 0; i < 4; i++) digitalWrite(andares[i], LOW);
    for (int i = 0; i < 16; i++) digitalWrite(colunas[i], LOW);
}

void CuboLED::acenderPorAndar() {
    for (int i = 0; i < 4; i++) {
        digitalWrite(andares[i], HIGH);
        for (int j = 0; j < 16; j++) digitalWrite(colunas[j], HIGH);
        delay(100);
        apagarTodos();
    }
}

void CuboLED::ondaVertical() {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 4; j++) {
            digitalWrite(andares[j], HIGH);
            digitalWrite(colunas[i], HIGH);
            delay(10);
            digitalWrite(andares[j], LOW);
            digitalWrite(colunas[i], LOW);
        }
    }
}

void CuboLED::luzesAleatorias() {
    for (int i = 0; i < 32; i++) {
        int andar = random(0, 4);
        int coluna = random(0, 16);

        digitalWrite(andares[andar], HIGH);
        digitalWrite(colunas[coluna], HIGH);
        delay(10);
        digitalWrite(andares[andar], LOW);
        digitalWrite(colunas[coluna], LOW);
    }
}

void CuboLED::chuvaDeLeds(int velocidade) {
    unsigned long tempo = millis();
    while (millis() - tempo < 5000) {
        int coluna = random(0, 16);
        for (int i = 3; i >= 0; i--) {
            digitalWrite(andares[i], HIGH);
            digitalWrite(colunas[coluna], HIGH);
            delay(velocidade);
            digitalWrite(andares[i], LOW);
            digitalWrite(colunas[coluna], LOW);
        }
    }
}

//----------------------------// 4 parte ---------------------------------------------
void CuboLED::efeitoExplosao() {
    int delayExplosao = 5; // Ajuste a velocidade da explosão
    for (int camada = 1; camada >= 0; camada--) {
      for (int coluna = 0; coluna < 16; coluna++) {
        digitalWrite(andares[camada], HIGH); // Ativa a camada
        digitalWrite(colunas[coluna], HIGH); // Acende o LED
        delay(delayExplosao);
        digitalWrite(colunas[coluna], LOW); // Apaga o LED
        digitalWrite(andares[camada], LOW); // Desativa a camada
      }
    }
    for (int camada = 2; camada < 4; camada++) {
      for (int coluna = 0; coluna < 16; coluna++) {
        digitalWrite(andares[camada], HIGH); // Ativa a camada
        digitalWrite(colunas[coluna], HIGH); // Acende o LED
        delay(delayExplosao);
        digitalWrite(colunas[coluna], LOW); // Apaga o LED
        digitalWrite(andares[camada], LOW); // Desativa a camada
      }
    }
  }
  
  void CuboLED::efeitoOnda3D() {
    int delayOnda = 10; // Ajuste a velocidade da onda
    for (int camada = 0; camada < 4; camada++) {
      for (int linha = 0; linha < 4; linha++) {
        for (int coluna = 0; coluna < 4; coluna++) {
          digitalWrite(andares[camada], HIGH); // Ativa a camada
          digitalWrite(colunas[linha * 4 + coluna], HIGH); // Acende o LED
          delay(delayOnda);
          digitalWrite(colunas[linha * 4 + coluna], LOW); // Apaga o LED
          digitalWrite(andares[camada], LOW); // Desativa a camada
        }
      }
    }
  }
  
  void CuboLED::efeitoEspiral3D() {
    int delayEspiral = 10; // Ajuste a velocidade da espiral
    for (int camada = 0; camada < 4; camada++) {
      for (int i = 0; i < 4; i++) {
        // Acende LEDs em espiral
        digitalWrite(andares[camada], HIGH);
        digitalWrite(colunas[i], HIGH); // Lado superior
        digitalWrite(colunas[4 + i], HIGH); // Lado direito
        digitalWrite(colunas[8 + i], HIGH); // Lado inferior
        digitalWrite(colunas[12 + i], HIGH); // Lado esquerdo
        delay(delayEspiral);
        // Apaga LEDs
        digitalWrite(colunas[i], LOW);
        digitalWrite(colunas[4 + i], LOW);
        digitalWrite(colunas[8 + i], LOW);
        digitalWrite(colunas[12 + i], LOW);
        digitalWrite(andares[camada], LOW);
      }
    }
  }
  
  void CuboLED::efeitoChuva() {
    int delayChuva = 100; // Ajuste a velocidade da chuva
    for (int i = 0; i < 50; i++) { // Repete o efeito 50 vezes
      int camada = rand() % 4; // Escolhe uma camada aleatória
      int coluna = rand() % 16; // Escolhe uma coluna aleatória
      digitalWrite(andares[camada], HIGH); // Ativa a camada
      digitalWrite(colunas[coluna], HIGH); // Acende o LED
      delay(delayChuva);
      digitalWrite(colunas[coluna], LOW); // Apaga o LED
      digitalWrite(andares[camada], LOW); // Desativa a camada
    }
  }
  
  void CuboLED::efeitoCuboGiratorio() {
    int delayGiro = 100; // Ajuste a velocidade do giro
    for (int i = 0; i < 20; i++) { // Repete o efeito 20 vezes
      for (int camada = 0; camada < 4; camada++) {
        digitalWrite(andares[camada], HIGH); // Ativa a camada
        for (int coluna = 0; coluna < 16; coluna++) {
          digitalWrite(colunas[coluna], HIGH); // Acende todos os LEDs da camada
        }
        delay(delayGiro);
        for (int coluna = 0; coluna < 16; coluna++) {
          digitalWrite(colunas[coluna], LOW); // Apaga todos os LEDs da camada
        }
        digitalWrite(andares[camada], LOW); // Desativa a camada
      }
    }
  }

void CuboLED::acenderSequencia() {
  //int Sequencia[] = {1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10};
  for (int i = 0; i < 4; i++) {
    digitalWrite(andares[i], HIGH);
  }
  for (int i = 0; i < sizeof(Sequencia) / sizeof(Sequencia[0]); i++) {
    digitalWrite(colunas[Sequencia[i] - 1], HIGH);
    delay(100);
    digitalWrite(colunas[Sequencia[i] - 1], LOW);
  }
  for (int i = (sizeof(Sequencia) / sizeof(Sequencia[0])) - 1; i >= 0; i--) {
    digitalWrite(colunas[Sequencia[i] - 1], HIGH);
    delay(25);
    digitalWrite(colunas[Sequencia[i] - 1], LOW);
  } 
}

void CuboLED::vaiAcendendoVoltaApagando(){
  for (int i = 0; i < 4; i++) {
    digitalWrite(andares[i], HIGH);
  }
  for (int i = 0; i < sizeof(Sequencia) / sizeof(Sequencia[0]); i++) {
    digitalWrite(colunas[Sequencia[i] - 1], HIGH);
    delay(100);
  }
  for (int i = (sizeof(Sequencia) / sizeof(Sequencia[0])) - 1; i >= 0; i--) {
    digitalWrite(colunas[Sequencia[i] - 1], LOW);
    delay(25);
  }
}

void CuboLED::testeLed(){
  for (int a = 0; a < 4; a++) {
    digitalWrite(andares[a], HIGH);
    for (int i = 0; i < sizeof(Sequencia) / sizeof(Sequencia[0]); i++) {
      digitalWrite(colunas[Sequencia[i] - 1], HIGH);
      delay(25);
      digitalWrite(colunas[Sequencia[i] - 1], LOW);
    }
    digitalWrite(andares[a], LOW);
  }
}

void CuboLED::espiral(){
    int ledsPorAndar = 4; // Define quantos LEDs devem ser ativados antes de iniciar o próximo andar
  int index = 0;
  
  for (int a = 0; a < 4; a++) {
    digitalWrite(andares[a], HIGH);
    for (int i = 0; i < ledsPorAndar && index < sizeof(Sequencia) / sizeof(Sequencia[0]); i++, index++) {
      digitalWrite(colunas[Sequencia[index] - 1], HIGH);
      delay(100);
    }
  }
    int index1 = (sizeof(Sequencia) / sizeof(Sequencia[0])) - 1;
  for (int a = 3; a >= 0; a--) {
    digitalWrite(andares[a], HIGH);
    for (int i = 0; i < ledsPorAndar && index1 >= 0; i++, index1--) {
      digitalWrite(colunas[Sequencia[index1] - 1], LOW);
      delay(100);
    }
    digitalWrite(andares[a], LOW);
  }
  }


  
