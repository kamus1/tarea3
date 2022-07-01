#include<fstream>
#include<iostream>
using namespace std;

int numero_de_sala = 1;

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
NodoGrafo* addNodo(int llave, string texto, NodoGrafo* &tail);
void addAdyacencia(int opcion, string texto);
