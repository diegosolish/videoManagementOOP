//
//  Video.h
//  proyectoPOO
//
//  Created by Diego Solis on 6/21/20.
//  Copyright © 2020 Diego Solis. All rights reserved.
//

#ifndef Video_h
#define Video_h

class Video {
public:
    Video();
    Video(int ident, int duracion, string genero, int calificacion, string nombre, int year, string director);
    
    void setId(int ident) {this-> ident = ident;}
    int getId() {return ident;}
    
    void setDuracion(int duracion) {this-> duracion = duracion;}
    int getDuracion() {return duracion;}
    
    void setGenero(string genero) {this-> genero = genero;}
    string getGenero() {return genero;}
    
    void setCalificacion(int calificacion) {this-> calificacion = calificacion;}
    int getCalificacion() {return calificacion;}
    
    void setNombre(string nombre) {this-> nombre = nombre;}
    string getNombre() {return nombre;}
    
    void setYear(int year) {this-> year = year;}
    int getYear() {return year;}
    
    void setDirector(string director) {this-> director = director;}
    string getDirector() {return director;}
    
    virtual void muestra() = 0;
    
protected:
    int ident, duracion, year;
    double calificacion;
    string genero, nombre, director;
};

Video::Video() {
    ident = 0;
    duracion = 0;
    year = 0;
    genero = "NaN";
    calificacion = 0;
    nombre = "NaN";
    director = "NaN";
}

Video::Video(int ident, int duracion, string genero, int calificacion, string nombre, int year, string director) {
    this-> ident = ident;
    this-> duracion = duracion;
    this-> year = year;
    this-> genero = genero;
    this-> calificacion = calificacion;
    this-> nombre = nombre;
    this-> director = director;
}

#endif /* Video_h */
