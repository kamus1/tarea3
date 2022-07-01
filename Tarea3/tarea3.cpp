#include<iostream>
#include<fstream>

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


//Funcion return Numero cantidad de opciones
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
//Funcion para insertar salas
void InsertarSala(struct sala *&primeraSala, string descripcion){

}

//Funcion para insertar Opciones
void InsertarOpcion(){

}


//struct para las ocpiones o caminos
struct opcion{
    string descripcion, numOpcion;

    struct opcion *siguiente;
    struct sala *salaSiguiente;
};

//struct para las salas
struct sala{
    string descripcion, numSala;
    int numOpciones;
    
    struct opcion *listaSalas;
};


int main(){
    
    string texto, nodoOrigen, decision, decripcion;
    float start = true;

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

        if(texto == "-" && start == true){
            start = false;
        }else if(start == true){
            cout<<texto<<endl;
        }





    }

    cout<<NumOpciones("6")<<endl;
    
    archivo.close();
    return 1;
}