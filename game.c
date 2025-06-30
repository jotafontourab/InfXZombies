#include <raylib.h>
#include "game.h"
#include "sois.h"
#define MARGEM_X 35
#define MARGEM_Y 95

typedef enum {
    SELECAO_NENHUMA,
    SELECIONANDO_ERVILHA,
    SELECIONANDO_GIRASSOL
} PlantaSelecionada;

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

int sois = 0;
Vector2 mouse = GetMousePosition();
int btnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED | verificar mouse (documentacao raylib)
bool btnAction = false;         // Button action should be activated | verificar se botao pressionado - mouse (documentacao raylib)
           
            DrawTextureEx(gamebackground, (Vector2){ x, y }, 0.0f, escalabackground, WHITE);
            DrawTextureEx(gamebackground, (Vector2){ x, y }, 0.0f, escalabackground, WHITE);
                    for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 9; j++) {
                        float posX = MARGEM_X + j * grama.width;
                        float posY = MARGEM_Y + i * grama.height;

                        if ((i + j) % 2 == 0) {
                             DrawTexture(grama, posX, posY, WHITE);
                        } else {
                        DrawTexture(terra, posX, posY, WHITE);
                        }   
    }
}          
          DrawTexture(botaoinv, 170, 14, WHITE); // Desenha o botão de inventário na posição (150, 20) 
          DrawTextureEx(sol, (Vector2){ 50, 22 }, 0.0f, 1.2f, WHITE);
          DrawTextureEx(girassol, (Vector2){ 160, 12 }, 0.0f, 0.85f, WHITE);
          Rectangle botaogirassolBounds = { +170 , + 15, botaoinv.width , botaoinv.height  }; 
          DrawText(TextFormat("%d", sois), 83, 50, 30, BLACK);
          Rectangle botaoervilhaBounds ={ +250, +15, botaoinv.width , botaoinv.height  };
          
          if (CheckCollisionPointRec(mouse, botaogirassolBounds))
            {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
                else btnState = 1;

                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
                if (btnAction){
                    DrawRectangleLinesEx(botaogirassolBounds, 20, RED);
                    plantaSelecionada = SELECIONANDO_GIRASSOL;
                 }
                 else{
               DrawRectangleLinesEx(botaogirassolBounds, 20, DARKGRAY);  // botão "inativo"

                 }
               }
               else if (CheckCollisionPointRec(mouse, botaoervilhaBounds))
            {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
                else btnState = 1;

                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
                if (btnAction){
                    plantaSelecionada = SELECIONANDO_ERVILHA;
                 }
               }
               if(plantaSelecionada == SELECIONANDO_GIRASSOL){
                    InitSois();
                    AtualizaSois();
                    sois = SoisColetados();
               }

              
}

//if (IsKeyPressed(KEY_ESCAPE)) { //se apertar esc, volta para o menu
            
//            currentScreen = OPCAOSAIR;
//}