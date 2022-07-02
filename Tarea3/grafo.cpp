#include "header.h"

NodoGrafo* crearGrafo(string texto){
    NodoGrafo* nodo_inicial = new NodoGrafo;
    nodo_inicial ->key = numero_de_sala;
    numero_de_sala++;
    nodo_inicial -> descripcion = texto;
    nodo_inicial -> adyacencia = NULL;
    nodo_inicial -> siguiente = NULL;
    return nodo_inicial;
}

NodoGrafo* addNodo(string texto, NodoGrafo* &tail){
    NodoGrafo* NuevoNodo = new NodoGrafo;
    NuevoNodo ->key = numero_de_sala;
    numero_de_sala++;
    NuevoNodo ->descripcion = texto;
    NuevoNodo ->adyacencia = NULL;
    NuevoNodo ->siguiente = NULL;
    tail ->siguiente = NuevoNodo;
    tail = NuevoNodo;
    return NuevoNodo; 
};

void addAdyacencia(int opcion, string texto, Adyacencia* inicio, NodoGrafo* destino){
    Adyacencia* nuevo = new Adyacencia;
    nuevo ->opcion = opcion;
    nuevo ->descripcion = texto;
    nuevo ->camino = destino;
    nuevo->siguiente = NULL;
    while (inicio ->siguiente != NULL)
    {
        inicio ->siguiente = inicio->siguiente->siguiente;
    }
    inicio ->siguiente = nuevo;
};

