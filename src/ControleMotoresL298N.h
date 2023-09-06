#ifndef CONTROLEMOTORESL298N_H
#define CONTROLEMOTORESL298N_H

#include <Arduino.h>

class ControleMotoresL298N {
public:
  // Construtor
  ControleMotoresL298N(const byte PINO_VELOCIDADE_ESQUERDA, const byte PINO_VELOCIDADE_DIREITA, const byte (&PORTAS_MOTORES)[4]);
  void parado();
  void acionar(short velocidadeEsquerda, short velocidadeDireita);
  void acionar(short velocidadeEsquerda, short velocidadeDireita, short time);
private:
    const byte (&PORTAS_MOTORES)[4];
    const byte PINO_VELOCIDADE_ESQUERDA;
    const byte PINO_VELOCIDADE_DIREITA;
};
#endif