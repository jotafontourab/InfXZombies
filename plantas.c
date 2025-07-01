#include "plantas.h"
#include "zumbis.h"

Projetil projeteis[MAX_PROJETEIS];


void InitPlantas(void) {
    for (int i = 0; i < MAX_PROJETEIS; i++) {
        projeteis[i].ativo = false;
    }

}


void CriarProjetil(Vector2 posInicial, int linha, int dano, float velocidade) {
    for (int i = 0; i < MAX_PROJETEIS; i++) {
        if (!projeteis[i].ativo) {
            projeteis[i].posicao = posInicial;
            projeteis[i].velocidade = velocidade;
            projeteis[i].linha = linha;
            projeteis[i].dano = dano;
            projeteis[i].ativo = true;
            break;
        }
    }
}

void DesenharProjeteis(Texture2D projetil) {
    for (int i = 0; i < MAX_PROJETEIS; i++) {
        if (projeteis[i].ativo) {
            DrawTexture(projetil, projeteis[i].posicao.x, projeteis[i].posicao.y, WHITE);
        }
    }
}

void AtualizarProjeteis(float delta, Texture2D zumbi) {
    for (int i = 0; i < MAX_PROJETEIS; i++) {
        if (projeteis[i].ativo) {
            projeteis[i].posicao.x += projeteis[i].velocidade * delta;
            
            if (projeteis[i].posicao.x > GetScreenWidth()) {
                projeteis[i].ativo = false;
                continue;
            }
            
            for (int z = 0; z < NUM_MAXDEZUMBIS; z++) {
                if (zumbis[z].ativo && 
                    zumbis[z].linha == projeteis[i].linha &&
                    CheckCollisionPointRec(projeteis[i].posicao, 
                        (Rectangle){zumbis[z].pos.x, zumbis[z].pos.y, 65, 88})) {
                    
                    zumbis[z].vida -= projeteis[i].dano;
                    projeteis[i].ativo = false;
                    
                    if (zumbis[z].vida <= 0) {
                        zumbis[z].ativo = false;
                        pontuacao += 100; // Incrementa a pontuação ao eliminar um zumbi
                    }
                    break;
                }
            }
        }
    }
}