//
//  main.cpp
//  proyectoPOO
//
//  Created by Diego Solis on 6/21/20.
//  Copyright © 2020 Diego Solis. All rights reserved.
//

#include <iostream>
using namespace std;

#include <fstream>
#include "Serie.h"
#include "Pelicula.h"

void cargaArchivoVideos(Video *arrVideos[], int  &cantEpisodios, int &cantPeliculas, int &cantVideos) {
    // Carga los datos del archivo 'datosVideos.txt'
    char tipoVideo;
    int idP, duracionP, yearP, idE, duracionE, yearE, numEpisodio, numTemp;
    double calificacionP,  calificacionE;
    string generoP, nombreP, directorP, premioOscarP, generoE, nombreE, directorE, nomEp;
    
    ifstream archivoVideos;
    archivoVideos.open("datosVideos.txt");
    while(archivoVideos >> tipoVideo) {
        if (tipoVideo == 'p') {
            archivoVideos >> idP >> duracionP >> generoP >> calificacionP >> nombreP >> yearP >> directorP >> premioOscarP;
            arrVideos[cantVideos++] = new Pelicula(idP, duracionP, generoP, calificacionP, nombreP, yearP, directorP, premioOscarP);
            
        } else if (tipoVideo == 'e'){
            archivoVideos >> idE >> duracionE >> generoE >> calificacionE >> nombreE >> yearE >> directorE >> nomEp >> numEpisodio >> numTemp;
            arrVideos[cantVideos++] = new Episodio(idE, duracionE, generoE, calificacionE, nombreE, yearE, directorE, nomEp, numEpisodio, numTemp);
        }
    }
    archivoVideos.close();
}

void cargaArchivoSerie(Serie *arrSeries[], int &cantSeries){
    // Carga datos de archivo 'datosSeries.txt'
    int idSerie, cantTemporadas;
    string nombreSerie;
    
    ifstream archivoSeries;
    archivoSeries.open("datosSeries.txt");
    
    while(archivoSeries >> idSerie >> nombreSerie >> cantTemporadas)
        arrSeries[cantSeries++] = new Serie(idSerie, nombreSerie, cantTemporadas);
    
    archivoSeries.close();
}

void organizaDatos(Video *arrVideos[], int cantVideos, int cantEpisodios, Serie *arrSeries[], int cantSeries) {
    // Acomoda los episodios en su temporada y serie correspondiente
    Episodio episodioNormal;
    Episodio *epActual;
    Temporada temporadaLocal;
    int contadorIndependiente = 0;
    for(int contadorSeries = 0; contadorSeries < cantSeries; contadorSeries++) { // Recorre los nombres de series
        for(int contTemporadas = 0; contTemporadas < 2; contTemporadas++) { // Recorre Temporadas
            // Busca la cantidad de temporadas de la serie actual
            temporadaLocal.setNumeroTemporada(contTemporadas);
            for (int contadorEpisodios = 0; contadorEpisodios < cantVideos; contadorEpisodios++) { // Recorre el arreglo episodios
                if (typeid(*arrVideos[contadorEpisodios]) == typeid(Episodio)) {
                    epActual = (Episodio*) arrVideos[contadorEpisodios];
                    if(epActual->getNombreSerie() == arrSeries[contadorSeries]->getNombre() && epActual->getNumeroTemporada() == contTemporadas + 1) {
                        temporadaLocal.agregarEpisodio(*epActual, contadorIndependiente); // Se agrega episodio a temporada
                        contadorIndependiente++;
                    }
                }
            }
            arrSeries[contadorSeries]->agregarTemporada(temporadaLocal); // Se agrega temporada a serie
            contadorIndependiente = 0;
        }
    }
}

void muestraPeliculas(Video *arrVideos[], int cantVideos) {
    // Muestra las películas registradas
    Pelicula *peliActual;
    for (int cont = 0; cont < cantVideos; cont++) {
        if (typeid(*arrVideos[cont]) == typeid(Pelicula)) {
            peliActual = (Pelicula*) arrVideos[cont];
            peliActual->muestra();
        }
    }
}

void muestraSeries(Serie *arrSeries[], int cantSeries) {
    // Muestra las series registradas
    for (int cont = 0; cont < cantSeries; cont++)
        arrSeries[cont]->muestra();
}

void muestraVideosCalif(Video *arrVideos[], int cantVideos) {
    // Muestra todos los videos con una calificación en específico
    Pelicula *peliActual;
    Episodio *epActual;
    int califUsuario;
    cout << "Teclee un número del 1 al 5: ";
    cin >> califUsuario;
    
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~Episodios~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
    for (int contEp = 0; contEp < cantVideos; contEp++) {
        if (typeid(*arrVideos[contEp]) == typeid(Episodio) && arrVideos[contEp]->getCalificacion() == califUsuario){
            epActual = (Episodio*) arrVideos[contEp];
            epActual->muestra();
        }
    }
    
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~Películas~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
    for (int contEp = 0; contEp < cantVideos; contEp++) {
        if (typeid(*arrVideos[contEp]) == typeid(Pelicula) && arrVideos[contEp]->getCalificacion() == califUsuario){
            peliActual = (Pelicula*) arrVideos[contEp];
            peliActual->muestra();
        }
    }
}

void muestraVideoGenero(Video *arrVideos[], int cantVideos) {
    // Muestra todos los videos de un género en específico
    Pelicula *peliActual;
    Episodio *epActual;
    
    string arrGeneros[5] = {"Accion_Y_Aventura", "Infantil", "Drama", "Ciencia_Ficcion", "Comedia"};
    int opcionUsuario, contadorFinal = 0;
    
    cout << "Ingresa la opción que desees" << endl;
    cout << "1) Acción y Aventura \n" << "2) Infantil\n" << "3) Drama\n" << "4) Ciencia Ficción\n" << "5) Comedia\n" << "Opción: ";
    cin >> opcionUsuario;
    cout << endl;
    
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~Episodios~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
    for (int contEp = 0; contEp < cantVideos; contEp++) {
        if (typeid(*arrVideos[contEp]) == typeid(Episodio) && arrVideos[contEp]->getGenero() == arrGeneros[opcionUsuario-1]) {
            epActual = (Episodio*) arrVideos[contEp];
            epActual->muestra();
            contadorFinal++;
        }
    }
    
    if (contadorFinal == 0)
        cout << "No hay episodios registrados con el género ingresado. \n";
    contadorFinal = 0;
    
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~Películas~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
    for (int contPeli = 0; contPeli < cantVideos; contPeli++) {
        if (typeid(*arrVideos[contPeli]) == typeid(Pelicula) && arrVideos[contPeli]->getGenero() == arrGeneros[opcionUsuario-1]) {
            peliActual = (Pelicula*) arrVideos[contPeli];
            peliActual->muestra();
            contadorFinal++;
        }
    }
    if (contadorFinal == 0)
        cout << "No hay episodios registrados con el género ingresado. \n";
}

void muestraPeliculasCalif(Video *arrVideos[], int cantVideos) {
    // Muestra las películas con una calificación determinada
    Pelicula *peliActual;
    int calificacionUsuario;
    
    cout << "Ingrese un número del 1 al 5: ";
    cin >> calificacionUsuario;
    cout << endl;
    
    for (int contPeli = 0; contPeli < cantVideos; contPeli++) {
        if (typeid(*arrVideos[contPeli]) == typeid(Pelicula) && arrVideos[contPeli]->getCalificacion() == calificacionUsuario) {
            peliActual = (Pelicula*) arrVideos[contPeli];
            peliActual->muestra();
        }
    }
}

void calificacionEpisodioSerie(Serie *arrSeries[], int cantSeries) {
    int opcionSerie;
    cout << "que serie desea?" << endl;
    for (int i = 0; i < cantSeries; i++) // Recorre arreglo de series
        cout << i + 1 << ") " << arrSeries[i]->getNombre() << endl;
    cout << "Opción: ";
    cin >> opcionSerie;
    arrSeries[opcionSerie - 1]->muestraEpisodiosCalif(); // Muestra los episodios de una serie en específico
    cout << endl;
}

void entradaUsuario(Video *arrVideos[], int cantVideos, Serie *arrSeries[], int cantSeries){
    int opcion;
    cout << "Bienvenid@ al mejor servicio de streaming, para continuar, teclee la opción que desee" << endl;
    do {
        cout << endl;
        cout << "1) Mostrar lista de películas" << endl; // Lista
        cout << "2) Mostrar la lista de series" << endl; // Lista
        cout << "3) Mostrar los videos en general con una cierta calificación" << endl; // Lista
        cout << "4) Mostrar los videos en general de un cierto género" << endl; // Lista
        cout << "5) Mostrar los episodios de una determinada serie con sus calificaciones" << endl; // Pendiente
        cout << "6) Mostrar las películas con cierta calificación" << endl; // Lista;
        cout << "0) Salir" << endl;
        cout << "Teclee opción: ";
        cin >> opcion;
        cout << endl;
        
        switch (opcion) {
            case 1:
                muestraPeliculas(arrVideos, cantVideos);
                break;
            case 2:
                muestraSeries(arrSeries, cantSeries);
                break;
            case 3:
                muestraVideosCalif(arrVideos, cantVideos);
                break;
            case 4:
                muestraVideoGenero(arrVideos, cantVideos);
                break;
            case 5:
                calificacionEpisodioSerie(arrSeries, cantSeries);
                break;
            case 6:
                muestraPeliculasCalif(arrVideos, cantVideos);
                break;
            case 0:
                break;
        }
    } while(opcion != 0);
}

int main() {
    Video *arrVideos[70];
    int cantVideos = 0, cantPeliculas = 0, cantEpisodios = 0;
    
    Serie *arrSeries[5];
    int cantSeries = 0;
    
    cargaArchivoSerie(arrSeries, cantSeries);
    cargaArchivoVideos(arrVideos, cantEpisodios, cantPeliculas, cantVideos);
    organizaDatos(arrVideos, cantVideos, cantEpisodios, arrSeries, cantSeries); // Acomoda los episodios en temporadas y series
    entradaUsuario(arrVideos, cantVideos, arrSeries, cantSeries);
    return 0;
}
