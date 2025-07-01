#ifndef GAME_H
#define GAME_H
#define LINHAS 5
#define COLUNAS 9


#include "raylib.h"


extern int permissaohordacontinua;

void initGame(Texture2D grama, Texture2D botaomenugenerico, int horda[]); // funcao que reseta todas as variaveis do jogo, para que o jogo possa reiniciar

void desenhaGame(Texture2D gamebackground,
                 float x,
                 float y,
                 float escalabackground, 
                 float delta,
                 Texture2D grama, 
                 Texture2D terra,
                 Texture2D girassol,
                 Texture2D ervilha,
                 Texture2D sol,
                 Texture2D botaoinv,
                 Texture2D botaoinv2,
                 Texture2D zumbi,
                 int horda[],
                 Texture2D botaomenugenerico,
                 Texture2D texturaProjetil);
                 
extern int tabuleiro[LINHAS][COLUNAS]; // tive q declara-lo globalmente e externamente, para que a funcao possa acessar o tabuleiro e para que ele nao atualize
// dentro do loop. precisei de uma ajudinha para descobrir isso kkkkkkkk


#endif
