#include <raylib.h>
#include <stdio.h>
#include "game.h"
#include "zumbis.h"
// #define VIDA_ZUMBI 100
#define VELOCIDADE_ZUMBI 12.0f
#define HORA_SPAWN_HORDA 10.0f
#define MARGEM_X 35
#define MARGEM_Y 95

int zumbisPorHorda = 5;

float tempoParaHorda = 0.0f;

Zumbi zumbis[NUM_MAXDEZUMBIS];  

typedef struct {
    Vector2 pos;       // posição na tela
    int linha;         // linha em que ele esta (0 a 4)
    float velocidade;  // vel de movimento
    int vida;          // vida do zumbi (começa em 100)
    bool ativo;        //se ta vivo
} ZUMBI;

void InitZumbis(void) {
    for (int i = 0; i < NUM_MAXDEZUMBIS; i++) {
        zumbis[i].ativo = false;
        zumbis[i].vida = 100;
        zumbis[i].pos = (Vector2){ 0, 0 };
        zumbis[i].linha = 0;
        zumbis[i].velocidade = VELOCIDADE_ZUMBI;
    }

    tempoParaHorda = f;  // reseta o tempo entre hordas
}


void SpawnHorda(Texture2D grama) {
    int spawnados = 0;

    for (int i = 0; i < NUM_MAXDEZUMBIS && spawnados < zumbisPorHorda; i++) {
        if (!zumbis[i].ativo) {
            zumbis[i].ativo = true;
            zumbis[i].vida = 100;
            zumbis[i].linha = GetRandomValue(0, 5 - 1); // 5 eh o num de linhas
            zumbis[i].velocidade = VELOCIDADE_ZUMBI;
            zumbis[i].pos = (Vector2){
                MARGEM_X + COLUNAS * grama.width + GetRandomValue(0, 100),   
                MARGEM_Y + zumbis[i].linha * grama.height
            };
            spawnados++;
        }
    }
}

void AtualizaZumbis(float delta, Texture2D grama) {
    tempoParaHorda += delta;

    if (tempoParaHorda >= HORA_SPAWN_HORDA) {
        SpawnHorda(grama);
        tempoParaHorda = 0.0f;
    }

    for (int i = 0; i < NUM_MAXDEZUMBIS; i++) {
        if (zumbis[i].ativo) {
            zumbis[i].pos.x -= zumbis[i].velocidade * delta;

            
            int col = (zumbis[i].pos.x - MARGEM_X + grama.width / 2) / grama.width;

         if (col >= 0 && col < COLUNAS) {
             if (tabuleiro[zumbis[i].linha][col] != 0) {
               tabuleiro[zumbis[i].linha][col] = 0;
            }
 }


            if (zumbis[i].pos.x < 0) zumbis[i].ativo = false;
        }
    }
}

void DesenhaZumbis(Texture2D zumbi) {
    for (int i = 0; i < NUM_MAXDEZUMBIS; i++) {
        if (zumbis[i].ativo) {
            DrawTexture(zumbi, zumbis[i].pos.x, zumbis[i].pos.y, WHITE);
        }
    }
}