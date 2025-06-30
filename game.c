#include <raylib.h>
#include "game.h"
#include "sois.h"
#define MARGEM_X 35
#define MARGEM_Y 95
#define LINHAS 5
#define COLUNAS 9
#define LARGURA_QUADRADINHO 72
#define ALTURA_QUADRADINHO 96


typedef enum {
    SELECAO_NENHUMA,
    SELECIONANDO_ERVILHA,
    SELECIONANDO_GIRASSOL
} PlantaSelecionada;

typedef struct s_planta{
    char tipo; // G - Girassois | E - Ervilhas 
    int localizax;
    int localizay; 
    int preco; // em sois
    int dano;
}PLANTA;

typedef struct s_zumbi{
    int localizax;
    int localizay;
    int velocidadex;
    int vida;
}ZUMBI;

int tabuleiro[LINHAS][COLUNAS] = { 0 };

PlantaSelecionada plantaSelecionada = SELECAO_NENHUMA;


void desenhaGame(Texture2D gamebackground,
                 float x,
                 float y,
                 float escalabackground, 
                 Texture2D grama, 
                 Texture2D terra,
                 Texture2D girassol,
                 Texture2D ervilha,
                 Texture2D sol,
                 Texture2D botaoinv,
                 Texture2D botaoinv2) {

int botaoclicado = 0; // Variável para controlar o botão clicado, para que a confirmação de clique não fique ativa, para conseguir colocar as plantas no tabuleiro
int soiscont = 0;
 // Variável para controlar o botão clicado, para que a confirmacao de clique nao fique ativa, para conseguir colocar as plantas no tabuleiro



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
          DrawTextureEx(girassol, (Vector2){ 160, 12 }, 0.0f, 0.85f, WHITE);
          DrawTextureEx(ervilha, (Vector2){ 270, 12 }, 0.0f, 0.85f, WHITE);
          Rectangle botaogirassolBounds = { +170 , + 15, botaoinv.width , botaoinv.height  }; 
          Rectangle botaoervilhaBounds ={ +280, +15, botaoinv.width , botaoinv.height  };
          DrawText("50", 200,88 , 26, BLACK);
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
               soiscont = SoisColetados(); 
              DrawText(TextFormat("%d", soiscont), 75, 50, 30, BLACK);

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
            DrawTexture(ervilha, x, y, WHITE);
        else if (tabuleiro[i][j] == 2)
            DrawTexture(girassol, x, y, WHITE);
    }
}

}

//if (IsKeyPressed(KEY_ESCAPE)) { //se apertar esc, volta para o menu
            
//            currentScreen = OPCAOSAIR;
//}