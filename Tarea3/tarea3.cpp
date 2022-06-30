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

    archivo.close();
    return 1;
}