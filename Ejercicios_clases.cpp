#include <iostream>
#include <string>
#include <vector>
#include "Ejercicios_clases.h"
using namespace std;

// Constructor clase Ejercicio
Ejercicio::Ejercicio(int cod, string nom, string desc, int tipo, int sem, int tiempo) {
  this->codigo = cod;
  this->nombre = nom;
  this->descripcion = desc;
  this->tipo = tipo;
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

int Ejercicio::getTipo() {
  return this->tipo;
}

int Ejercicio::getUltimaSemana() {
  return this->ultimaSemana;
}

int Ejercicio::getTiempoMinutos() {
  return this->tiempoMinutos;
}

// Setters clase Ejercicio
void Ejercicio::setUltimaSemana(int sem) {
  this->ultimaSemana = sem;
}

// Otros métodos clase Ejercicio
void Ejercicio::mostrarInfo() {
  cout << "=============================================" << endl;
  cout << "CODIGO: " << this->codigo << endl;
  cout << "NOMBRE: " << this->nombre << endl;
  cout << "DESCRIPCION: " << this->descripcion << endl;
  cout << "TIPO: ";
  switch (this->tipo) {
    case 1: cout << "Fuerza" << endl; break;
    case 2: cout << "Cardiovascular" << endl; break;
  }
  cout << "TIEMPO ESTIMADO: " << this->tiempoMinutos << endl;
}

Basico::Basico(int cod, string nom, string desc, int inten, int sem, int tiempo) : Ejercicio(cod, nom, desc, inten, sem, tiempo) {}

Basico::~Basico() {}

void Basico::mostrarInfo() {
  Ejercicio::mostrarInfo();
  cout << "INTENSIDAD: Basico" << endl;
  cout << "=============================================" << endl;
}

Intermedio::Intermedio(int cod, string nom, string desc, int inten, int sem, int tiempo) : Ejercicio(cod, nom, desc, inten, sem, tiempo) {}

Intermedio::~Intermedio() {}

void Intermedio::mostrarInfo() {
  Ejercicio::mostrarInfo();
  cout << "INTENSIDAD: Intermedio" << endl;
  cout << "=============================================" << endl;
}

Avanzado::Avanzado(int cod, string nom, string desc, int inten, int sem, int tiempo) : Ejercicio(cod, nom, desc, inten, sem, tiempo) {}

Avanzado::~Avanzado() {}

void Avanzado::mostrarInfo() {
  Ejercicio::mostrarInfo();
  cout << "INTENSIDAD: Avanzado" << endl;
  cout << "=============================================" << endl;
}

AltoRendimiento::AltoRendimiento(int cod, string nom, string desc, int inten, int sem, int tiempo) : Ejercicio(cod, nom, desc, inten, sem, tiempo) {}

AltoRendimiento::~AltoRendimiento() {}

void AltoRendimiento::mostrarInfo() {
  Ejercicio::mostrarInfo();
  cout << "INTENSIDAD: Alto Rendimiento" << endl;
  cout << "=============================================" << endl;
}

Rutina::Rutina(string cliente, int nivel) {
  this->cliente = cliente;
  this->nivelIntensidad = nivel;
}