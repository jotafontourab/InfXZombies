#ifndef ZUMBIS_H
#define ZUMBIS_H
#include "raylib.h"
#define NUM_MAXDEZUMBIS 25

typedef struct {
    Vector2 pos;
    int linha;
    float velocidade;
    int vida;
    bool ativo;
} Zumbi;


void InitZumbis(void);

void AtualizaZumbis(float delta, Texture2D grama);

void SpawnHorda(Texture2D grama);

void DesenhaZumbis(Texture2D zumbi);

#endif