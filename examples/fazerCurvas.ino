#include <ControleMotoresL298N.h>

#define PINO_VELOCIDADE_ESQUERDA 13
#define PINO_VELOCIDADE_DIREIA 12
const byte PINOS_MOTORES[4] = {3,4,5,6};

ControleMotoresL298N motores(PINO_VELOCIDADE_ESQUERDA, PINO_VELOCIDADE_DIREIA, PINOS_MOTORES);
void setup(){

}
void loop(){
    motores.acionar(255, -255, 1000);
    motores.acionar(-255, 255, 1000);
}