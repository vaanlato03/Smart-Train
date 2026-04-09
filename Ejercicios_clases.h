#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Ejercicio {
  private:
    int codigo;
    string nombre;
    string descripcion;
    int tipo;
    int ultimaSemana;
    int tiempoMinutos;

  public:
    // Constructor y destructor
    Ejercicio(int cod, string nom, string desc, int tipo, int sem, int tiempo);
    ~Ejercicio();

    // Getters
    int getCodigo();
    string getNombre();
    string getDescripcion();
    int getTipo();
    int getUltimaSemana();
    int getTiempoMinutos();

    // Setters
    void setNombre(string nom);
    void setDescripcion(string desc);
    void setTipo(int tipo);
    void setUltimaSemana(int sem);
    void setTiempoMinutos(int tiempo);

    virtual void mostrarInfo();
};

class Basico : public Ejercicio {
  public:
    Basico(int cod, string nom, string desc, int tipo, int sem, int tiempo);
    ~Basico();
    void mostrarInfo();
};

class Intermedio : public Ejercicio {
  public:
    Intermedio(int cod, string nom, string desc, int tipo, int sem, int tiempo);
    ~Intermedio();
    void mostrarInfo();
};

class Avanzado : public Ejercicio {
  public:
    Avanzado(int cod, string nom, string desc, int tipo, int sem, int tiempo);
    ~Avanzado();
    void mostrarInfo();
};

class AltoRendimiento : public Ejercicio {
  public:
    AltoRendimiento(int cod, string nom, string desc, int tipo, int sem, int tiempo);
    ~AltoRendimiento();
    void mostrarInfo();
};

class Rutina {
  public:
    string cliente;
    int nivelIntensidad;
    vector<Ejercicio*> ejercicios;

    Rutina(string cliente, int nivel);
    ~Rutina();

    void agregarEjercicio(Ejercicio* ejercicio);
    int calcularTiempoTotal();
    void mostrarRutina();
};