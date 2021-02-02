#include <iostream>
#include <fstream>
using namespace std;

int Busqueda(int arrr[], int t, int dato);
void ingresarElementos(int arrr[], int t);
void escribirArchivo(int arrr[], string nombrearchivo, int t, int dato, int posición);
int solicitarNumero();

int main() {
  int a[]={}, tamaño, posición;
  string narchivo;
  //ofstream archivo;
  //archivo.open("LINEAL",ios::out);
  cout<<"Ingrese el nombre del archivo:\n";
  getline(cin,narchivo);
  cout<<"Ingrese el tamaño del arreglo:\n";
  cin>>tamaño;
  ingresarElementos(a,tamaño);
  int dato=solicitarNumero();
  if (Busqueda(a, tamaño, dato)==-1)
  {
    cout<<"Elemento no encontrado.\n";
  }
  else
  {
    cout<<"Elemento encontrado en la posición "<<Busqueda(a, tamaño, dato);
  }
  posición=Busqueda(a, tamaño, dato);
  escribirArchivo(a,narchivo,tamaño,dato,posición);

  return 0;
}

int Busqueda(int arrr[], int t, int dato)
{
  int i;
  for (int i=0; i<t; i++)
  {
         //4 --- 3
    if (arrr[i]==dato)
    {
      //cout<<"Elemento encontrado";
      return i;
    }
  }
  return -1;
}

void ingresarElementos(int arrr[], int t)
{
  //cout<<"ingresar con el elemento agregado es: ";
  for (int i=0; i<t; i++)
  {
    cout<<"Ingresar elemento "<<i<<": " ;
    cin>>arrr[i];
  }
}

void escribirArchivo(int arrr[], string nombrearchivo, int t, int dato, int posición)
{
  int i;
  ofstream archivoarreglo;
  archivoarreglo.open(nombrearchivo.c_str(),ios::out);
  archivoarreglo<<"Arreglo de elementos:\n";
  for (i=0; i<t; i++)
  {
    archivoarreglo<<"|"<<arrr[i]<<"|";
  }
  archivoarreglo<<endl;
  archivoarreglo<<"Elemento a buscar: \n";
  archivoarreglo<<dato;
  archivoarreglo<<endl;
  archivoarreglo<<"Posición del elemento a buscar: \n";
  archivoarreglo<<posición;
  archivoarreglo.close();
}

int solicitarNumero()
{
  int n;
  cout<<"Ingresar el elemento a buscar: \n";
  cin>>n;
  return n;
}
