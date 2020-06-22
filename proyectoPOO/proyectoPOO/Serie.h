//
//  Serie.h
//  proyectoPOO
//
//  Created by Diego Solis on 6/21/20.
//  Copyright © 2020 Diego Solis. All rights reserved.
//

#ifndef Serie_h
#define Serie_h

#include "Temporada.h"

class Serie {
public:
    Serie();
    Serie(int idSerie, string nombreSerie, int cantTemporadas);
    void setNombre(string nombreSerie) {this-> nombreSerie = nombreSerie;}
    string getNombre() {return nombreSerie;}
    void setIdSerie(int idSerie) {this-> idSerie = idSerie;}
    int getIdSerie() {return idSerie;}
    void agregarTemporada(Temporada nuevaTemp);
    void setCantTemporadas(int cantTemporadas) { this-> cantTemporadas = cantTemporadas;}
    int getCantTemporadas() {return cantTemporadas;}
    void muestra();
    void muestraEpisodiosCalif();
    
private:
    string nombreSerie;
    Temporada arrTemporadas[3];
    int cantTemporadas, idSerie;
    int contadorTemp = 0;
};

Serie::Serie() {
    nombreSerie = "-";
}

Serie::Serie(int idSerie, string nombreSerie, int cantTemporadas) {
    this-> nombreSerie = nombreSerie;
    this-> idSerie = idSerie;
    this-> cantTemporadas = cantTemporadas;
}

void Serie::agregarTemporada(Temporada nuevaTemp) {
    arrTemporadas[contadorTemp++] = nuevaTemp;
}

void Serie::muestra() {
    cout << "id: " << idSerie << "\nNombre serie: " << nombreSerie << "\nCantidad de temporadas: " << cantTemporadas <<  "\n------------------------------------------\n";
}

void Serie::muestraEpisodiosCalif() {
    for (int i = 0; i < cantTemporadas; i++) {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~Temporada " << i + 1 << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        arrTemporadas[i].muestra();
        }
}


#endif /* Serie_h */
