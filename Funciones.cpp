#include <iostream>
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

int validarOpcion(int max, int min, string mensaje) {
  try {
    // Pide el dato por primera vez.
    int opcion;
    cout << mensaje;
    cin >> opcion;

    // Lanza error si el dato ingresado no es numérico.
    if (cin.fail()) {
      throw "Error: Verifique que el dato ingresado sea un numero.";
    }

    // Lanza error si el dato ingresado está fuera del rango.
    if (opcion < min || opcion > max) {
      throw "Opcion no valida. Intente nuevamente.";
    }
    // Si está todo bien, limpia el buffer y retorna el dato.
    return opcion;
  }
  catch (const char* e) {
    cout << e << endl;
    cin.clear(); // Quita el estado de error.
    cin.ignore(1000, '\n'); // Limpia el buffer de entrada para evitar problemas.
    return validarOpcion(max, min, mensaje);
  }
}

string validarTexto(string mensaje) {
  // Pide el dato por primera vez.
  string texto;
  cout << mensaje;
  getline(cin, texto);

  // Vuelve a solicitar el dato mientras el campo esté vacío.
  while (texto.empty()) {
    cout << "No puede estar vacio. Intente nuevamente." << endl;
    cout << mensaje;
    getline(cin, texto);
  }
  return texto;
}

tuple<string, string, int, int, int, int> pedirDatos() {
  // Limpia el buffer de entrada para evitar problemas con getline.
  cin.ignore();

  // Pide los datos y los retorna.
  string nom = validarTexto("Nombre: ");
  string desc = validarTexto("Descripcion: ");
  int tipo = validarOpcion(2, 1, "Tipo (1: Fuerza, 2: Cardiovascular): ");
  int tiempo = validarOpcion(1000, 1, "Tiempo estimado (minutos): ");
  int inten = validarOpcion(4, 1, "Intensidad (1: Basico, 2: Intermedio, 3: Avanzado, 4: Alto Rendimiento): ");
  int sem = validarOpcion(2, 1, "Realizo este ejercicio la semana pasada? (1: Si, 2: No): ");
  return {nom, desc, tipo, tiempo, inten, sem};
}

int buscarPorCodigo(vector<Ejercicio*> ejercicios, string mensaje) {
  int cod = validarOpcion(1000, 0, mensaje);
  // Cancelar la operación si se ingresa 0.
  if (cod == 0) {
    return -2;
  }
  // Recorre el vector hasta encontrar el ejercicio con el código ingresado.
  for (int i = 0; i < ejercicios.size(); i++) {
    if (ejercicios[i]->getCodigo() == cod) {
      // Retorna el índice del ejercicio si lo encuentra.
      return i;
    }
  }
  // Retorna -1 si no lo encuentra.
  return -1;
}

void ingresarEjercicio(vector<Ejercicio*>& ejercicios, int& cod) {
  string nom, desc;
  int tipo, tiempo, inten, sem;
  Ejercicio* nuevoEjercicio = nullptr;
  cout << "\nIngrese los datos del ejercicio..." << endl;
  // Utiliza tie() para desempaquetar la tupla y asignar los valores a las variables.
  tie(nom, desc, tipo, tiempo, inten, sem) = pedirDatos();
  // Crea un nuevo objeto de la clase correspondiente y lo agrega al vector.
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
  // Muestra la lista de ejercicios y pide el código del ejercicio a actualizar.
  listaEjercicios(ejercicios);
  cout << "Ingrese 0 para cancelar." << endl;
  int indice = buscarPorCodigo(ejercicios, "Ingrese el codigo del ejercicio a actualizar: ");
  if (indice == -1) {
    cout << "\nNo se encontro el ejercicio con ese codigo." << endl;
    return;
  // Para cancelar la operación.
  } else if (indice == -2) {
    cout << "\nOperacion cancelada." << endl;
    return;
  }

  // Muestra la información actual del ejercicio y pide los nuevos datos.
  ejercicios[indice]->mostrarInfo();
  string nom, desc;
  int tipo, tiempo, inten, sem;
  cout << "\nIngrese los NUEVOS datos del ejercicio..." << endl;
  tie(nom, desc, tipo, tiempo, inten, sem) = pedirDatos();

  // Si el tipo de ejercicio no cambió, actualiza los datos directamente.
  if (ejercicios[indice]->getTipo() == tipo) {
    ejercicios[indice]->setNombre(nom);
    ejercicios[indice]->setDescripcion(desc);
    ejercicios[indice]->setIntensidad(inten);
    ejercicios[indice]->setTiempoMinutos(tiempo);
    ejercicios[indice]->setUltimaSemana(sem);
    cout << "\nEl ejercicio se ha actualizado correctamente." << endl;
  // Si el tipo de ejercicio cambió, crea un nuevo ejercicio.
  } else {
    // Mantiene el mismo código ya que es el "mismo ejercicio".
    int cod = ejercicios[indice]->getCodigo();
    Ejercicio* nuevoEjercicio = nullptr;
    if (tipo == 1) {
      nuevoEjercicio = new Fuerza(cod, nom, desc, inten, sem, tiempo);
    } else {
      nuevoEjercicio = new Cardio(cod, nom, desc, inten, sem, tiempo);
    }
    // Elimina el ejercicio anterior y lo reemplaza en el vector con el nuevo ejercicio.
    delete ejercicios[indice];
    ejercicios[indice] = nuevoEjercicio;
    cout << "\nEl ejercicio se ha actualizado correctamente." << endl;
  }
}

void eliminarEjercicio(vector<Ejercicio*>& ejercicios) {
  // Muestra la lista de ejercicios y pide el código del ejercicio a eliminar.
  listaEjercicios(ejercicios);
  cout << "Ingrese 0 para cancelar." << endl;
  int indice = buscarPorCodigo(ejercicios, "Ingrese el codigo del ejercicio a eliminar: ");
  if (indice == -1) {
    cout << "\nNo se encontro el ejercicio con ese codigo." << endl;
    return;
  // Para cancelar la operación.
  } else if (indice == -2) {
    cout << "\nOperacion cancelada." << endl;
    return;
  }
  
  // Elimina el ejercicio y elimina su espacio en el vector.
  delete ejercicios[indice];
  ejercicios.erase(ejercicios.begin() + indice);
  cout << "\nEl ejercicio se ha eliminado correctamente." << endl;
}

void consultarEjercicio(vector<Ejercicio*> ejercicios) {
  // Muestra la lista de ejercicios y pide el código del ejercicio a consultar.
  listaEjercicios(ejercicios);
  cout << "Ingrese 0 para cancelar." << endl;
  int indice = buscarPorCodigo(ejercicios, "Ingrese el codigo del ejercicio a consultar: ");
  if (indice == -1) {
    cout << "\nNo se encontro el ejercicio con ese codigo." << endl;
    return;
  // Para cancelar la operación.
  } else if (indice == -2) {
    cout << "\nOperacion cancelada." << endl;
    return;
  }
  
  // Muestra la información del ejercicio.
  ejercicios[indice]->mostrarInfo();
}

void buscarPorIntensidad(vector<Ejercicio*> ejercicios) {
  // Pide la intensidad a buscar.
  cout << "Ingrese 0 para cancelar." << endl;
  int inten = validarOpcion(4, 0, "Ingrese el nivel de intensidad (1: Basico, 2: Intermedio, 3: Avanzado, 4: Alto Rendimiento): ");

  // Para cancelar la operación.
  if (inten == 0) {
    cout << "\nOperacion cancelada." << endl;
    return;
  }
  
  // Recorre el vector y muestra todos los ejercicios con la intensidad ingresada.
  bool encontrado = false;
  for (int i = 0; i < ejercicios.size(); i++) {
    if (ejercicios[i]->getIntensidad() == inten) {
      ejercicios[i]->mostrarInfo();
      encontrado = true;
    }
  }
  // Si no encontró ningun ejercicio, muestra un mensaje.
  if (!encontrado) {
    cout << "\nNo se encontraron ejercicios con ese nivel, ingrese algunos primero." << endl;
  }
}

Rutina* generarRutina(vector<Ejercicio*> ejercicios, string cliente) {
  cout << "\n-- Generar rutina de entrenamientos --" << endl;
  // Pide la intensidad y la cantidad de ejercicios a incluir en la rutina.
  int inten = validarOpcion(4, 1, "Nivel de intensidad (1: Basico, 2: Intermedio, 3: Avanzado, 4: Alto Rendimiento): ");
  int cantidad = validarOpcion(1000, 1, "Cantidad de ejercicios: ");

  // Si no hay suficientes ejercicios en total retorna nullptr directamente.
  if (cantidad > ejercicios.size()) {
    cout << "\nNo hay suficientes ejercicios para generar la rutina, ingrese algunos primero." << endl;
    return nullptr;
  }
  
  Rutina* miRutina = new Rutina(cliente, inten);

  // Recorre el vector y agrega los ejercicios con la intensidad ingresada que no se hayan realizado la semana pasada.
  int agregados = 0;
  for (int i = 0; i < ejercicios.size(); i++) {
    if (ejercicios[i]->getIntensidad() == inten && ejercicios[i]->getUltimaSemana() != 1) {
      miRutina->agregarEjercicio(ejercicios[i]);
      agregados++;
    }
  }

  // Si no hay suficientes ejercicios que cumplan las condiciones, retorna nullptr.
  if (agregados < cantidad) {
    cout << "\nNo hay suficientes ejercicios disponibles para ese nivel o distintos a la semana pasada." << endl;
    cout << "Ingrese más ejercicios primero." << endl;
    delete miRutina;
    return nullptr;
  // Si cumple con la cantidad exacta, muestra la rutina y la retorna.
  } else if (agregados == cantidad) {
    cout << "\nEsta es tu rutina !" << endl;
    miRutina->mostrarRutina();
    return miRutina;
  // Si hay más ejercicios de los necesarios, elimina ejercicios aleatorios hasta cumplir con la cantidad.
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
  // Si no hay ejercicios, retorna de inmediato.
  if (ejercicios.empty()) {
    cout << "\nNo hay ejercicios registrados en el sistema." << endl;
    return;
  }
  cout << "\n========================================================" << endl;
  cout << "          CATALOGO DE EJERCICIOS DISPONIBLES" << endl;
  for (int i = 0; i < ejercicios.size(); i++) {
    cout << i+1 <<". CODIGO: " << ejercicios[i]->getCodigo() << "\tEJERCICIO: " << ejercicios[i]->getNombre() << "\tINTENSIDAD: " << ejercicios[i]->getIntensidad() <<endl;
  }
  cout << "========================================================" << endl;
}

void liberarMemoria(vector<Ejercicio*>& ejercicios) {
  // Destruye cada ejercicio en el vector y luego lo limpia.
  for (int i = 0; i < ejercicios.size(); i++) {
    delete ejercicios[i];
  }
  ejercicios.clear();
}

void GestorDeRutinas() {
  // Variables necesarias para el funcionamiento del programa.
  int opcion = 0;
  int ultimoCodigo = 1;
  string cliente;
  vector<Ejercicio*> ejercicios;
  Rutina* miRutina = nullptr;

  // Al abrir el programa pide le nombre del cliente.
  cout << "\nBienvenido al sistema de rutinas de entrenamiento!" << endl;
  cout << "Ingrese su nombre de usuario: "; getline(cin, cliente);

  // Bucle del menú hasta que se seleccione salir (8).
  do {
    mostrarMenu(cliente);
    opcion = validarOpcion(8, 1, "Elija una opcion: ");
    switch (opcion) {
      case 1: ingresarEjercicio(ejercicios, ultimoCodigo); break;
      case 2: actualizarEjercicio(ejercicios); break;
      case 3: eliminarEjercicio(ejercicios); break;
      case 4: consultarEjercicio(ejercicios); break;
      case 5: buscarPorIntensidad(ejercicios); break;
      case 6: if (miRutina!=nullptr) delete miRutina; miRutina = generarRutina(ejercicios, cliente); break;
      case 7: listaEjercicios(ejercicios); break;
      case 8: cout << "\nGracias por visitar el sistema de rutinas!" << endl; break;
    }
  } while (opcion != 8);

  // Elimina los ejercicios en el vector y la rutina antes de salir.
  liberarMemoria(ejercicios);
  cout << "Se eliminaron los ejercicios del sistema." << endl;
  if (miRutina != nullptr) {
    delete miRutina;
  }
}