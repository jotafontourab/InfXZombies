
#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#define MAX_NOME 25
#define MAX_JOGADORES 5

typedef struct {
char nomejogador[25]; // nome do jogador
int pontuacao; // pontuacao do jogador
}JOGADOR;



void AtualizaLeaderboard(JOGADOR jogadores[], int tamanho, JOGADOR novoJogador);
void CarregaLeaderboard(JOGADOR jogadores[], int tamanho);
void SalvaLeaderboard(JOGADOR jogadores[], int tamanho);


#endif