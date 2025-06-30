#ifndef SOIS_H
#define SOIS_H

#include "raylib.h"

typedef struct {
    Vector2 posicao;
    bool ativo;
    float tempoVida;
} Sol;

void InitSois(void);
void AtualizaSois(void);
void DesenhaSois(void);
int SoisColetados(void);

#endif
