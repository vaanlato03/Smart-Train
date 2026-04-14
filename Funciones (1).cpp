#include <iostream>
#include <tuple>
#include "Funciones.h"
using namespace std;

void mostrarMenu(string cliente) {
  cout << "\n==================================================" << endl;
  cout << "Sistema de Rutinas de Entrenamiento de " << cliente << endl;
  cout << "==================================================" << endl;
  cout << "1. Ingresar ejercicio" << endl;
  cout << "2. Actualizar ejercicio" << endl;
  cout << "3. Eliminar ejercicio" << endl;
  cout << "4. Consultar ejercicio" << endl;
  cout << "5. Buscar ejercicio por intensidad" << endl;
  cout << "6. Generar rutina de entrenamiento" << endl;
  cout << "7. Ver catalogo de ejercicios disponibles" << endl;
  cout << "8. Salir" << endl;
}

int validarOpcion(int max, string mensaje) {
  int opcion;
  cout << mensaje;
  cin >> opcion;
  
  while (opcion < 1 || opcion > max) {
    cout << "Opcion no valida. Intente nuevamente." << endl;
    cout << mensaje;
    cin >> opcion;
  }
  return opcion;
}

string validarTexto(string mensaje) {
  string texto;
  cout << mensaje;
  getline(cin, texto);
  
  while (texto.empty()) {
    cout << "No puede estar vacio. Intente nuevamente." << endl;
    cout << mensaje;
    getline(cin, texto);
  }
  return texto;
}

tuple<string, string, int, int, int, int> pedirDatos() {
  cin.ignore();
  string nom = validarTexto("Nombre: ");
  string desc = validarTexto("Descripcion: ");
  int tipo = validarOpcion(2, "Tipo (1: Fuerza, 2: Cardiovascular): ");
  int tiempo = validarOpcion(1000, "Tiempo estimado (minutos): ");
  int inten = validarOpcion(4, "Intensidad (1: Basico, 2: Intermedio, 3: Avanzado, 4: Alto Rendimiento): ");
  int sem = validarOpcion(2, "Realizo este ejercicio la semana pasada? (1: Si, 2: No): ");
  return {nom, desc, tipo, tiempo, inten, sem};
}

int buscarPorCodigo(vector<Ejercicio*> ejercicios, string mensaje) {
  int cod = validarOpcion(1000, mensaje);
  for (int i = 0; i < ejercicios.size(); i++) {
    if (ejercicios[i]->getCodigo() == cod) {
      return i;
    }
  }
  return -1;
}

void ingresarEjercicio(vector<Ejercicio*>& ejercicios, int& cod) {
  string nom, desc;
  int tipo, tiempo, inten, sem;
  Ejercicio* nuevoEjercicio = nullptr;
  cout << "\nIngrese los datos del ejercicio..." << endl;
  tie(nom, desc, tipo, tiempo, inten, sem) = pedirDatos();
  switch (tipo) {
    case 1: {
      nuevoEjercicio = new Fuerza(cod, nom, desc, inten, sem, tiempo);
      ejercicios.push_back(nuevoEjercicio);
      break;
    }
    case 2: {
      nuevoEjercicio = new Cardio(cod, nom, desc, inten, sem, tiempo);
      ejercicios.push_back(nuevoEjercicio);
      break;
    }
    default: cout << "\nAlgo salio mal. Intente nuevamente." << endl; return;
  }
  cod++;
  cout << "\nEl ejercicio se ha ingresado correctamente. Tu puedes!" << endl;
  nuevoEjercicio->mostrarInfo();
}

void actualizarEjercicio(vector<Ejercicio*>& ejercicios){
  int indice = buscarPorCodigo(ejercicios, "Ingrese el codigo del ejercicio a actualizar: ");
  if (indice == -1) {
    cout << "\nNo se encontro el ejercicio con ese codigo." << endl;
    return;
  }
  
  ejercicios[indice]->mostrarInfo();
  string nom, desc;
  int tipo, tiempo, inten, sem;
  cout << "\nIngrese los NUEVOS datos del ejercicio..." << endl;
  tie(nom, desc, tipo, tiempo, inten, sem) = pedirDatos();
  
  if (ejercicios[indice]->getTipo() == tipo) {
    ejercicios[indice]->setNombre(nom);
    ejercicios[indice]->setDescripcion(desc);
    ejercicios[indice]->setIntensidad(inten);
    ejercicios[indice]->setTiempoMinutos(tiempo);
    ejercicios[indice]->setUltimaSemana(sem);
    cout << "\nEl ejercicio se ha actualizado correctamente." << endl;
  } else {
    int cod = ejercicios[indice]->getCodigo();
    Ejercicio* nuevoEjercicio = nullptr;
    if (tipo == 1) {
      nuevoEjercicio = new Fuerza(cod, nom, desc, inten, sem, tiempo);
    } else {
      nuevoEjercicio = new Cardio(cod, nom, desc, inten, sem, tiempo);
    }
    delete ejercicios[indice];
    ejercicios[indice] = nuevoEjercicio;
    cout << "\nEl ejercicio se ha actualizado correctamente." << endl;
  }
}

void eliminarEjercicio(vector<Ejercicio*>& ejercicios) {
  int indice = buscarPorCodigo(ejercicios, "Ingrese el codigo del ejercicio a eliminar: ");
  if (indice == -1) {
    cout << "\nNo se encontro el ejercicio con ese codigo." << endl;
    return;
  }
  delete ejercicios[indice];
  ejercicios.erase(ejercicios.begin() + indice);
  cout << "\nEl ejercicio se ha eliminado correctamente." << endl;
}

void consultarEjercicio(vector<Ejercicio*> ejercicios) {
  int indice = buscarPorCodigo(ejercicios, "Ingrese el codigo del ejercicio a consultar: ");
  if (indice == -1) {
    cout << "\nNo se encontro el ejercicio con ese codigo." << endl;
    return;
  }
  ejercicios[indice]->mostrarInfo();
}

void buscarPorIntensidad(vector<Ejercicio*> ejercicios) {
  int inten;
  cout << "Ingrese el nivel de intensidad (1: Basico, 2: Intermedio, 3: Avanzado, 4: Alto Rendimiento): ";
  cin >> inten;

  bool encontrado = false;
  for (int i = 0; i < ejercicios.size(); i++) {
    if (ejercicios[i]->getIntensidad() == inten) {
      ejercicios[i]->mostrarInfo();
      encontrado = true;
    }
  }
  if (!encontrado) {
    cout << "\nNo se encontraron ejercicios con ese nivel, ingrese algunos primero." << endl;
  }
}

Rutina* generarRutina(vector<Ejercicio*> ejercicios, string cliente) {
  cout << "\n-- Generar rutina de entrenamientos --" << endl;
  int inten = validarOpcion(4, "Nivel de intensidad (1: Basico, 2: Intermedio, 3: Avanzado, 4: Alto Rendimiento): ");
  int cantidad = validarOpcion(1000, "Cantidad de ejercicios: ");

  if (cantidad < ejercicios.size()) {
    cout << "\nNo hay suficientes ejercicios para generar la rutina, ingrese algunos primero." << endl;
    return nullptr;
  }
  
  Rutina* miRutina = new Rutina(cliente, inten);
  
  int agregados = 0;
  for (int i = 0; i < ejercicios.size(); i++) {
    if (ejercicios[i]->getIntensidad() == inten && ejercicios[i]->getUltimaSemana() != 1) {
      miRutina->agregarEjercicio(ejercicios[i]);
      agregados++;
    }
  }

  if (agregados < cantidad) {
    cout << "\nNo hay suficientes ejercicios disponibles para ese nivel o distintos a la semana pasada." << endl;
    cout << "Ingrese más ejercicios primero." << endl;
    return nullptr;
  } else if (agregados == cantidad) {
    cout << "\nEsta es tu rutina !" << endl;
    miRutina->mostrarRutina();
    return miRutina;
  } else {
    while (agregados > cantidad) {
      int aleatorio = rand() % miRutina->getEjercicios().size();
      miRutina->eliminarEjercicio(aleatorio);
    }
    cout << "\nEsta es tu rutina !" << endl;
    miRutina->mostrarRutina();
    return miRutina;
  }
}

void listaEjercicios(vector<Ejercicio*> ejercicios) {
  if (ejercicios.empty()) {
    cout << "\nNo hay ejercicios registrados en el sistema." << endl;
    return;
  }
  cout << "\n========================================================" << endl;
  cout << "          CATALOGO DE EJERCICIOS DISPONIBLES" << endl;
  for (int i = 0; i < ejercicios.size(); i++) {
    cout << i+1 <<". CODIGO: " << ejercicios[i]->getCodigo() << "\tEJERCICIO: " << ejercicios[i]->getNombre() << "\tINTENSIDAD: " << ejercicios[i]->getIntensidadString() << endl;
  }
  cout << "========================================================" << endl;
}

void liberarMemoria(vector<Ejercicio*>& ejercicios) {
  for (int i = 0; i < ejercicios.size(); i++) {
    delete ejercicios[i];
  }
  ejercicios.clear();
}

void GestorDeRutinas() {
  int opcion = 0;
  int ultimoCodigo = 1;
  string cliente;
  vector<Ejercicio*> ejercicios;
  Rutina* miRutina = nullptr;

  cout << "\nBienvenido al sistema de rutinas de entrenamiento!" << endl;
  cout << "Ingrese su nombre de usuario: "; getline(cin, cliente);
  
  do {
    mostrarMenu(cliente);
    opcion = validarOpcion(8, "Elija una opcion: ");
    switch (opcion) {
      case 1: ingresarEjercicio(ejercicios, ultimoCodigo); break;
      case 2: actualizarEjercicio(ejercicios); break;
      case 3: eliminarEjercicio(ejercicios); break;
      case 4: consultarEjercicio(ejercicios); break;
      case 5: buscarPorIntensidad(ejercicios); break;
      case 6: miRutina = generarRutina(ejercicios, cliente); break;
      case 7: listaEjercicios(ejercicios); break;
      case 8: cout << "\nGracias por visitar el sistema de rutinas!" << endl; break;
    }
  } while (opcion != 8);

  liberarMemoria(ejercicios);
  miRutina->liberarRutina();
}