#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

int main(){
    
    string texto;
    ifstream archivo;

    archivo.open("input.txt", ios::in);//abrir archivo en modo lectura

    //verificar que el archivo se haya abierto correctamente
    if(archivo.fail()){
        cout << "No se pudo abrir el archivo" << endl;
        return 0;
    }

    while(!archivo.eof()){
        getline(archivo, texto);        
        if(texto == "START"){
            cout<<"Detecto"<<endl;
        }

    }

    archivo.close();
    return 1;
}