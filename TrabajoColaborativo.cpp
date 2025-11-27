#include <iostream>
#include <string>
using namespace std;

/*
    Estructura que representa a un miembro de la antigua civilización.
    Cada miembro será un nodo dentro del Árbol Binario de Búsqueda (ABB).
*/
struct Miembro {
    int id;                     // Identificador único del miembro
    string nombre;              // Nombre del miembro
    string fechaNacimiento;     // Fecha de nacimiento
    string descripcion;         // Descripción o datos adicionales
    Miembro *izq, *der;         // Hijos izquierdo y derecho del ABB

    // Constructor del nodo (miembro)
    Miembro(int _id, string _nombre, string _fecha, string _desc) {
        id = _id;
        nombre = _nombre;
        fechaNacimiento = _fecha;
        descripcion = _desc;
        izq = der = nullptr;   // Inicialmente sin hijos
    }
};

/*
    Clase principal del sistema.
    Maneja el Árbol Genealógico implementado como un ABB.
*/
class ArbolGenealogico {
private:
    Miembro *raiz;  // Puntero al nodo raíz del ABB

    /* ======================================================
        FUNCIÓN PRIVADA: insertar()
        Inserta un nuevo miembro dentro del ABB respetando el orden.
    ====================================================== */
    Miembro* insertar(Miembro *nodo, Miembro *nuevo) {
        if (!nodo) return nuevo;  // Caso base: insertar aquí

        if (nuevo->id < nodo->id)
            nodo->izq = insertar(nodo->izq, nuevo);  // Ir al subárbol izquierdo
        else
            nodo->der = insertar(nodo->der, nuevo);  // Ir al subárbol derecho

        return nodo;
    }

    /* ======================================================
        FUNCIÓN PRIVADA: buscar()
        Ubica un miembro dentro del ABB mediante su ID.
    ====================================================== */
    Miembro* buscar(Miembro *nodo, int id) {
        if (!nodo || nodo->id == id) return nodo;  // Encontrado o árbol vacío

        if (id < nodo->id)
            return buscar(nodo->izq, id);  // Buscar en izquierda
        
        return buscar(nodo->der, id);      // Buscar en derecha
    }

    /* ======================================================
        FUNCIÓN PRIVADA: mostrarAncestros()
        Muestra la cadena de ancestros mientras se recorre el árbol.
    ====================================================== */
    void mostrarAncestros(Miembro *nodo, int id) {
        if (!nodo) return;

        // Si llegamos al hijo buscado detenemos sin imprimirlo
        if (nodo->id == id) return;

        // Camino hacia el nodo (solo se imprime el camino recorrido)
        if (id < nodo->id) {
            cout << nodo->nombre << " ";
            mostrarAncestros(nodo->izq, id);
        } else {
            cout << nodo->nombre << " ";
            mostrarAncestros(nodo->der, id);
        }
    }

    /* ======================================================
        FUNCIÓN PRIVADA: mostrarDescendientes()
        Recorre el subárbol del miembro para listar todos sus descendientes.
    ====================================================== */
    void mostrarDescendientes(Miembro *nodo) {
        if (!nodo) return;
        cout << nodo->nombre << " ";
        mostrarDescendientes(nodo->izq);
        mostrarDescendientes(nodo->der);
    }

    /* ======================================================
        FUNCIÓN PRIVADA: minimo()
        Devuelve el nodo más pequeño del subárbol derecho.
        Usado para reemplazar un nodo eliminado.
    ====================================================== */
    Miembro* minimo(Miembro *nodo) {
        while (nodo->izq) nodo = nodo->izq;  // Avanza a la izquierda
        return nodo;
    }

    /* ======================================================
        FUNCIÓN PRIVADA: eliminar()
        Elimina un nodo del ABB manteniendo su estructura.
    ====================================================== */
    Miembro* eliminar(Miembro *nodo, int id) {
        if (!nodo) return nullptr;

        if (id < nodo->id)
            nodo->izq = eliminar(nodo->izq, id);
        else if (id > nodo->id)
            nodo->der = eliminar(nodo->der, id);
        else {
            // Caso 1: sin hijo izquierdo
            if (!nodo->izq) return nodo->der;

            // Caso 2: sin hijo derecho
            if (!nodo->der) return nodo->izq;

            // Caso 3: dos hijos → buscar reemplazo
            Miembro *minDer = minimo(nodo->der);

            // Copiar datos del sucesor
            nodo->id = minDer->id;
            nodo->nombre = minDer->nombre;
            nodo->fechaNacimiento = minDer->fechaNacimiento;
            nodo->descripcion = minDer->descripcion;

            // Eliminar el nodo duplicado
            nodo->der = eliminar(nodo->der, minDer->id);
        }
        return nodo;
    }

public:
    /* Constructor del árbol */
    ArbolGenealogico() { raiz = nullptr; }

    /* ======================================================
        FUNCIÓN PÚBLICA: registrar()
        Inserta un nuevo miembro en el ABB.
    ====================================================== */
    void registrar(int id, string nombre, string fecha, string desc) {
        Miembro *nuevo = new Miembro(id, nombre, fecha, desc);
        raiz = insertar(raiz, nuevo);
    }

    /* ======================================================
        FUNCIÓN PÚBLICA: consultar()
        Muestra la información almacenada de un miembro.
    ====================================================== */
    void consultar(int id) {
        Miembro *m = buscar(raiz, id);
        if (m) {
            cout << "\n--- Información del miembro ---\n";
            cout << "ID: " << m->id << "\nNombre: " << m->nombre;
            cout << "\nNacimiento: " << m->fechaNacimiento;
            cout << "\nDescripción: " << m->descripcion << "\n";
        } else {
            cout << "Miembro no encontrado.\n";
        }
    }

    /* ======================================================
        FUNCIÓN PÚBLICA: ancestros()
        Lista todos los ancestros de un miembro.
    ====================================================== */
    void ancestros(int id) {
        cout << "Ancestros de " << id << ": ";
        mostrarAncestros(raiz, id);
        cout << "\n";
    }

    /* ======================================================
        FUNCIÓN PÚBLICA: descendientes()
        Muestra el subárbol completo de un miembro.
    ====================================================== */
    void descendientes(int id) {
        Miembro *m = buscar(raiz, id);
        if (!m) { 
            cout << "No existe.\n"; 
            return; 
        }
        cout << "Descendientes de " << m->nombre << ": ";
        mostrarDescendientes(m);
        cout << "\n";
    }

    /* ======================================================
        FUNCIÓN PÚBLICA: eliminarMiembro()
        Elimina un miembro del árbol.
    ====================================================== */
    void eliminarMiembro(int id) {
        raiz = eliminar(raiz, id);
    }
};

/*
    FUNCIÓN PRINCIPAL
    Maneja el menú del sistema y permite interactuar con el árbol genealógico.
*/
int main() {
    ArbolGenealogico arbol;
    int op, id;
    string nombre, fecha, desc;

    do {
        cout << "\n---- Menu Genealogico ----\n";
        cout << "1. Registrar miembro\n";
        cout << "2. Consultar miembro\n";
        cout << "3. Ancestros\n";
        cout << "4. Descendientes\n";
        cout << "5. Eliminar miembro\n";
        cout << "0. Salir\nOpción: ";
        cin >> op;

        switch (op) {
            case 1:
                cout << "ID: "; cin >> id;
                cout << "Nombre: "; cin >> nombre;
                cout << "Nacimiento: "; cin >> fecha;
                cout << "Descripción: "; cin >> desc;
                arbol.registrar(id, nombre, fecha, desc);
                break;

            case 2:
                cout << "ID a consultar: "; cin >> id;
                arbol.consultar(id);
                break;

            case 3:
                cout << "ID: "; cin >> id;
                arbol.ancestros(id);
                break;

            case 4:
                cout << "ID: "; cin >> id;
                arbol.descendientes(id);
                break;

            case 5:
                cout << "ID a eliminar: "; cin >> id;
                arbol.eliminarMiembro(id);
                cout << "Eliminado.\n";
                break;
        }
    } while (op != 0);

    return 0;
}
