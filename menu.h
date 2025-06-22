#ifndef MENU_H
#define MENU_H

// Inclua raylib aqui para que a função possa usar os tipos do raylib
#include "raylib.h"

// Protótipo da função
void desenhaMenu(Texture2D background,
                 Texture2D botaoplay,
                 Texture2D botaoleaderboard,
                 Texture2D botaosair,
                 float x,
                 float y,
                 float escalabackground);

#endif // MENU_H
