#include "sois.h"

#define MAX_SOIS 10
#define INTERVALO_SOL 4.0f

static Sol sois[MAX_SOIS];
static Texture2D spriteSol;
static float tempoSois = 0.0f;
static int contadorSois = 0;

void InitSois(void) {
    spriteSol = LoadTexture("sun.png");
    for (int i = 0; i < MAX_SOIS; i++) sois[i].ativo = false;
}

static void gerarSol(void) {
    for (int i = 0; i < MAX_SOIS; i++) {
        if (sois[i].ativo != true) {
            sois[i].posicao = (Vector2){ GetRandomValue(90, 600), GetRandomValue(110, 400) };
            sois[i].tempoVida = 6.0f;
            sois[i].ativo = true;
            break;
        }
    }
}

void AtualizaSois(void) {
    tempoSois += GetFrameTime();
    if (tempoSois >= INTERVALO_SOL) {
        gerarSol();
        tempoSois = 0.0f;
    }

    Vector2 mouse = GetMousePosition();
    for (int i = 0; i < MAX_SOIS; i++) {
        if (!sois[i].ativo) continue;

        Rectangle area = { sois[i].posicao.x, sois[i].posicao.y, spriteSol.width, spriteSol.height };

        if (CheckCollisionPointRec(mouse, area) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            sois[i].ativo = false;
            contadorSois++;
        }

        sois[i].tempoVida -= GetFrameTime();
        if (sois[i].tempoVida <= 0.0f) sois[i].ativo = false;
    }
}

void DrawSois(void) {
    for (int i = 0; i < MAX_SOIS; i++) {
        if (sois[i].ativo) DrawTexture(spriteSol, sois[i].posicao.x, sois[i].posicao.y, WHITE);
    }
}

int SoisColetados(void) {
    return contadorSois;
}
