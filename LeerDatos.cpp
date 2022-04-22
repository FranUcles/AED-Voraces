#include <vector>
#include <iostream>

using namespace std;

//las matrices son cuadrdas, así que sabemos el número de datos que tenemos que leer en cad línea

void leerDatos(int &casos, int &alumnos, vector<vector<int>> &Amistades, vector<vector<int>> &Trabajo){
    cin >> casos;                               //leemos el número de casos de prueba
    int cont=0;
    while (cont<casos){
        cin >> alumnos;                         //leémos el número de alumnos
    
        for (int i = 0; i<alumnos; i++){
            for(int j=0; i<alumnos; i++){
                if(i==j) Amistades[i][j] = 0;   //si estamos en la diagonal, ponemos un 0
                else cin >> Amistades[i][j];    //en otor caso, leemos el dato y lo ponemos en la matriz.
            }

        }
        for (int i = 0; i<alumnos; i++){
            for(int j=0; i<alumnos; i++){
                if(i==j) Trabajo[i][j] = 0;   //si estamos en la diagonal, ponemos un 0
                else cin >> Trabajo[i][j];    //en otor caso, leemos el dato y lo ponemos en la matriz.
            }
        }
        cont++;
    }
}

int main(int argc, char const *argv[])
{
    int casos;
    int alumnos;
    vector<vector<int>> Amistades;
    vector<vector<int>> Trabajo;

    leerDatos(casos, alumnos, Amistades, Trabajo);
    for (int i=0;  i<alumnos;  i++){
        for (int j=0;  j<alumnos; j++){
            cout << Amistades[i][j];
        }
        cout << endl;
    }

    for (int i=0;  i<alumnos;  i++){
        for (int j=0;  j<alumnos; j++){
            cout << Trabajo[i][j];
        }
        cout << endl;
    }

    return 0;
}
