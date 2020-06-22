//
//  Episodio.h
//  proyectoPOO
//
//  Created by Diego Solis on 6/21/20.
//  Copyright © 2020 Diego Solis. All rights reserved.
//

#ifndef Episodio_h
#define Episodio_h

#include "Video.h"

class Episodio: public Video {
public:
    Episodio();
    Episodio(int ident, int duracion, string genero, int calificacion, string nombre, int year, string director, string nomSerie, int numEpisodio, int numTemporada);
    void setNombreSerie(string nomSerie) {this-> nomSerie = nomSerie;}
    string getNombreSerie() {return nomSerie;}
    void setNumeroEpisodio(int numEpisodio) {this-> numEpisodio = numEpisodio;}
    int getNumeroEpisodio() {return numEpisodio;}
    void setNumeroTemporada(int numTemporada) {this-> numTemporada = numTemporada;}
    int getNumeroTemporada() {return numTemporada;}
    void muestra();
    void muestraEpisodio();
private:
    int numEpisodio, numTemporada;
    string nomSerie;
};

Episodio::Episodio(): Video() {
    nomSerie = "-";
    numEpisodio = 0;
    numTemporada = 0;
}

Episodio::Episodio(int ident, int duracion, string genero, int calificacion, string nombre, int year, string director, string nomSerie, int numEpisodio, int numTemporada): Video(ident, duracion, genero, calificacion, nombre, year, director) {
    this-> nomSerie = nomSerie;
    this-> numEpisodio = numEpisodio;
    this-> numTemporada = numTemporada;
}

void Episodio::muestra() {
    cout << "id: " << ident << "\nNombre Serie: "  << nomSerie << "\nDuración en minutos: " << duracion << "\nCalificación: " << calificacion << "\nNombre episodio: " << nombre << "\nDirector: " << director << "\nNúmero Episodio: E" << numEpisodio << "\nNúmero de Temporada: T" << numTemporada << "\n------------------------------------------\n";
}

void Episodio::muestraEpisodio() {
    cout << "id: " << ident << "Nombre episodio: " << nombre << "\nCalificación: " << calificacion << "\n------------------------------------------\n";
}

#endif /* Episodio_h */

