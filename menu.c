#include <raylib.h>
#include "menu.h"


void desenhaMenu(Texture2D background,
                 Texture2D botaoplay,
                 Texture2D botaoleaderboard,
                 Texture2D botaosair,
                 float x,
                 float y,
                 float escalabackground){
           
            DrawTextureEx(background, (Vector2){ x, y }, 0.0f, escalabackground, WHITE);
            DrawTextureEx(botaoplay, (Vector2){ x + 365, y + 165 }, 0.0f, 0.2f, WHITE); // desenhando o background e o botao play na tela.
            DrawTextureEx(botaoleaderboard, (Vector2){ x + 365, y + 310 }, 0.0f, 0.2f, WHITE); // desenhando o botao leaderboard na tela.
            DrawTextureEx(botaosair, (Vector2){ x + 365, y + 455 }, 0.0f, 0.2f, WHITE); // desenhando o botao sair na tela.

        }