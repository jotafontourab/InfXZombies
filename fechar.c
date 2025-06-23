#include <raylib.h>
#include "menu.h"
#include "fechar.h"




void desenhaSair(Texture2D background, Texture2D botaomenugenerico, float x, float y, float escalabackground){
 
       DrawTextureEx(background, (Vector2){ x, y }, 0.0f, escalabackground, WHITE);
       DrawTextureEx(botaomenugenerico, (Vector2){ x +250 , y + 200 }, 0.0f, 0.4f, WHITE); // desenhando o botao menu generico na tela.
       DrawText("Deseja realmente sair?", x + 230, y + 160, 40, MAROON);
       DrawText("Sim", x + 360, y + 360, 40, MAROON);
       DrawText("Nao", x + 480, y + 360, 40, MAROON);

}