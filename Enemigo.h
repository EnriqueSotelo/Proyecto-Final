#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED
#include <allegro.h>
#include "Bala.h"
#include "Escudos.h"
#include "portada.h"


struct Enemigo{
    int posNaveX,posNaveY;
    int nDisparos, max_disp;
    int tick;
    int ancho_b, alto_b;
    int ancho_p, alto_p;
    int direccion;
    int tipo,vidas;


    BITMAP* imgNave;
    BITMAP* imgBala;
    BITMAP* imgExplosion;

    SAMPLE *disparo;
    SAMPLE *escudo;
    SAMPLE *explosivo;

    void construirNave(char* rutaNave, char* rutaBala, char* rutaDisparo, char* rutaEscudo, char* rutaExplosion,
                       int anchoBala, int altoBala, int anchoPersonaje, int altoPersonaje, int posNavX,
                       int posNavY, int direccionBala, int tip, int vid);


    void pintar(BITMAP* buffer, int ix, int iy);
    bool temporizador();
    void disparar(struct Bala disparos[], BITMAP *buffer);

    void explosion(BITMAP* buffer);
    void moverEnemigos(Enemigo e[], int& mov, int& dir);
    void insertarEnemigos(Enemigo e[], int& vidas);
    void pintarEnemigo(Enemigo e[], BITMAP * buffer, int mov);


};
