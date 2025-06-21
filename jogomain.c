#include <raylib.h>
#include <stdio.h>

int main(void){
    
    InitWindow(800, 450, "Hello Raylib");
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    while (WindowShouldClose() == false) {
        

        //Organizacao de eventos

        //Atualizacao das posicoes

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawText("Hello Raylib!", 190, 200, 20, LIGHTGRAY);
        
        EndDrawing();
    }
    {
        /* code */
    }
    
    
    
    
    return 0;
}