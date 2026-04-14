#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Ejercicio {
  private:
    int codigo;
    string nombre;
    string descripcion;
    int intensidad;
    int ultimaSemana;
    int tiempoMinutos;

  public:
    // Constructor y destructor
    Ejercicio(int cod, string nom, string desc, int inten, int sem, int tiempo);
    virtual ~Ejercicio();

    // Getters
    int getCodigo();
    string getNombre();
    string getDescripcion(); // No se usa
    string getIntensidadString();
    int getIntensidad();
    int getUltimaSemana();
    int getTiempoMinutos(); // No se usa

    // Setters
    void setNombre(string nom);
    void setDescripcion(string desc);
    void setIntensidad(int inten);
    void setUltimaSemana(int sem);
    void setTiempoMinutos(int tiempo);

    virtual int getTipo();
    virtual void mostrarInfo();
};

class Fuerza : public Ejercicio {
  public:
    Fuerza(int cod, string nom, string desc, int inten, int sem, int tiempo);
    ~Fuerza();
    int getTipo();
    void mostrarInfo();
};

class Cardio : public Ejercicio {
  public:
    Cardio(int cod, string nom, string desc, int inten, int sem, int tiempo);
    ~Cardio();
    int getTipo();
    void mostrarInfo();
};

class Rutina {
  private:
    string cliente;
    int nivelIntensidad;
    vector<Ejercicio*> rutina;

  public:
    Rutina(string cliente, int nivel);
    ~Rutina();

    void agregarEjercicio(Ejercicio* ejercicio);
    void eliminarEjercicio(int indice);
    int calcularTiempoTotal();
    void mostrarRutina();
    void liberarRutina();

    // Getters
    string getCliente();
    int getNivelIntensidad();
    vector<Ejercicio*> getEjercicios();

    // Setters
    void setNivelIntensidad(int nivel);
};