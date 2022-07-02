#include<iostream>
#include<fstream>

#include "header.h"

using namespace std;

// trim from end (right)
inline std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

// trim from beginning (left)
inline std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

// trim from both ends (left & right)
inline std::string& trim(std::string& s, const char* t = " \t\n\r\f\v")
{
    return ltrim(rtrim(s, t), t);
}


//Funcion return Numero cantidad de opciones de nodo
int NumOpciones(string num){
    string texto;
    int contador = 0 ;
    ifstream archivo;
    archivo.open("input.txt", ios::in);
    while(!archivo.eof()){
        getline(archivo, texto); 
        trim(texto);
        if(texto == num){
            contador++;
        }
    }
    archivo.close();
    return contador;
}

int main(){
    
    string texto, decision, decripcion, start_, nodoOrigen_2;
    int nodoOrigen_1;

    float start = true;
    int opcion = 0;

    ifstream archivo;
    archivo.open("input.txt", ios::in);//abrir archivo en modo lectura

    //verificar que el archivo se haya abierto correctamente
    if(archivo.fail()){
        cout << "No se pudo abrir el archivo" << endl;
        return 0;
    }

    while(!archivo.eof()){
        getline(archivo, texto); 
        trim(texto);

        if(texto == "-" && start == true){ // Si se estaba leyendo el inicio y llega a un "-" cambia el stado de star por false
            start = false;
        }else if(start == true && texto != "START"){ // Si mientras "start" sea true imprime por pantalla
            start_ += texto;
        }else if(texto == "-"){ // Si se detecta un guion y no es el inicio se reestablesen las variables de control y descripcion (caso especial)
            

            //-------------------------------------------------
            NodoGrafo* inicio = crearGrafo(start_);
            NodoGrafo* tail = inicio;

            NodoGrafo* origen = inicio;

            while(origen->key != nodoOrigen_1){
                origen = origen->siguiente;
            }

            Adyacencia* inicioAdyacencia = origen->adyacencia;
            NodoGrafo* nodoActual = addNodo(decripcion, tail);
            
            int numOpciones_ =  1;
            if(NumOpciones(nodoOrigen_2) > numOpciones_ ){
                addAdyacencia(numOpciones_, decision, inicioAdyacencia, nodoActual);
            }


            //--------------------------------------------------

            opcion = 0;
            decripcion = "";

        }else{ // leer 
            switch(opcion){
                case 0:
                    nodoOrigen_1 = stoi(texto);
                    nodoOrigen_2 = texto;
                    opcion++;
                    break;
                case 1:
                    decision = texto;
                    opcion++;
                    break;
                default:
                    decripcion += texto;
                    break;
            }
            cout<<nodoOrigen_1<<endl;
            cout<<decision<<endl;
            cout<<decripcion<<endl;
        }

    }    
    archivo.close();
    return 1;
}