#include <ControleMotoresL298N.h>

#define PINO_VELOCIDADE_ESQUERDA 13
#define PINO_VELOCIDADE_DIREITA 12
const byte PINOS_MOTORES[4] = {3,4,5,6};

ControleMotoresL298N motores(PINO_VELOCIDADE_ESQUERDA, PINO_VELOCIDADE_DIREITA, PINOS_MOTORES);
void setup(){
  motores.acionar(255,255);
}
void loop(){

}