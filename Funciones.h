#include <tuple>
#include <vector>
#include <string>
#include "Ejercicios_clases.h"
using namespace std;

// FUNCIONES PRINCIPALES

// Muestra el menú de opciones, personalizado con el nombre del cliente.
void mostrarMenu(string cliente);

// Pide los datos del ejercicio al cliente y los devuelve en una tupla en orden: 
// nombre, descripción, tipo, tiempo en minutos, intensidad, ultima semana.
tuple<string, string, int, int, int, int> pedirDatos();

// Crea un nuevo ejercicio y lo agrega al vector de ejercicios.
void ingresarEjercicio(vector<Ejercicio*>& ejercicios, int& cod);

// Actualiza los datos de un ejercicio existente.
void actualizarEjercicio(vector<Ejercicio*>& ejercicios);

// Elimina un ejercicio del vector de ejercicios.
void eliminarEjercicio(vector<Ejercicio*>& ejercicios);

// Muestra la información a detalle de un ejercicio.
void consultarEjercicio(vector<Ejercicio*> ejercicios);

// Busca ejercicios con el nivel de intensidad solicitado y los muestra.
void buscarPorIntensidad(vector<Ejercicio*> ejercicios);

// Crea una rutina con la cantidad de ejercicios y la intensidad solicitada,
// solamente con ejercicios que no se hayan realizado la semana pasada.
Rutina* generarRutina(vector<Ejercicio*> ejercicios, string cliente);

// Muestra una lista con los ejercicios ingresados.
void listaEjercicios(vector<Ejercicio*> ejercicios);

// Función principal con el flujo del menú.
void GestorDeRutinas();

// FUNCIONES AUXILIARES

// Valida que la opción ingresada sea numérica y esté disponible.
int validarOpcion(int max, int min, string mensaje);

// Valida que el texto ingresado no esté vacío.
string validarTexto(string mensaje);

// Busca el ejercicio solicitado por código y devuelve su índice en el vector.
// Si no lo encuentra, devuelve -1. Para cancelar operaciones, devuelve -2.
int buscarPorCodigo(vector<Ejercicio*> ejercicios, string mensaje);

// Libera la memoria de los ejercicios creados.
void liberarMemoria(vector<Ejercicio*>& ejercicios);