#include <vector>
#include <iostream>

using namespace std;

// las matrices son cuadrdas, así que sabemos el número de datos que tenemos que leer en cada línea

void leerDatos(int alumnos, vector<vector<int>> &Amistades, vector<vector<int>> &Trabajo)
{
    for (int i = 0; i < alumnos; i++){
        for (int j = 0; j < alumnos; j++)
        {
            if (i == j)
                Amistades[i][j] = 0; // si estamos en la diagonal, ponemos un 0
            else
                cin >> Amistades[i][j]; // en otor caso, leemos el dato y lo ponemos en la matriz.
        }
    }
    for (int i = 0; i < alumnos; i++){
        for (int j = 0; j < alumnos; j++)
        {
            if (i == j)
                Trabajo[i][j] = 0; // si estamos en la diagonal, ponemos un 0
            else
                cin >> Trabajo[i][j]; // en otor caso, leemos el dato y lo ponemos en la matriz.
        }
    }
}

int main(int argc, char const *argv[])
{
    int casos;
    cin >> casos;
    for (int i = 1; i <= casos; i++)
    {
        int alumnos;
        cin >> alumnos;
        vector<vector<int>> Amistades(alumnos, vector<int>(alumnos));
        vector<vector<int>> Trabajo(alumnos, vector<int>(alumnos));
        leerDatos(alumnos, Amistades, Trabajo);
        for (int i = 0; i < alumnos; i++)
        {
            for (int j = 0; j < alumnos; j++)
            {
                cout << Amistades[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < alumnos; i++)
        {
            for (int j = 0; j < alumnos; j++)
            {
                cout << Trabajo[i][j] << " ";
            }
            cout << endl;
        }
    }
}
