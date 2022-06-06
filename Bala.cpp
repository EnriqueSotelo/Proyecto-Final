#include "Enemigo.h"

void Enemigo::construirNave(char* rutaNave, char* rutaBala, char* rutaDisparo, char* rutaEscudo, char* rutaExplosion, int anchoBala, int altoBala,
                                int anchoPersonaje, int altoPersonaje, int posNavX, int posNavY, int direccionBala, int tip, int vid){

    posNaveX = posNavX;
    posNaveY = posNavY;
    max_disp = 2;
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
    escudo = load_wav(rutaEscudo);
    explosivo = load_wav(rutaExplosion);
}


void Enemigo::pintar(BITMAP* buffer, int ix, int iy){
    masked_blit(imgNave, buffer, ix * ancho_p, iy * alto_p , posNaveX, posNaveY, ancho_p, alto_p);
}


bool Enemigo::temporizador(){
    tick++;
    if (tick == 5){
        tick = 0;
        return true;
    }
    else {
        return false;
    }
}



void Enemigo::disparar(struct Bala disparos[], BITMAP* buffer){
    if (tipo)
    if (crear_bala(nDisparos, max_disp, disparos, posNaveX, posNaveY, direccion)){
        play_sample(disparo, 175, 127, 1000, 0);
    }
    pintar_bala(nDisparos, max_disp, disparos, buffer, imgBala, ancho_b, alto_b);
    elimina_bala(nDisparos, max_disp, disparos, 600, 600);

}

void Enemigo::explosion(BITMAP* buffer){
    if (this->vidas == 0){
        play_sample(escudo, 127, 127, 1000, 0);
    }
    else {
        play_sample(explosivo, 127, 127, 1000, 0);
    }
    BITMAP *expMedio = create_bitmap(25, 20);
    clear_to_color(expMedio, 0x000000);
    blit(expMedio, buffer, 0, 0, posNaveX, posNaveY, 25, 20);
    masked_blit(imgExplosion, buffer, 0, 0, posNaveX - 10, posNaveY, 41, 34);
}

void Enemigo::moverEnemigos(Enemigo e[], int& mov, int& dir){
    for (int i = 0; i < 55; i++) {
        e[i].posNaveX += dir;
    }
    if (++mov == 2){
        mov = 0;
    }
   if (bordeTablero(e, dir)){
        for (int i = 0; i < 55; i++){
            e[i].posNaveY += 10;
        }
    }
}

void Enemigo::insertarEnemigos(Enemigo e[], int& vidas){
    int indice = -1;
    int tipo = 0;
    for (int i = 0; i < 5; i++){
        tipo++;
        if (tipo == 4){

            tipo = 1;
        }
        for (int j = 0; j < 11; j++){
            indice++;
            e[indice].construirNave((char*)"Recursos/enemigos.bmp", (char*)"Recursos/Bala_enem.bmp",
                                    (char*)"Recursos/soundEffects_Disparo.wav",  (char*)"Recursos/soundEffects_Explosion.wav",
                                    (char*)"Recursos/soundEffects_ExplosionShield.wav", 6, 12, 25, 20, 140 + j * 30, 130 + i * 24, 8, tipo, vidas);
        }
    }
}


void Enemigo::pintarEnemigo(Enemigo e[], BITMAP * buffer, int mov){
    int indice = -1;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 11; j++){
            indice++;
            if (e[indice].vidas > 0){
                e[indice].pintar(buffer, mov, e[indice].tipo - 1);
            }
        }
    }
}
