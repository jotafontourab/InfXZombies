#ifndef PLANTAS_H
#define PLANTAS_H

#include <raylib.h>

#define MAX_PROJETEIS 100

extern int pontuacao;

typedef struct {
    Vector2 posicao;
    float velocidade;
    int linha;
    int dano;
    bool ativo;
} Projetil;

void InitPlantas(void);



void CriarProjetil(Vector2 posInicial, int linha, int dano, float velocidade);
void DesenharProjeteis(Texture2D projetil);
void AtualizarProjeteis(float delta, Texture2D zumbi);
#endif