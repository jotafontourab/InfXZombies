#include <raylib.h>
#include <stdio.h>

typedef enum GameScreen { MENU = 0, JOGO, LEADERBOARD, FECHAR } GameScreen;


int main(void){
    
    InitWindow(800, 600, "Hello Raylib");
    GameScreen currentScreen = MENU;// Definindo a tela atual como MENU

    int btnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    bool btnAction = false;         // Button action should be activated

    Vector2 mousePoint = { 0.0f, 0.0f }; 

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
    UnloadImage(imagebotaosair); // descarregando as imagens, pois ja foram carregadas como texturas.
    Rectangle playBounds = {+ 365, + 165, botaoplay.width * 0.2f, botaoplay.height * 0.2f }; // Definindo os limites do botao play

    while (WindowShouldClose() == false) {
        
        // Update de telas
        switch (currentScreen)
        {
            case MENU:
            {
                mousePoint = GetMousePosition();
                btnAction = false;

        // Check button state
        if (CheckCollisionPointRec(mousePoint, playBounds))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
            else btnState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
        }
        else btnState = 0;
        if (btnAction){
            // Change to JOGO screen
            currentScreen = JOGO;
        }
            } break;
            case JOGO:
            {
                // TODO: Update TITLE screen variables here!

                // Press enter to change to GAMEPLAY screen
           
            } break;
            case LEADERBOARD:
            {
                // TODO: Update GAMEPLAY screen variables here!

                // Press enter to change to ENDING screen
               
            } break;
            case FECHAR:
            {
                // TODO: Update ENDING screen variables here!

                // Press enter to return to TITLE screen
              
            } break;
            default: break;
        }

        // Draw
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
         switch(currentScreen)
            {
                case MENU:
                {
                    DrawTextureEx(background, (Vector2){ x, y }, 0.0f, escalabackground, WHITE);
                    DrawTextureEx(botaoplay, (Vector2){ x + 365, y + 165 }, 0.0f, 0.2f, WHITE); // desenhando o background e o botao play na tela.
                    DrawTextureEx(botaoleaderboard, (Vector2){ x + 365, y + 310 }, 0.0f, 0.2f, WHITE); // desenhando o botao leaderboard na tela.
                    DrawTextureEx(botaosair, (Vector2){ x + 365, y + 455 }, 0.0f, 0.2f, WHITE); // desenhando o botao sair na tela.
        

                } break;
                case JOGO:
                {
                    // TODO: Draw TITLE screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
                    DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
                    DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);

                } break;
                case LEADERBOARD:
                {
                    // TODO: Draw GAMEPLAY screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
                    DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
                    DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);

                } break;
                case FECHAR:
                {
                    // TODO: Draw ENDING screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
                    DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
                    DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);

                } break;
                default: break;
            }

      
        
        EndDrawing();
    }
    {
        /* code */
    }
    
    
    
    
    return 0;
}