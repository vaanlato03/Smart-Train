#include <iostream>
#include "Ejercicios_clases.h"
using namespace std;

// Constructor clase Ejercicio
Ejercicio::Ejercicio(int cod, string nom, string desc, int inten, int sem, int tiempo) {
  this->codigo = cod;
  this->nombre = nom;
  this->descripcion = desc;
  this->intensidad = inten;
  this->ultimaSemana = sem;
  this->tiempoMinutos = tiempo;
}

// Destructor clase Ejercicio
Ejercicio::~Ejercicio() {}

// Getters clase Ejercicio
int Ejercicio::getCodigo() {
  return this->codigo;
}

string Ejercicio::getNombre() {
  return this->nombre;
}

string Ejercicio::getIntensidadString() {
  string inten;
  // Interpreta la intensidad para devolverla como texto.
  switch (this->intensidad){
    case 1: inten = "Basico"; break;
    case 2: inten = "Intermedio"; break;
    case 3: inten = "Avanzado"; break;
    case 4: inten = "Alto Rendimiento"; break;
  }
  return inten;
}

int Ejercicio::getIntensidad() {
  return this->intensidad;
}

int Ejercicio::getUltimaSemana() {
  return this->ultimaSemana;
}

int Ejercicio::getTiempoMinutos() {
  return this->tiempoMinutos;
}

// Setters clase Ejercicio
void Ejercicio::setNombre(string nom) {
  this->nombre = nom;
}

void Ejercicio::setDescripcion(string desc) {
  this->descripcion = desc;
}

void Ejercicio::setIntensidad(int inten) {
  this->intensidad = inten;
}

void Ejercicio::setUltimaSemana(int sem) {
  this->ultimaSemana = sem;
}

void Ejercicio::setTiempoMinutos(int tiempo) {
  this->tiempoMinutos = tiempo;
}

// Otros métodos clase Ejercicio
int Ejercicio::getTipo() {
  return 0; // Por defecto 0, debe ser sobreescrito por las clases Fuerza o Cardio.
}

void Ejercicio::mostrarInfo() {
  cout << "=============================================" << endl;
  cout << "CODIGO: " << this->codigo << endl;
  cout << "NOMBRE: " << this->nombre << endl;
  cout << "DESCRIPCION: " << this->descripcion << endl;
  cout << "INTENSIDAD: " << this->getIntensidadString() << endl;
  cout << "TIEMPO ESTIMADO: " << this->tiempoMinutos << endl;
}

// Constructor y destructor clase Fuerza
Fuerza::Fuerza(int cod, string nom, string desc, int inten, int sem, int tiempo) : Ejercicio(cod, nom, desc, inten, sem, tiempo) {}

Fuerza::~Fuerza() {}

// Métodos clase Fuerza
int Fuerza::getTipo() {
  return 1;
}

void Fuerza::mostrarInfo() {
  Ejercicio::mostrarInfo(); // Utiliza el método de la clase base
  cout << "TIPO: Fuerza" << endl; // y lo extiende con la información del tipo.
  cout << "=============================================" << endl;
}

// Constructor y destructor clase Cardio
Cardio::Cardio(int cod, string nom, string desc, int inten, int sem, int tiempo) : Ejercicio(cod, nom, desc, inten, sem, tiempo) {}

Cardio::~Cardio() {}

// Métodos clase Cardio
int Cardio::getTipo() {
  return 2;
}

void Cardio::mostrarInfo() {
  Ejercicio::mostrarInfo(); // Utiliza el método de la clase base
  cout << "TIPO: Cardiovascular" << endl; // y lo extiende con la información del tipo.
  cout << "=============================================" << endl;
}

// Constructor y destructor clase Rutina
Rutina::Rutina(string cliente, int nivel) {
  this->cliente = cliente;
  this->nivelIntensidad = nivel;
}

Rutina::~Rutina() {
  this->limpiarRutina();
}

// Métodos clase Rutina
void Rutina::agregarEjercicio(Ejercicio* ejercicio) {
  this->rutina.push_back(ejercicio); // Agrega un ejercicio al final con push_back.
}

void Rutina::eliminarEjercicio(int indice) {
  delete this->rutina[indice]; // Destruye el ejercicio en el índice solicitado.
  this->rutina.erase(this->rutina.begin() + indice); // Elimina el espacio en el vector.
}

int Rutina::calcularTiempoTotal() {
  int tiempoTotal = 0;
  // Recorre el vector y suma el tiempo de cada ejercicio con getTiempoMinutos().
  for (int i = 0; i < this->rutina.size(); i++) {
    tiempoTotal += this->rutina[i]->getTiempoMinutos();
  }
  return tiempoTotal;
}

void Rutina::mostrarRutina() {
  cout << "=============================================" << endl;
  cout << "RUTINA DEL CLIENTE: " << this->cliente << endl;
  cout << "NIVEL DE INTENSIDAD: ";
  switch (this->nivelIntensidad) {
    case 1: cout << "Basico" << endl; break;
    case 2: cout << "Intermedio" << endl; break;
    case 3: cout << "Avanzado" << endl; break;
    case 4: cout << "Alto Rendimiento" << endl; break;
  }
  cout << "TIEMPO TOTAL: " << this->calcularTiempoTotal() << endl;
  cout << "EJERCICIOS: " << endl;
  for (int i = 0; i < this->rutina.size(); i++) {
    cout << i+1 << ". " << this->rutina[i]->getNombre() << ".\tCódigo: " << this->rutina[i]->getCodigo() << endl;
  }
  cout << "=============================================" << endl;
}

void Rutina::limpiarRutina() {
  this->rutina.clear(); // Limpia el vector.
}

// Getters clase Rutina
string Rutina::getCliente() {
  return this->cliente;
}

vector<Ejercicio*> Rutina::getEjercicios() {
  return this->rutina;
}