#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

const int VACIO = -1;

vector<int> Seleccionar(vector<bool> &Alumnos, vector<vector<int>> &Amistades, vector<vector<int>> &Trabajo){
    // Busco al primer alumno de la pareja
    int i = 0;
    while (Alumnos[i] == true)                      // No es necesario comprobar que no se salga del array porque siempre va a encontrar a alguno
        i++;
    int alumno1 = i;                                // Selecciono al alumno1
    // Busco al segundo alumno de la pareja que dé el mayor beneficio
    int max = 0;                                    // Pongo el máximo beneficio que obtendría con el segundo alumo a 0
    int alumno2 = VACIO;                            // Pongo el segundo alumno a "vacío"
    int N = Alumnos.size();                         // Calculo el número total de alumnos    
    for (int i = 0; i < N; i++){
        if (Alumnos[i] == true || i == alumno1) // Me salto los que ya se hayan seleccionado
            continue;
        int beneficio = Amistades[alumno1][i]*Amistades[i][alumno1] + Trabajo[alumno1][i];
        if (beneficio > max){                       // Compruebo si el beneficio va a ser mayor con esta pareja
            max = beneficio;                        // Actualizo el máximo beneficio
            alumno2 = i;                            // Actualizo la "mejor" pareja
        }
    }
    // Construyo la pareja seleccioanda
    vector<int> pareja(2);                          
    pareja[0] = alumno1;                            
    pareja[1] = alumno2;                            
    return pareja;
}

void Voraz(vector<bool> &Alumnos, vector<vector<int>> &Amistades, vector<vector<int>> &Trabajo, vector<vector<int>> &Parejas, int &valor){
    // Primero hacemos la inicialización 
    int ultima = 0;                                         // Variable que nos indica cuál es la siguiente pareja en asignar
    int N = Alumnos.size();                                 // Número total de alumnos
    int parejas = (int) ceil((double)N/2);                  // Número total de parejas a formar
    for (int i = 0; i < parejas; i++){                      // Ponemos todas las parejas como "vacías"
        Parejas[i][0] = VACIO;                              // ...
        Parejas[i][1] = VACIO;                              // ...
    }                                                       // ...
    // Ahora hacemos el bucle que se repetirá mientras no haya solución
    while (ultima < parejas) {                             // Habrá una solución cuando la última pareja esté asignada
        // Elegimos cuál es la pareja más prometedora
        vector<int> pareja_aux = Seleccionar(Alumnos, Amistades, Trabajo);             // Seleccionamos la pareja
        int alumno1 = pareja_aux[0];                        // Obtenemos el primer alumno de la pareja
        int alumno2 = pareja_aux[1];                        // Obtenemos el segundo alumno de la pareja
        // Quitamos a los alumnos de los candidatos
        Alumnos[alumno1] = true;                            // Los tomo como ya seleccionados
        if (alumno2 != VACIO)                               // Necesario comprobar si el alumno1 ha quedado suelto
            Alumnos[alumno2] = true;                        // El -1 es por los índices del vector
        // Inserto la pareja a la solución, pues siempre se puede llegar a una solución con cualquier pareja
        Parejas[ultima][0] = alumno1;                       // Los coloco en el array de soluciones
        Parejas[ultima][1] = alumno2;                       // ...
        ultima++;                                           // Paso a la siguiente pareja a colocar
        if (alumno2 != VACIO)                               // Actualizo el valor de esa pareja en caso de que no sea un alumno suelto
            valor = valor + (Amistades[alumno1][alumno2]+Amistades[alumno2][alumno1])*(Trabajo[alumno1][alumno2]+Trabajo[alumno2][alumno1]);
    }
}
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
    for (int i = 1; i <= casos; i++){
        int alumnos;
        cin >> alumnos;
        vector<vector<int>> Amistades(alumnos, vector<int>(alumnos));               // Inicializo la matriz de amistades
        vector<vector<int>> Trabajo(alumnos, vector<int>(alumnos));                 // Inicializo la matriz de trabajo
        vector<bool> Alumnos(alumnos, false);                                       // Inicializo todos los alumnos a false, pues ninguno está seleccionado
        leerDatos(alumnos, Amistades, Trabajo);                                     // Leer los datos necesario del fichero
        int valor = 0;                                                              // Variable para guardar el valor de esa distribución
        vector<vector<int>> Parejas((int)ceil((double)alumnos/2),vector<int>(2,VACIO));     // Creo la matriz de las parejas
        Voraz(Alumnos, Amistades, Trabajo, Parejas, valor);                         // Ejecuto el algoritmo voraz
        cout << valor << endl;
        for(int j = 0; j < Parejas.size(); j++){
            if (Parejas[j][1] == VACIO)
                cout << Parejas[j][0] << " ";
            else
                cout << Parejas[j][0] << " " << Parejas[j][1] << " ";
        }
        cout << endl;
    }
}
