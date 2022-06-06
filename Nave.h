#ifndef NAVE_H_INCLUDED
#define NAVE_H_INCLUDED
#include <allegro.h>
#include "Escudos.h"
#include "Bala.h"

struct NAVE{
    int posNaveX;
    int posNaveY;
    int nDisparos;
    int max_disp;
    int tick;
    int ancho_b;
    int alto_b;
    int ancho_p;
    int alto_p;
    int direccion;
    int tipo;
    int vidas;


    BITMAP *imgNave;
    BITMAP *imgBala;
    BITMAP *imgExplosion;

    SAMPLE *disparo;
    SAMPLE *explosivo;


void construirNave(char* rutaNave, char* rutaBala, char* rutaDisparo, char* rutaExplosion, int anchoBala, int altoBala, int anchoPersonaje,
                       int altoPersonaje, int posNavX, int posNavY, int direccionBala, int tip, int vid);

void pintar(BITMAP* buffer, int ix, int iy);
void mover();
bool temporizador();
void disparar(struct Bala disparos[], BITMAP *buffer);
void explosion(BITMAP* buffer, BITMAP *fondo, bool& muerto);
void crear_bala_jugador(struct Bala disparos[]);

};
