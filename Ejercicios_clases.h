#include <vector>
#include <string>
using namespace std;

// CLASE PRINCIPAL: EJERCICIO
class Ejercicio {
  private:
    // Atributos necesarios. Privados para encapsulamiento.
    int codigo;
    string nombre;
    string descripcion;
    int intensidad; // 1: Basico, 2: Intermedio, 3: Avanzado, 4: Alto Rendimiento.
    int ultimaSemana; // Realizo el ejercicio la semana pasada? 1: Si, 2: No.
    int tiempoMinutos;

  public:
    // Constructor y destructor
    Ejercicio(int cod, string nom, string desc, int inten, int sem, int tiempo);
    virtual ~Ejercicio(); // Destructor virtual para que se llame al destructor de la clase derivada.

    // Getters
    int getCodigo();
    string getNombre();
    string getIntensidadString(); // Devuelve el nivel de intensidad interpretado en texto.
    int getIntensidad();
    int getUltimaSemana();
    int getTiempoMinutos();

    // Setters
    void setNombre(string nom);
    void setDescripcion(string desc);
    void setIntensidad(int inten);
    void setUltimaSemana(int sem);
    void setTiempoMinutos(int tiempo);

    // Métodos virtuales para polimorfismo.
    virtual int getTipo(); // Se sobreescribe en Fuerza(1) y Cardio(2). Por defecto es 0.
    virtual void mostrarInfo(); // Muestra la información detallada del ejercicio, excluyendo el tipo.
};

// CLASE FUERZA: HEREDA DE EJERCICIO
class Fuerza : public Ejercicio {
  public:
    // Constructor y destructor
    Fuerza(int cod, string nom, string desc, int inten, int sem, int tiempo);
    ~Fuerza();

    // Métodos virtuales sobreescritos
    int getTipo(); // Devuelve 1 para indicar que es un ejercicio de fuerza.
    void mostrarInfo(); // Extiende la información detallada del ejercicio, incluyendo el tipo.
};

// CLASE CARDIO: HEREDA DE EJERCICIO
class Cardio : public Ejercicio {
  public:
    // Constructor y destructor
    Cardio(int cod, string nom, string desc, int inten, int sem, int tiempo);
    ~Cardio();

    // Métodos virtuales sobreescritos
    int getTipo(); // Devuelve 2 para indicar que es un ejercicio cardiovascular.
    void mostrarInfo(); // Extiende la información detallada del ejercicio, incluyendo el tipo.
};

// CLASE RUTINA
class Rutina {
  private:
    // Atributos necesarios. Privados para encapsulamiento.
    string cliente;
    int nivelIntensidad;
    vector<Ejercicio*> rutina;

  public:
    // Constructor y destructor
    Rutina(string cliente, int nivel);
    ~Rutina();

    // Getters
    string getCliente();
    int getNivelIntensidad();
    vector<Ejercicio*> getEjercicios();

    // Otros métodos de Rutina
    void agregarEjercicio(Ejercicio* ejercicio); // Agrega un ejercicio al vector rutina.
    void eliminarEjercicio(int indice); // Elimina un ejercicio del vector rutina.
    int calcularTiempoTotal(); // Calcula el tiempo total de la rutina, sumando el tiempo de cada ejercicio.
    void mostrarRutina(); // Muestra la información detallada de la rutina.
    void limpiarRutina(); // Limpia el vector rutina.
};