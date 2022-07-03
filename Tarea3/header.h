#include<fstream>
#include<iostream>
using namespace std;

struct Adyacencia;
struct NodoGrafo;

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
NodoGrafo* crearGrafo(string texto);
NodoGrafo* addNodo(string texto, NodoGrafo* &tail);
void addAdyacencia(string texto, Adyacencia* inicio, NodoGrafo* destino);
void recorrerGrafo(NodoGrafo* inicio);