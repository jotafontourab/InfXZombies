#include <raylib.h>
#include "menu.h"
#include <stdio.h>
#include "fechar.h"

typedef enum GameScreen { MENU = 0, JOGO, LEADERBOARD, FECHAR } GameScreen;

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


int main(void){
    
    InitWindow(800, 600, "Hello Raylib");
    GameScreen currentScreen = MENU;// Definindo a tela atual como MENU

    int btnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED | verificar mouse (documentacao raylib)
    bool btnAction = false;         // Button action should be activated | verificar se botao pressionado - mouse (documentacao raylib)

    Vector2 mousePoint = { 0.0f, 0.0f }; 

    int framesCounter = 0;

    int janeladevefechar = 0;

    SetTargetFPS(60);

    int screenWidth = 800;
    int screenHeight = 600;
    float escalabackground = 1.07f; // tive que criar uma escala para que o background ficasse do tamanho certo.

    Image imagebackground = LoadImage("sprites/menu-background.png");
    Image imagebotaoplay = LoadImage("sprites/play-button.png");
    Image imagebotaoleaderboard = LoadImage("sprites/leaderboard-button.png");
    Image imagebotaosair = LoadImage("sprites/exit-button.png");
    Image imagegamebackground = LoadImage("sprites/background.png");
    Image imagebotaomenugenerico = LoadImage("sprites/menu-button.png");
    
    ImageResize(&imagebackground, 800, 600);
    ImageResize(&imagegamebackground, 800, 600);

    Texture2D background = LoadTextureFromImage(imagebackground); // carregando a imagem do background como textura.
    Texture2D botaoplay = LoadTextureFromImage(imagebotaoplay); // carregando a imagem do botao play como textura.
    Texture2D botaoleaderboard = LoadTextureFromImage(imagebotaoleaderboard); // carregando a imagem do botao leaderboard como textura.
    Texture2D botaosair = LoadTextureFromImage(imagebotaosair); // carregando a imagem do botao sair como textura.
    Texture2D gamebackground = LoadTextureFromImage(imagegamebackground);
    Texture2D botaomenugenerico = LoadTextureFromImage(imagebotaomenugenerico); // carregando a imagem do botao menu generico como textura.

    float x = (screenWidth - background.width -110) / 2.0f;
    float y = (screenHeight - background.height) / 2.0f;  // apliquei a centralizacao do background
  //  UnloadImage(imagebackground); 
  //  UnloadImage(imagebotaoplay); 
   // UnloadImage(imagebotaoleaderboard);
   // UnloadImage(imagebotaosair); 
  //  UnloadImage(imagegamebackground); 
   // UnloadImage(imagebotaomenugenerico);    // descarregando as imagens, pois ja foram carregadas como texturas.
    Rectangle playBounds = {+ 365, + 165, botaoplay.width * 0.2f, botaoplay.height * 0.2f }; // definindo os limites do botao play
    Rectangle leaderboardBounds = { + 365, + 310, botaoleaderboard.width * 0.2f, botaoleaderboard.height * 0.2f }; // definindo os limites do botao leaderboard
    Rectangle exitBounds = { + 365, + 455, botaosair.width * 0.2f, botaosair.height * 0.2f }; // definindo os limites do botao sair
    Rectangle saidaSimBounds = { + 280, + 320, botaomenugenerico.width * 0.1f, botaomenugenerico.height * 0.3f }; // definindo os limites do botao sair sim
    Rectangle saidaNaoBounds = { + 400, + 320, botaomenugenerico.width * 0.1f, botaomenugenerico.height * 0.3f }; // definindo os limites do botao sair nao
    
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
                if (btnAction){
                // Change to JOGO screen
                currentScreen = JOGO;
                }
            }
       
            if(CheckCollisionPointRec(mousePoint, leaderboardBounds))
            {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
                else btnState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
            if (btnAction){
            // Change to JOGO screen
            currentScreen = LEADERBOARD;
        }
    }
            if(CheckCollisionPointRec(mousePoint, exitBounds))
            {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
                else btnState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
            if (btnAction){
            // Change to JOGO screen
            currentScreen = FECHAR;
        }
    }
        else btnState = 0;
        
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
            framesCounter++;
            mousePoint = GetMousePosition();
            btnAction = false;

            if(CheckCollisionPointRec(mousePoint, saidaSimBounds))
            {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
                else btnState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
            if (btnAction){
             janeladevefechar=1;

             if(janeladevefechar==1){
                EndDrawing();
                CloseWindow(); 
                return 0; // aqui eu fecho a janela, pois o usuario quer sair do jogo.
            }// aqui eu fecho a janela, pois o usuario quer sair do jogo.
        }
    }
        else if(CheckCollisionPointRec(mousePoint, saidaNaoBounds))
            {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
                else btnState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
            if (btnAction){
            // Change to JOGO screen
            currentScreen = MENU; // aqui eu volto para o menu, pois o usuario nao quer sair do jogo.
        }
    }
             // funcao que vem do exit.c
              
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
                   
                desenhaMenu(background, botaoplay, botaoleaderboard, botaosair, x, y, escalabackground); //funcao que vem do menu.c

                } break;
                case JOGO:
                {
                    
                   DrawTextureEx(gamebackground, (Vector2){ x, y }, 0.0f, escalabackground, WHITE);

                } break;
                case LEADERBOARD:
                {
                    // TODO: Draw GAMEPLAY screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
                    DrawText("LEADERBOARD TELA", 20, 20, 40, MAROON);
                    DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);

                } break;
                case FECHAR:
                {
                   desenhaSair(background, botaomenugenerico, x, y, escalabackground);

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