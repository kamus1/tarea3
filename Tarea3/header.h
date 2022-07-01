#include<fstream>
#include<iostream>
using namespace std;

struct NodoGrafo
{
    int key;
    string descripcion;
    Adyacencia *adyacencia;
    NodoGrafo *siguiente;
};

struct Adyacencia
{
    int opcion;
    string descripcion;
    NodoGrafo* camino;
    Adyacencia* siguiente;
};

//Funciones
NodoGrafo* crearGrafo();
