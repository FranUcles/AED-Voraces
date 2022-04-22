#include <vector>
#include <math.h>
#include <fstream>
#include <iostream>

using namespace std;

//tras cada caso de prueba se imprimen los datos
void imprimirDatos (int alumnos, vector<vector<int>> &Parejas, int &valor){
    ofstream salida;
    salida.open("salida.txt", ofstream::out | ofstream::trunc);

    salida << valor << endl;        //imprimimos primero el beneficio total de la clase
    int mitad;
    //esto lo hago porque la division de enteros redondea por truncamiento, y en el caso impar nos faltaría un alumno
    if ((alumnos % 2)==0) mitad = alumnos/2;
    else mitad = alumnos/2 +1;
    for (int i=0; i<mitad; i++){
        salida << Parejas[i][0] << " " << Parejas[i][1];
    }

    salida << endl;
    
}