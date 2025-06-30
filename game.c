#include <raylib.h>
#include "game.h"
#define MARGEM_X 35
#define MARGEM_Y 95


void desenhaGame(Texture2D gamebackground,
                 float x,
                 float y,
                 float escalabackground, 
                 Texture2D grama, 
                 Texture2D terra,
                 Texture2D girassol,
                 Texture2D ervilha,
                 Texture2D sol,
                 Texture2D botaoinv) {

  
           
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
          Rectangle botaoinvBounds = { +150 , + 20, botaoinv.width * 0.2f, botaoinv.height * 0.2f }; 
          DrawText(TextFormat("%d", sois), 83, 50, 30, BLACK);
                 }

//if (IsKeyPressed(KEY_ESCAPE)) { //se apertar esc, volta para o menu
            
//            currentScreen = OPCAOSAIR;
//}