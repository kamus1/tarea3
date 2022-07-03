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

bool ProcesarArchivo(NodoGrafo* &inicio, NodoGrafo* &tail, string nameArchivo){
    string texto, decision, descripcion, start_, nodoOrigen_2;
    int nodoOrigen_1;

    bool start = true;
    bool nodoInicioCreado = false;

    int opcion = 0;

    ifstream archivo;
    archivo.open(nameArchivo, ios::in);//abrir archivo en modo lectura

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
            start_ += texto+"\n";
        }else if(texto == "-"){ // Si se detecta un guion y no es el inicio se reestablesen las variables de control y descripcion (caso especial)
            
            //-------------------------------------------------
            if(!nodoInicioCreado){
                inicio = crearGrafo(start_);

                tail = inicio;
                nodoInicioCreado = true;
            }

            NodoGrafo* origen = inicio;

            while(origen->key != nodoOrigen_1){
                origen = origen->siguiente;
            }

            NodoGrafo* nodoActual = addNodo(descripcion, tail);

            if(origen->adyacencia == NULL){
                
                Adyacencia* nuevo = new Adyacencia;

                nuevo->opcion = 1;
                nuevo->descripcion = decision;
                nuevo->camino = nodoActual;
                nuevo->siguiente = NULL;
                origen->adyacencia = nuevo;

                // cout<<"1 "<<decision<<endl;

            }else{
                Adyacencia* inicioAdyacencia = origen->adyacencia;

                // cout<<"2 "<<decision<<endl;
                addAdyacencia(decision, inicioAdyacencia, nodoActual);
            }

            //--------------------------------------------------

            opcion = 0;
            descripcion = "";

        }else if(texto != "START"){ // leer 
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
                    if(texto == "GAMEOVER"){
                        descripcion += "\n"+texto;
                    }else{                        
                        descripcion += texto;
                    }
                    break;
            }
        }
    }
 
    archivo.close();
    return 1;

}

int main(){
    
    NodoGrafo* inicio;
    NodoGrafo* tail;

    // ProcesarArchivo(inicio, tail, "input.txt");
    if(!ProcesarArchivo(inicio, tail, "historia.txt")){
        cout<<"Ocurrio algun error"<<endl;
        return 0;
    }  
    // recorrerGrafo(inicio);

    //Ciclo principal del juego


    int alternativa;
    
    NodoGrafo* aux = inicio;
    while(aux != NULL){
        system("clear");

        cout<<aux->descripcion<<endl;
        

        Adyacencia* auxAdyacencia = aux->adyacencia;
        if(auxAdyacencia != NULL){
            while(auxAdyacencia != NULL){
                cout<<auxAdyacencia->opcion<<": ";
                cout<<auxAdyacencia->descripcion<<endl;
                
                auxAdyacencia = auxAdyacencia->siguiente;
            }   
            
            cin>>alternativa;

            auxAdyacencia = aux->adyacencia;
            while(auxAdyacencia != NULL){

                if(auxAdyacencia->opcion == alternativa){
                    aux = auxAdyacencia->camino;
                }

                
                auxAdyacencia = auxAdyacencia->siguiente;
            }  
        }else{
            aux = inicio;
        }
        cout<<"OK"<<endl;
        cin.get();

    }

    return 1;
}