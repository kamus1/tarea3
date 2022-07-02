#include<fstream>
#include<iostream>
using namespace std;

int numero_de_sala = 1;

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
void addAdyacencia(int opcion, string texto, Adyacencia* inicio, NodoGrafo* destino);
