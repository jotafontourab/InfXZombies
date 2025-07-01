#include <raylib.h>
#include <stdio.h>
#include "game.h"
#include "zumbis.h"
#include <stdbool.h> // nao conhecia essa biblioteca, mas tive que inclui-la pq para criar uma funcao booleana (necessaria, pois tenho que saber se
//ha zombis vivos ainda para poder decidir se a proxima horda vai ser spawnada ou nao) tenho que importala.
// #define VIDA_ZUMBI 100
#define VELOCIDADE_ZUMBI 8.0f
#define HORA_SPAWN_HORDA 15.0f
#define MARGEM_X 35
#define MARGEM_Y 95


float tempoParaHorda = 0.0f;

ZUMBI zumbis[NUM_MAXDEZUMBIS];  

int numHordas = 0; //parametro global, que recebe o numero de hordas DIRETAMENTE DO ARQUIVO TEXTO e dps compara com hordanum, para saber quando terminaram as hordas e quando o jogador venceu.

int hordanum = 0; // numero da horda atual, que vai ser spawnada
void InitZumbis(void) {
    for (int i = 0; i < NUM_MAXDEZUMBIS; i++) {
        zumbis[i].ativo = false;
        zumbis[i].vida = 100;
        zumbis[i].pos = (Vector2){ 0, 0 };
        zumbis[i].linha = 0;
        zumbis[i].velocidade = VELOCIDADE_ZUMBI;
    }


    tempoParaHorda = 0.0f;  // reseta o tempo entre hordas
}

bool TemZumbisVivos(void) {
    for (int i = 0; i < NUM_MAXDEZUMBIS; i++) {
        if (zumbis[i].ativo) {
            return true;  // Sai da função AQUI MESMO se encontrar um vivo
        }
    }
    return false;  // Só chega aqui se nenhum zumbi estiver ativo
}

void SpawnHorda(Texture2D grama, int horda, int *permissaohordacontinua) {
    int spawnados = 0;
    if (*permissaohordacontinua == 0) return;

    for (int i = 0; i < NUM_MAXDEZUMBIS && spawnados < horda; i++) {
        if (!zumbis[i].ativo) {
            zumbis[i].ativo = true;
            zumbis[i].vida = 100;
            zumbis[i].linha = GetRandomValue(0, 5 - 1); // 5 eh o num de linhas
            zumbis[i].velocidade = VELOCIDADE_ZUMBI;
            zumbis[i].pos = (Vector2){MARGEM_X + COLUNAS * grama.width + GetRandomValue(0, 100), MARGEM_Y + zumbis[i].linha * grama.height
            };
            spawnados++;
        }
    }
}

void AtualizaZumbis(float delta, Texture2D grama, int horda[], Texture2D botaonumgenerico, int *permissaohordacontinua) {
    tempoParaHorda += delta;

   if (*permissaohordacontinua == 0){
        return; 
    }


if (*permissaohordacontinua == 1 && !TemZumbisVivos()) {                                                             //   for(int i=0; i<NUM_MAXDEZUMBIS; i++) {   //ao inves de fazer assim
                                                                                    // if (zumbis[i].ativo) {
                                                                                    //    algumvivo=1;
                                                                                    //    }else{
                                                                                    //       todosinativos=0;
                                                                                    //   }
                                                                                    //}
                                                                                    // if(todosinativos==1){
    if (hordanum < numHordas && tempoParaHorda >= HORA_SPAWN_HORDA) {
        SpawnHorda(grama, horda[hordanum], permissaohordacontinua);
        hordanum++;
        tempoParaHorda = 0.0f;
    }
    else if (hordanum >= numHordas) {
        *permissaohordacontinua = 0;
        jogoVencido = true;
    }
}


    

    for (int i = 0; i < NUM_MAXDEZUMBIS; i++) {
        if (zumbis[i].ativo) {
            zumbis[i].pos.x -= zumbis[i].velocidade * delta;


            
            int col = (zumbis[i].pos.x - MARGEM_X + grama.width / 2) / grama.width;

         if (col >= 0 && col < COLUNAS) {
             if (tabuleiro[zumbis[i].linha][col] != 0) {
               tabuleiro[zumbis[i].linha][col] = 0;
            }

            if (hordanum >= numHordas && !TemZumbisVivos()) {
            *permissaohordacontinua = 0;
            jogoVencido = true;  // variável de vitória
}
 }


            if (zumbis[i].pos.x < 0) {          // se o zumbi sair da tela, ele é considerado morto e alem disso, o jogador perde o jogo, entao
                //criar tela pra perder o jogo e voltar pro menu. lembrar de adotar os pontos e salvar dentro do arquivo binario. 
                zumbis[i].ativo = false;
                *permissaohordacontinua = 0;
                jogoVencido = false; // jogador perdeu o jogo, pois zumbis chegaram no final do tabuleiro
                
        }
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

