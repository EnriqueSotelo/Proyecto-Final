#include "portada.h"
#include <allegro.h>

void PORTADA(BITMAP* portada){
    int parpadeo = 0,y = 0,cont = 0;
    bool salida = false,carga = false;

while (!salida){
        if (parpadeo < 25){
            blit(portada, screen, 0, y, 0, 100, 600, 400);
        }
        else {
            blit(portada, screen, 600, y, 0, 100, 600, 400);
        }
        if (key[KEY_ENTER]){
            y = 400;
            carga= true;
        }
        if (carga) {
            cont++;
        }
        if (cont > 400){
            salida = true;
        }
        rest(5);
        if (++parpadeo == 50){
            parpadeo = 0;
        }
    }
    clear_to_color(screen, 0x000000);
}

void imprimir_fondo(BITMAP* fondo, BITMAP* buffer){
    masked_blit(fondo, buffer,0,0,0,0,600,600);

}
