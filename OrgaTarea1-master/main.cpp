// queue::push/pop
#include "Mascota.h"
#include "Evaluador.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

void escribir(string nombre_archivo, Mascota*mascota, int posicion)
{

    ofstream my_archivo(nombre_archivo.c_str(),ios::in | ios::binary);

   my_archivo.seekp( posicion*10);
   my_archivo.write(mascota->nombre.c_str(),6);
   my_archivo.write((char *) &mascota->edad,4);
   my_archivo.close();

}


Mascota* leer(string nombre_archivo, int posicion)
{
    Mascota *masc;
    ifstream my_archivo(nombre_archivo.c_str());
    my_archivo.seekg(posicion*10);
    char nombre[6];
    int edad;
    my_archivo.read(nombre,6);
    my_archivo.read((char*)&edad,4);
    masc=  new Mascota(edad,nombre);
    return masc;
}


vector<Mascota*> leerTodos(string nombre_archivo)
{
    vector<Mascota*>respuesta;
    Mascota *masc ;
    ifstream my_archivo(nombre_archivo.c_str());
    my_archivo.seekg(0,my_archivo.end);
    int tama = my_archivo.tellg()/10;
    my_archivo.seekg(0,my_archivo.beg);

    for(int i =0 ; i< tama; i++)
    {
        char nombre[6];
        int edad;
       my_archivo.read(nombre,6);
        my_archivo.read((char*)&edad,4);
        masc = new Mascota(edad,nombre);
        respuesta.push_back(masc);
    }
    return respuesta;
}

int main ()
{

    evaluar();
    return 0;
}
