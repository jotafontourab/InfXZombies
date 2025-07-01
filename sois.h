#ifndef SOIS_H
#define SOIS_H

#include "raylib.h"

typedef struct {
    Vector2 posicao;
    bool ativo;
    float tempoVida;
} Sol;

extern int numSois;

void InitSois(void);
void AtualizaSois(void);
void DrawSois(void);
int SoisColetados(void);
void SubtraiSois(int valor);

#endif
