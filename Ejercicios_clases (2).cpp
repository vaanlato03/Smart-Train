#include <iostream>
#include <string>
#include <vector>
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

string Ejercicio::getDescripcion() {
  return this->descripcion;
}

string Ejercicio::getIntensidadString() {
  string inten;
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
  return 0;
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
  Ejercicio::mostrarInfo();
  cout << "TIPO: Fuerza" << endl;
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
  Ejercicio::mostrarInfo();
  cout << "TIPO: Cardiovascular" << endl;
  cout << "=============================================" << endl;
}

// Constructor y destructor clase Rutina
Rutina::Rutina(string cliente, int nivel) {
  this->cliente = cliente;
  this->nivelIntensidad = nivel;
}

Rutina::~Rutina() {
  cout << "Se elimino la rutina del cliente " << this->cliente << endl;
}

// Métodos clase Rutina
void Rutina::agregarEjercicio(Ejercicio* ejercicio) {
  this->rutina.push_back(ejercicio);
}

void Rutina::eliminarEjercicio(int indice) {
  delete this->rutina[indice];
  this->rutina.erase(this->rutina.begin() + indice);
}

int Rutina::calcularTiempoTotal() {
  int tiempoTotal = 0;
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

void Rutina::liberarRutina() {
  for (int i = 0; i < this->rutina.size(); i++) {
    delete this->rutina[i];
  }
  this->rutina.clear();
}

string Rutina::getCliente() {
  return this->cliente;
}

void Rutina::setNivelIntensidad(int nivel) {
  this->nivelIntensidad = nivel;
}

vector<Ejercicio*> Rutina::getEjercicios() {
  return this->rutina;
}