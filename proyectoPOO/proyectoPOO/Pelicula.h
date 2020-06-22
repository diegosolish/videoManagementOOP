//
//  Pelicula.h
//  proyectoPOO
//
//  Created by Diego Solis on 6/21/20.
//  Copyright © 2020 Diego Solis. All rights reserved.
//

#ifndef Pelicula_h
#define Pelicula_h

#include "Video.h"

class Pelicula: public Video {
public:
    Pelicula();
    Pelicula(int ident, int duracion, string genero, int calificacion, string nombre, int year, string director, string premioOscar);
    void setPremioOscar(string premioOscar) {this-> premioOscar = premioOscar;}
    string getPremioOscar() {return premioOscar;}
    void muestra();
    void muestraCalificacion();
    
private:
    string premioOscar;
};

Pelicula::Pelicula(): Video() {
    premioOscar = "false";
}

Pelicula::Pelicula(int ident, int duracion, string genero, int calificacion, string nombre, int year, string director, string premioOscar): Video(ident, duracion, genero, calificacion, nombre, year, director) {
    this-> premioOscar = premioOscar;
}

void Pelicula::muestra() {
    cout << "id: " << ident << "\nNombre de Película: " << nombre << "\nCalificación: " << calificacion << "\nAño de Estreno: " << year << "\nDirector: " << director << "\nDuración en minutos: " << duracion << "\nPremios: ";
    
    if (premioOscar == "true")
        cout <<"Sí ha ganado un premio Oscar" << "\n------------------------------------------\n";
    else {
        cout <<"No ha ganado un premio Oscar" << "\n------------------------------------------\n";
    }
}

void Pelicula::muestraCalificacion() {
    cout << "id: " << ident << "\nNombre de película: " << nombre << "\nCalificación: " << calificacion << "\n------------------------------------------\n";
}
#endif /* Pelicula_h */
