#include <raylib.h>
#include <stdio.h>

int main(void){
    
    InitWindow(800, 600, "Hello Raylib");
    SetTargetFPS(60);

    int screenWidth = 800;
    int screenHeight = 600;
    float escalabackground = 1.07f; // tive que criar uma escala para que o background ficasse do tamanho certo.

    Image imagebackground = LoadImage("sprites/menu-background.png");
    Image imagebotaoplay = LoadImage("sprites/play-button.png");
    Image imagebotaoleaderboard = LoadImage("sprites/leaderboard-button.png");
    Image imagebotaosair = LoadImage("sprites/exit-button.png");
    
    ImageResize(&imagebackground, 800, 600);
    
    Texture2D background = LoadTextureFromImage(imagebackground); // carregando a imagem do background como textura.
    Texture2D botaoplay = LoadTextureFromImage(imagebotaoplay); // carregando a imagem do botao play como textura.
    Texture2D botaoleaderboard = LoadTextureFromImage(imagebotaoleaderboard); // carregando a imagem do botao leaderboard como textura.
    Texture2D botaosair = LoadTextureFromImage(imagebotaosair); // carregando a imagem do botao sair como textura.
    float x = (screenWidth - background.width -110) / 2.0f;
    float y = (screenHeight - background.height) / 2.0f;  // apliquei a centralizacao do background
    UnloadImage(imagebackground); 
    UnloadImage(imagebotaoplay); 
    UnloadImage(imagebotaoleaderboard);
    UnloadImage(imagebotaosair);// descarregando as imagens, pois ja foram carregadas como texturas.  
    


    while (WindowShouldClose() == false) {
        

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTextureEx(background, (Vector2){ x, y }, 0.0f, escalabackground, WHITE);
        DrawTextureEx(botaoplay, (Vector2){ x + 365, y + 165 }, 0.0f, 0.2f, WHITE); // desenhando o background e o botao play na tela.
        DrawTextureEx(botaoleaderboard, (Vector2){ x + 365, y + 310 }, 0.0f, 0.2f, WHITE); // desenhando o botao leaderboard na tela.
        DrawTextureEx(botaosair, (Vector2){ x + 365, y + 455 }, 0.0f, 0.2f, WHITE); // desenhando o botao sair na tela.
        EndDrawing();
    }
    {
        /* code */
    }
    
    
    
    
    return 0;
}