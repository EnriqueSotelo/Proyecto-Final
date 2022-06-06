#include "Nave.h"

void NAVE::construirNave(char* rutaNave, char* rutaBala, char* rutaDisparo, char* rutaExplosion, int anchoBala, int altoBala,int anchoPersonaje, int altoPersonaje,
                         int posNavX, int posNavY, int direccionBala, int tip, int vid){
    posNaveX = posNavX;
    posNaveY = posNavY;
    max_disp = 4;
    nDisparos = 0;
    tick = 0;
    ancho_b = anchoBala;
    alto_b = altoBala;
    ancho_p = anchoPersonaje;
    alto_p = altoPersonaje;
    direccion = direccionBala;
    tipo = tip;
    vidas = vid;

    imgNave = load_bitmap(rutaNave, NULL);
    imgBala = load_bitmap(rutaBala, NULL);
    imgExplosion = load_bitmap(rutaExplosion, NULL);
    disparo = load_wav(rutaDisparo);
    explosivo = load_wav(rutaExplosion);

}

void NAVE::pintar(BITMAP* buffer, int ix, int iy){
    masked_blit(imgNave, buffer, ix * ancho_p, iy * alto_p , posNaveX, posNaveY, ancho_p, alto_p);
}

void NAVE::mover(){
    if(key[KEY_LEFT]){
        posNaveX -= 5;
    }
    if (key[KEY_RIGHT]){
        posNaveX += 5;
    }
}

bool NAVE::temporizador(){
    tick++;
    if (tick == 5){
        tick = 0;
        return true;
    }
    else {
        return false;
    }
}

void NAVE::disparar(struct Bala disparos[], BITMAP* buffer){
   crear_bala(nDisparos, max_disp, disparos, posNaveX, posNaveY, direccion);
   pintar_bala(nDisparos, max_disp, disparos, buffer, imgBala, ancho_b, alto_b);
   elimina_bala(nDisparos, max_disp, disparos, 600, 600);
}

void NAVE::explosion(BITMAP* buffer, BITMAP* fondo, bool& muerto){
    play_sample(explosivo, 255, 127, 1000, 0);
    BITMAP *expMedio = create_bitmap(30, 20);
    clear_to_color(expMedio, 0x000000);
    for (int i = 0; i < 6; i++){
        for (int j = 1; j <= 2; j++){
            blit(expMedio, buffer, 0, 0, posNaveX, posNaveY, 30, 20);
            masked_blit(imgExplosion, buffer, j * 30, 0, posNaveX, posNaveY, 30, 20);
            blit(buffer, screen, 0, 0, 0, 0, 600, 600);
            rest(50);
        }
    }

    if (this->vidas == 0){
        muerto = true;
    }
}

void NAVE::crear_bala_jugador( struct Bala disparos[]){
    if (key[KEY_SPACE] && temporizador()){
        if (crear_bala(nDisparos, max_disp, disparos, posNaveX, posNaveY, direccion)){
            play_sample(disparo, 127, 127, 1000, 0);
        }
        rest(30);
    }
}
