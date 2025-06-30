#ifndef GAME_H
#define GAME_H

// Inclua raylib aqui para que a função possa usar os tipos do raylib
#include "raylib.h"

// Protótipo da função
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
                 Texture2D botaoinv2);

#endif // GAME_H
