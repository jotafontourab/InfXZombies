#include <stdio.h>
#include <string.h>
#include "leaderboard.h"
#include "game.h"

void CarregaLeaderboard(JOGADOR jogadores[], int tamanho) {
    FILE *f = fopen("top_scores.bin", "rb");
    if (f) {

        for (int i = 0; i < tamanho; i++) {
            jogadores[i].nomejogador[0] = '\0';
            jogadores[i].pontuacao = 0;
        }
        
        fread(jogadores, sizeof(JOGADOR), tamanho, f);
        fclose(f);
    } else {

        for (int i = 0; i < tamanho; i++) {
            snprintf(jogadores[i].nomejogador, MAX_NOME, "Jogador %d", i+1);
            jogadores[i].pontuacao = 400 - (i * 100); 
        }
    }
}


void SalvaLeaderboard(JOGADOR jogadores[], int tamanho) {
    FILE *f = fopen("top_scores.bin", "wb");
    if (f) {

        for (int i = 0; i < tamanho; i++) {
            if (strlen(jogadores[i].nomejogador) == 0) {
                snprintf(jogadores[i].nomejogador, MAX_NOME, "Jogador %d", i+1);
            }
        }
        
        fwrite(jogadores, sizeof(JOGADOR), tamanho, f);
        fclose(f);
    }
}

void AtualizaLeaderboard(JOGADOR jogadores[], int tamanho, JOGADOR novoJogador) {

    if (tamanho == 0 || novoJogador.pontuacao <= jogadores[tamanho-1].pontuacao) {
        return;
    }

    int pos = tamanho - 1;
    while (pos > 0 && novoJogador.pontuacao > jogadores[pos-1].pontuacao) {
        pos--;
    }


    for (int i = 0; i < tamanho; i++) {
        if (strcmp(jogadores[i].nomejogador, novoJogador.nomejogador) == 0 && 
            jogadores[i].pontuacao == novoJogador.pontuacao) {
            return; 
        }
    }


    for (int i = tamanho - 1; i > pos; i--) {
        jogadores[i] = jogadores[i-1];
    }


    strncpy(jogadores[pos].nomejogador, novoJogador.nomejogador, MAX_NOME-1);
    jogadores[pos].nomejogador[MAX_NOME-1] = '\0';
    jogadores[pos].pontuacao = novoJogador.pontuacao;
}