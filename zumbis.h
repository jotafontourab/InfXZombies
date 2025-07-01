#ifndef ZUMBIS_H
#define ZUMBIS_H
#include "raylib.h"
#define NUM_MAXDEZUMBIS 25
#include <stdbool.h> 

typedef struct {
    Vector2 pos;
    int linha;
    float velocidade;
    int vida;
    bool ativo;
} ZUMBI;


void InitZumbis(void);

bool TemZumbisVivos(void);

void AtualizaZumbis(float delta, Texture2D grama, int horda[], Texture2D botaomenugenerico, int *permissaohordacontinua);

void SpawnHorda(Texture2D grama, int horda, int *permissaohordacontinua);

void DesenhaZumbis(Texture2D zumbi);

#endif