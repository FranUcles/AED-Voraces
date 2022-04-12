#include <vector>
#include <math.h>
using namespace std;

const int SIN_PAREJA = -1;

void Voraz(vector<bool> &Alumnos, vector<vector<int>> &Amistades, vector<vector<int>> &Trabajo, vector<vector<int>> &Parejas, int &valor){
    // Primero hacemos la inicialización 
    int ultima = 1;                         // Variable que nos indica cuál es la siguiente pareja en asignar
    int N = Alumnos.size();                 // Número total de alumnos
    int parejas = (int) ceil(N/2);          // Número total de parejas a formar
    for (int i = 1; i <= parejas; i++){     // Ponemos todas las parejas como "vacías"
        Parejas[i-1][0] = SIN_PAREJA;       // ...
        Parejas[i-1][1] = SIN_PAREJA;       // ...
    }              
    // Ahora hacemos el bucle que se repetirá mientras no haya solución
    while (ultima <= parejas) {             // Habrá una solución cuando la última pareja esté asignada
        // Elegimos cuál es la pareja más prometedora
        vector<int> pareja_aux;         
        int alumno1 = pareja_aux[0];        // Obtenemos el primer alumno de la pareja
        int alumno2 = pareja_aux[1];        // Obtenemos el segundo alumno de la pareja
        // Quitamos a los alumnos de los candidatos
        Alumnos[alumno1 - 1] = true;        // Los tomo como ya seleccionados
        if (alumno2 != -1)                  // Necesario comprobar si el alumno1 ha quedado suelto
            Alumnos[alumno2 - 1] = true;    // El -1 es por los índices del vector
        // Inserto la pareja a la solución, pues siempre se puede llegar a una solución con cualquier pareja
        Parejas[ultima - 1][0] = alumno1;   // Los coloco en el array de soluciones
        Parejas[ultima - 1][1] = alumno2;   // ...
        ultima++;                           // Paso a la siguiente pareja a colocar
        if (alumno2 != 1)                   // Actualizo el valor de esa pareja en caso de que no sea un alumno suelto
            valor = valor + Amistades[alumno1 - 1][alumno2 - 1]*Amistades[alumno2 - 1][alumno1 - 1] + Trabajo[alumno1 - 1][alumno2 - 1]*Trabajo[alumno2 - 1][alumno1 - 1];
    }
}
