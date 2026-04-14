#include <iostream>
#include "Ejercicios_clases.h"
using namespace std;

void mostrarMenu(string cliente);
int validarOpcion(int max, int opcion, string mensaje);
string validarTexto(string texto, string mensaje);
tuple<string, string, int, int, int, int> pedirDatos();
int buscarPorCodigo(vector<Ejercicio*> ejercicios);

void ingresarEjercicio(vector<Ejercicio*>& ejercicios, int& cod);
void actualizarEjercicio(vector<Ejercicio*>& ejercicios);
void eliminarEjercicio(vector<Ejercicio*>& ejercicios);
void consultarEjercicio(vector<Ejercicio*> ejercicios);
void buscarPorIntensidad(vector<Ejercicio*> ejercicios);
Rutina* generarRutina(vector<Ejercicio*> ejercicios, string cliente);
void listaEjercicios(vector<Ejercicio*> ejercicios);

void liberarMemoria(vector<Ejercicio*>& ejercicios);

void GestorDeRutinas();