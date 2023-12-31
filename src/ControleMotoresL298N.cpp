#include <ControleMotoresL298N.h>
#include <AFMotor.h>
#include <Arduino.h>

ControleMotoresL298N::ControleMotoresL298N(const byte PINO_VELOCIDADE_ESQUERDA, const byte PINO_VELOCIDADE_DIREITA, const byte (&PORTAS_MOTORES)[4]) : PINO_VELOCIDADE_ESQUERDA(PINO_VELOCIDADE_ESQUERDA), PINO_VELOCIDADE_DIREITA(PINO_VELOCIDADE_DIREITA), PORTAS_MOTORES(PORTAS_MOTORES)
{
  for (byte i : PORTAS_MOTORES)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(PINO_VELOCIDADE_ESQUERDA, OUTPUT);
  pinMode(PINO_VELOCIDADE_DIREITA, OUTPUT);
}
void ControleMotoresL298N::parado()
{
  digitalWrite(PORTAS_MOTORES[0], 0);
  digitalWrite(PORTAS_MOTORES[1], 0);
  digitalWrite(PORTAS_MOTORES[2], 0);
  digitalWrite(PORTAS_MOTORES[3], 0);
}
void ControleMotoresL298N::acionar(short velocidadeEsquerda, short velocidadeDireita)
{
  if (velocidadeEsquerda >= 0)
  {
    velocidadeEsquerda = map(velocidadeEsquerda, 0, 255, 125, 255);
  }
  else
  {
    velocidadeEsquerda = 255 - map(velocidadeEsquerda, -255, 0, 0, 125);
  }
  if (velocidadeDireita >= 0)
  {
    velocidadeDireita = map(velocidadeDireita, 0, 255, 125, 255);
  }
  else
  {
    velocidadeDireita = 255 - map(velocidadeDireita, -255, 0, 0, 125);
  }
  if (velocidadeEsquerda >= 125)
  {
    digitalWrite(PORTAS_MOTORES[0], 1);
    digitalWrite(PORTAS_MOTORES[1], 0);
  }
  else
  {
    digitalWrite(PORTAS_MOTORES[0], 0);
    digitalWrite(PORTAS_MOTORES[1], 1);
  }

  if (velocidadeDireita >= 125)
  {
    digitalWrite(PORTAS_MOTORES[2], 1);
    digitalWrite(PORTAS_MOTORES[3], 0);
  }
  else
  {
    digitalWrite(PORTAS_MOTORES[2], 0);
    digitalWrite(PORTAS_MOTORES[3], 1);
  }

  analogWrite(PINO_VELOCIDADE_ESQUERDA, velocidadeEsquerda);
  analogWrite(PINO_VELOCIDADE_DIREITA, velocidadeDireita);
}
void ControleMotoresL298N::acionar(short velocidadeEsquerda, short velocidadeDireita, short time)
{
  ControleMotoresL298N::acionar(velocidadeEsquerda, velocidadeDireita);
  delay(time);
  ControleMotoresL298N::parado();
}