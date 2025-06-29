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
                 Texture2D sol) {
           
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
           DrawTextureEx(sol, (Vector2){ 50, 30 }, 0.0f, 1.2f, WHITE);
           DrawTextureEx(girassol, (Vector2){ 150, 20 }, 0.0f, 1.0f, WHITE);
                 }

//if (IsKeyPressed(KEY_ESCAPE)) { //se apertar esc, volta para o menu
            
//            currentScreen = OPCAOSAIR;
//}