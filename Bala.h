#ifndef BALA_H_INCLUDED
#define BALA_H_INCLUDED
#include <allegro.h>
#include "Enemigo.h"
#include "Escudos.h"
#include "Nave.h"

/*Creamos la estructura que tendra la bala por ejemplo las coordenadas y la anchura*/
struct Bala{
    int x , y;
    int dx , dy;


bool choque(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);

bool crear_bala(int& n_disparos, const int max_disparos, struct Bala disparos[],
                const int X, const int Y ,const int dy);


void pintar_bala(int& n_disparos, const int max_disparos, struct Bala disparos[],
                 BITMAP* buffer, BITMAP* bala, int ancho, int alto);

void eliminar(struct Bala disparos[], int& nDiparos, int cont);
void elimina_bala(int& n_disparos, const int max_disparos, struct Bala disparos[],
                  const int ANCHO, const int ALTO);
bool eliminar_bala_choque(struct NAVE& n, struct Enemigo& e, Bala b[]);
bool eliminar_bala_choque(struct Enemigo& n, struct NAVE& e, Bala b[]);
void eliminar_bala_escudo(struct NAVE& n, struct Escudos ES[], Bala b[]);
void eliminar_bala_escudo(struct Enemigo& n, struct Escudos ES[], Bala b[]);

};
#endif // BALA_H_INCLUDED
