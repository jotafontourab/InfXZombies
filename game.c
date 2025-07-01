#include <raylib.h>
#include "game.h"
#include "sois.h"
#include "zumbis.h"
#include "plantas.h"
#include "leaderboard.h"
#include <stdbool.h> 
#include <string.h>
#define MARGEM_X 35
#define MARGEM_Y 95
#define LINHAS 5
#define COLUNAS 9
#define LARGURA_QUADRADINHO 72
#define ALTURA_QUADRADINHO 96
#define INTERVALO_DISPARO_ERVILHA 10.0f 
#define INTERVALO_DISPARO_GIRASSOL 13.0f 
#define DANO_ERVILHA 20
#define DANO_GIRASSOL 15
#define VELOCIDADE_PROJETIL 15.0f



JOGADOR jogador; // Variável global para armazenar o jogador atual



typedef enum {
    SELECAO_NENHUMA,
    SELECIONANDO_ERVILHA,
    SELECIONANDO_GIRASSOL
} PlantaSelecionada;


int pontuacao = 0;

static float tempoDesdeUltimoDisparo[LINHAS][COLUNAS] = {0};

int permissaohordacontinua = 1; 

int tabuleiro[LINHAS][COLUNAS] = { 0 };

bool jogoVencido = false;


PlantaSelecionada plantaSelecionada = SELECAO_NENHUMA;

#include <string.h>
#include "leaderboard.h"

void SalvaPontuacaoFinal(const char *nomeJogador, int pontuacao) {
    JOGADOR jogadores[5], atual;
    CarregaLeaderboard(jogadores, 5);
    strcpy(atual.nomejogador, nomeJogador);
    atual.pontuacao = pontuacao;
    AtualizaLeaderboard(jogadores, 5, atual);
    SalvaLeaderboard(jogadores, 5);
}


void initGame(Texture2D grama, Texture2D botaomenugenerico, int horda[]) { //funcao que reseta todas as variaveis do jogo, para que o jogo possa reiniciar
    pontuacao=0;
    InitPlantas(); 
    InitSois();
    InitZumbis();// reseta o numero da horda
    permissaohordacontinua = 1;
    
    

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}


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
                 Texture2D projetil) {

int botaoclicado = 0; // variável para controlar o botão clicado, para que a confirmação de clique não fique ativa, para conseguir colocar as plantas no tabuleiro
char jogadorNome[25];

AtualizarProjeteis(delta, zumbi);

Vector2 mouse = { 0.0f, 0.0f }; 
mouse = GetMousePosition();
int btnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED | verificar mouse (documentacao raylib)
bool btnAction = false;         // Button action should be activated | verificar se botao pressionado - mouse (documentacao raylib)
           
            DrawTextureEx(gamebackground, (Vector2){ x, y }, 0.0f, escalabackground, WHITE);
            DrawTextureEx(gamebackground, (Vector2){ x, y }, 0.0f, escalabackground, WHITE);
                    for (int i = 0; i < LINHAS; i++) {
                        for (int j = 0; j < COLUNAS; j++) {
                        float posX = MARGEM_X + j * grama.width;
                        float posY = MARGEM_Y + i * grama.height;

                        if ((i + j) % 2 == 0) {
                             DrawTexture(grama, posX, posY, WHITE);
                        } else {
                        DrawTexture(terra, posX, posY, WHITE);
                        }   
    }
}          
          DrawTexture(botaoinv, 170, 14, WHITE); 
          DrawTexture(botaoinv, 280, 14, WHITE); 
          DrawTextureEx(sol, (Vector2){ 50, 22 }, 0.0f, 1.2f, WHITE);
          DrawTextureEx(girassol, (Vector2){ 170, 6 }, 0.0f, 0.7f, WHITE);
          DrawTextureEx(ervilha, (Vector2){ 280, 6 }, 0.0f, 0.7f, WHITE);
          Rectangle botaogirassolBounds = { +170 , + 15, botaoinv.width , botaoinv.height  }; 
          Rectangle botaoervilhaBounds ={ +280, +15, botaoinv.width , botaoinv.height  };
          DrawText("50", 200,88 , 26, BLACK);
          DrawText("100", 310,88 , 26, BLACK);
          DrawSois();
          

if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    if (CheckCollisionPointRec(mouse, botaoervilhaBounds) && SoisColetados() >= 100) {
        plantaSelecionada = SELECIONANDO_ERVILHA;
        botaoclicado = 1; 
    }
    else if (CheckCollisionPointRec(mouse, botaogirassolBounds) && SoisColetados() >= 50) {
        plantaSelecionada = SELECIONANDO_GIRASSOL;
        botaoclicado = 1;
    }
}
        
              DrawText(TextFormat("%d", numSois), 75, 50, 30, BLACK);

    if (plantaSelecionada != SELECAO_NENHUMA && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)  && !botaoclicado) {
        int col = (mouse.x - MARGEM_X -30) / grama.width;
        int lin = (mouse.y - MARGEM_Y) / grama.height;

    if (lin >= 0 && lin < LINHAS && col >= 0 && col < COLUNAS && tabuleiro[lin][col] == 0) {
        if (plantaSelecionada == SELECIONANDO_ERVILHA && SoisColetados() >= 100) {
            tabuleiro[lin][col] = 1;
            SubtraiSois(100);
        }
        else if (plantaSelecionada == SELECIONANDO_GIRASSOL && SoisColetados() >= 50) {
            tabuleiro[lin][col] = 2;
            SubtraiSois(50);
        }

        plantaSelecionada = SELECAO_NENHUMA;
    }
  }

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
        float x = (MARGEM_X -30) + j * grama.width;
        float y = MARGEM_Y + i * grama.height;

        if (tabuleiro[i][j] == 1)
            DrawTexture(ervilha, x+15, y-15, WHITE);
        else if (tabuleiro[i][j] == 2)
            DrawTexture(girassol, x+15, y-15, WHITE);
    }

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            float x = (MARGEM_X -30) + j * grama.width;
            float y = MARGEM_Y + i * grama.height;
            
            if (tabuleiro[i][j] == 1 || tabuleiro[i][j] == 2) { // Ervilha ou Girassol
                // Atualiza temporizador
                tempoDesdeUltimoDisparo[i][j] += delta;
                
                // Verifica se pode atirar
                float intervalo = (tabuleiro[i][j] == 1) ? INTERVALO_DISPARO_ERVILHA : INTERVALO_DISPARO_GIRASSOL;
                int dano = (tabuleiro[i][j] == 1) ? DANO_ERVILHA : DANO_GIRASSOL;
                
                if (tempoDesdeUltimoDisparo[i][j] >= intervalo) {
                    // Verifica se há zumbis à frente
                    bool temZumbi = false;
                    for (int z = 0; z < NUM_MAXDEZUMBIS; z++) {
                        if (zumbis[z].ativo && zumbis[z].pos.x > x) {
                            temZumbi = true;
                            break;
                        }
                    }
                    
                    // Dispara se houver zumbi
                    if (temZumbi) {
                        CriarProjetil((Vector2){x + 50, y + 20}, i, dano, VELOCIDADE_PROJETIL);
                        tempoDesdeUltimoDisparo[i][j] = 0.0f; // Reseta o temporizador
                    }
                }
            }
        }
    }
}
if(permissaohordacontinua ==1){
AtualizaZumbis(delta, grama, horda, botaomenugenerico, &permissaohordacontinua); // Atualiza os zumbis, passando o delta e a textura da grama
DesenhaZumbis(zumbi);
DesenharProjeteis(projetil);
}

if (permissaohordacontinua == 0) {
    if (jogoVencido) {
        DrawRectangle(0, 0, 800, 600, Fade(GREEN, 0.5f));
        DrawText("Parabéns! Você venceu!", 170, 280, 30, DARKGREEN);
        DrawText(TextFormat("Pontuação: %d", pontuacao), 300, 320, 30, WHITE); // Mostra a pontuação
        DrawText("Aperte ESC para voltar ao menu", 200, 340, 20, WHITE);
        SalvaPontuacaoFinal(jogador.nomejogador, pontuacao);
    } else {
        DrawRectangle(0, 0, 800, 600, Fade(BLACK, 0.5f));
        DrawText("GAME OVER", 250, 280, 50, RED);
        DrawText(TextFormat("Pontuação: %d", pontuacao), 300, 320, 30, WHITE); // Mostra a pontuação
        DrawText("Aperte ESC para voltar ao menu", 220, 340, 20, WHITE);
        SalvaPontuacaoFinal(jogador.nomejogador, pontuacao);
    }
}
}



