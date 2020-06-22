//
//  Temporada.h
//  proyectoPOO
//
//  Created by Diego Solis on 6/21/20.
//  Copyright © 2020 Diego Solis. All rights reserved.
//

#ifndef Temporada_h
#define Temporada_h

#include "Episodio.h"

class Temporada {
public:
    Temporada();
    Temporada(int numTemporada);
    void setNumeroTemporada(int numTemporada) {this-> numTemporada = numTemporada;}
    int getNumeroTemporada() {return numTemporada + 1;}
    void agregarEpisodio(Episodio nuevoEpisodio, int numTemporada);
    int getNumeroEpisodios() {return numeroEpisodio;}
    void setNumEpisodios(int cantEpisodios) {this-> cantEpisodios = cantEpisodios;}
    int getCantEpisodios() {return cantEpisodios;}
    void muestra();
private:
    Episodio arrEpisodios[10], nuevoEpisodio;
    int numeroEpisodio, numTemporada, cantEpisodios;
};

Temporada::Temporada() {
    numTemporada = 0;
}

Temporada::Temporada(int numTemporada) {
    this-> numTemporada = numTemporada;
}

void Temporada::agregarEpisodio(Episodio nuevoEpisodio, int numeroEpisodio) {
    arrEpisodios[numeroEpisodio] = nuevoEpisodio;
    cantEpisodios = numeroEpisodio + 1;
}

void Temporada::muestra() {
    for (int i = 0; i < cantEpisodios;  i++) {
        cout << "id: " << arrEpisodios[i].getId() << "\nNúmero Episodio: E" << arrEpisodios[i].getNumeroEpisodio() << "\nNombre episodio: "  << arrEpisodios[i].getNombre() << "\nDuración en minutos: " << arrEpisodios[i].getDuracion() << "\nDirector: " << arrEpisodios[i].getDirector() << "\n--------------------------------------\n";
    }
}

#endif /* Temporada_h */
