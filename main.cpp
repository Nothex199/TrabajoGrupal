#include <iostream>
#include <string>
using namespace std;

// ===== ESTRUCTURA DE PACIENTES =====
struct Paciente {
    int id;
    string nombre;
    string apellidos;
    int prioridad;
    string estado;
    Paciente* siguiente;

    Paciente() {};
    Paciente(int valor, string name, string apell, int prior, string status) {
        id = valor;
        nombre = name;
        apellidos = apell;
        prioridad = prior;
        estado = status;
        siguiente = NULL;
    }
};

// ===== FUNCIONES DE PACIENTES =====

// Insertar nuevos pacientes
void agregarPaciente(Paciente*& inicio, int valor, string name, string apell, int prior, string status) {
    Paciente* nuevoPaciente = new Paciente(valor, name, apell, prior, status);
    if (inicio == NULL) {
        inicio = nuevoPaciente;
    } else {
        Paciente* temp = inicio;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoPaciente;
    }
    cout << "Paciente agregado correctamente.\n";
}

// Eliminar paciente por ID
void eliminarPaciente(Paciente*& inicio, int idBuscado) {
    Paciente* temp = inicio;
    Paciente* anterior = NULL;

    while (temp != NULL) {
        if (temp->id == idBuscado) {
            if (anterior == NULL) {
                inicio = temp->siguiente;
            } else {
                anterior->siguiente = temp->siguiente;
            }
            delete temp;
            cout << "Paciente con ID " << idBuscado << " eliminado.\n";
            return;
        }
        anterior = temp;
        temp = temp->siguiente;
    }
    cout << "No se encontró un paciente con ese ID.\n";
}

// Buscar paciente por ID
void buscarPaciente(Paciente*& inicio, int idBuscado) {
    Paciente* temp = inicio;
    while (temp != NULL) {
        if (temp->id == idBuscado) {
            cout << "=== Paciente Encontrado ===\n";
            cout << "ID: " << temp->id << endl;
            cout << "Nombre: " << temp->nombre << " " << temp->apellidos << endl;
            cout << "Prioridad: " << temp->prioridad << endl;
            cout << "Estado: " << temp->estado << endl;
            return;
        }
        temp = temp->siguiente;
    }
    cout << "No se encuentra el paciente buscado.\n";
}

// Modificar prioridad
void ModificarPrioridad(Paciente*& inicio, int idBuscado) {
    Paciente* temp = inicio;
    while (temp != NULL && temp->id != idBuscado) {
        temp = temp->siguiente;
    }
    if (temp == NULL) {
        cout << "No se encontró un paciente con ese ID.\n";
        return;
    }

    cout << "Paciente Encontrado:\n";
    cout << "ID: " << temp->id << endl;
    cout << "Nombre: " << temp->nombre << " " << temp->apellidos << endl;
    cout << "Prioridad actual: " << temp->prioridad << endl;

    int nuevaPrioridad;
    cout << "Ingrese la nueva prioridad: ";
    cin >> nuevaPrioridad;

    temp->prioridad = nuevaPrioridad;
    cout << "Prioridad actualizada correctamente.\n";
}

// ===== ESTRUCTURA DE MEDICINAS (PILA) =====
struct Medicina {
    string nombre;
    string dosis;
    string frecuencia;
    Medicina* siguiente;
};

Medicina* tope = NULL;

// Asignar medicina (PUSH)
void asignarMedicina(string nombre, string dosis, string frecuencia) {
    Medicina* nueva = new Medicina{nombre, dosis, frecuencia, tope};
    tope = nueva;
    cout << "Se agregó " << nombre << " a la pila.\n";
}

// Eliminar medicina (POP)
void eliminarMedicina() {
    if (tope == NULL) {
        cout << "La pila está vacía. No hay elementos que eliminar.\n";
        return;
    }
    Medicina* temp = tope;
    cout << "Se eliminó " << temp->nombre << " de la pila.\n";
    tope = tope->siguiente;
    delete temp;
}

// Mostrar medicinas actuales
void MostrarMedicinas() {
    if (tope == NULL) {
        cout << "La pila está vacía.\n";
        return;
    }
    Medicina* temp = tope;
    cout << "=== Estado actual de la pila ===\n";
    while (temp != NULL) {
        cout << "- " << temp->nombre << " (" << temp->dosis << ", " << temp->frecuencia << ")\n";
        temp = temp->siguiente;
    }
}

// ===== MENÚ PRINCIPAL =====
void menuPacientes(Paciente*& inicio) {
    int opcion;
    do {
        system("clear"); // Usa system("cls") si estás en Windows
        cout << "======= GESTIÓN DE PACIENTES ========\n";
        cout << "1. Agregar Paciente\n";
        cout << "2. Buscar Paciente\n";
        cout << "3. Eliminar Paciente\n";
        cout << "4. Modificar Prioridad\n";
        cout << "5. Ingreso de Medicina\n";
        cout << "6. Eliminar Medicina\n";
        cout << "7. Mostrar Medicinas\n";
        cout << "8. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: {
                int id, prioridad;
                string nombre, apellido, estado;
                cout << "Ingrese ID: ";
                cin >> id;
                cin.ignore();

                cout << "Ingrese nombre: ";
                getline(cin, nombre);
                cout << "Ingrese apellido: ";
                getline(cin, apellido);
                cout << "Ingrese Prioridad (1-5): ";
                cin >> prioridad;
                cin.ignore();
                cout << "Ingrese estado: ";
                getline(cin, estado);

                agregarPaciente(inicio, id, nombre, apellido, prioridad, estado);
                break;
            }
            case 2: {
                int id;
                cout << "Ingrese ID del paciente a buscar: ";
                cin >> id;
                buscarPaciente(inicio, id);
                break;
            }
            case 3: {
                int id;
                cout << "Ingrese ID del paciente a eliminar: ";
                cin >> id;
                eliminarPaciente(inicio, id);
                break;
            }
            case 4: {
                int id;
                cout << "Ingrese ID del paciente a modificar: ";
                cin >> id;
                ModificarPrioridad(inicio, id);
                break;
            }
            case 5: {
                string nombre, dosis, frecuencia;
                cout << "Ingrese Nombre de la Medicina: ";
                getline(cin, nombre);
                cout << "Ingrese la Dosis: ";
                getline(cin, dosis);
                cout << "Ingrese la Frecuencia: ";
                getline(cin, frecuencia);
                asignarMedicina(nombre, dosis, frecuencia);
                break;
            }
            case 6:
                eliminarMedicina();
                break;
            case 7:
                MostrarMedicinas();
                break;
            case 8:
                cout << "Hasta pronto...\n";
                break;
            default:
                cout << "Opción inválida.\n";
                break;
        }
        cout << "\nPresione ENTER para continuar...";
        cin.get();
    } while (opcion != 8);
}

int main() {
    Paciente* inicio = NULL;
    menuPacientes(inicio);
    return 0;
}
