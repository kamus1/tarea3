#include "header.h"

NodoGrafo* crearGrafo(){
    NodoGrafo* nodo_inicial = new NodoGrafo;
    nodo_inicial ->key = 1;
    nodo_inicial -> descripcion = "";
    nodo_inicial -> adyacencia = NULL;
    nodo_inicial -> siguiente = NULL;
    return nodo_inicial;
}
