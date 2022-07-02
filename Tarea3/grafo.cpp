#include<iostream>
#include "header.h"

int numero_de_sala = 1;

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
    tail->siguiente = NuevoNodo;
    tail = NuevoNodo;
    return NuevoNodo; 
}

void addAdyacencia(string texto, Adyacencia* inicio, NodoGrafo* destino){

    cout<<destino->key<<endl;


    int numAdyacencia = 0;
    Adyacencia* nuevo = new Adyacencia;

    nuevo->descripcion = texto;
    nuevo->camino = destino;
    nuevo->siguiente = NULL;
    while (inicio->siguiente != NULL)
    {
        // cout<<numAdyacencia<<endl;
        // cout<<texto<<endl;

        numAdyacencia++;
        inicio = inicio->siguiente;
    }

    nuevo->opcion = numAdyacencia;
    inicio->siguiente = nuevo;
}

void recorrerGrafo(NodoGrafo* inicio){
    NodoGrafo* aux = inicio;
    while(aux != NULL){
        // cout<<aux->key<<endl;
        cout<<aux->descripcion<<endl;

        Adyacencia* aux2 = aux->adyacencia;
        while(aux2 != NULL){
            cout<<aux2->opcion<<endl;
            cout<<aux2->descripcion<<endl;
            aux2 = aux2->siguiente;
        }

        aux = aux->siguiente;
    }
}