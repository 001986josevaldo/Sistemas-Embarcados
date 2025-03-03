
// Semáforo 4 tempos

// Classe Semáforo
class Semaforo {
  private:
    int vermelho, amarelo, verde;

  public:
    Semaforo(int pinoVermelho, int pinoAmarelo, int pinoVerde) {
      vermelho = pinoVermelho;
      amarelo = pinoAmarelo;
      verde = pinoVerde;
      
      pinMode(vermelho, OUTPUT);
      pinMode(amarelo, OUTPUT);
      pinMode(verde, OUTPUT);
    }

    void verdeLigado() {
      digitalWrite(verde, HIGH);
      digitalWrite(amarelo, LOW);
      digitalWrite(vermelho, LOW);
    }

    void amareloLigado() {
      digitalWrite(verde, LOW);
      digitalWrite(amarelo, HIGH);
      digitalWrite(vermelho, LOW);
    }

    void vermelhoLigado() {
      digitalWrite(verde, LOW);
      digitalWrite(amarelo, LOW);
      digitalWrite(vermelho, HIGH);
    }
};

// Definição dos semáforos
Semaforo semaforo2(4,3,2);
Semaforo semaforo3(7,6,5);

Semaforo semaforo1(10,9,8);
Semaforo semaforo4(13,12,11);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Semáforo de 4 tempos");

  // Fase 1: Semáforos 1 e 3 VERDE, Semáforos 2 e 4 VERMELHO
  semaforo1.verdeLigado();
  semaforo3.verdeLigado();
  semaforo2.vermelhoLigado();
  semaforo4.vermelhoLigado();
  delay(5000);

  // Fase 2: Semáforos 1 e 3 AMARELO

  semaforo1.amareloLigado();
  semaforo3.amareloLigado();
  delay(2000);

  // Fase 3: Semáforos 1 e 3 VERMELHO, Semáforos 2 e 4 VERDE
  semaforo1.vermelhoLigado();
  semaforo3.vermelhoLigado();
  semaforo2.verdeLigado();
  semaforo4.verdeLigado();
  delay(5000);

  // Fase 4: Semáforos 2 e 4 AMARELO
  semaforo2.amareloLigado();
  semaforo4.amareloLigado();
  delay(2000);
}
