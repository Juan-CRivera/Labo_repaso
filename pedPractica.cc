#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <stack>

struct Libro {
    std::string Titulo;
    std::string Autor;
    int Anio;
};

void Menu();
void MostrarLibros(const std::list<Libro>&);
void AgregarLibro(std::list<Libro>&);
void OrdenarLibro(std::list<Libro>&);
void BuscarLibro(const std::list<Libro>&);
void UsarPila(std::list<Libro>&, std::stack<Libro>&);
void UsarColas(std::queue<std::string>&);

int main() {
    std::list<Libro> biblioteca;
    std::stack<Libro> pilaPrestamos;
    std::queue<std::string> colaSolicitudes;
    int opcion;

    do {
        Menu();
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            AgregarLibro(biblioteca);
            break;
        case 2:
            OrdenarLibro(biblioteca);
            MostrarLibros(biblioteca);
            break;
        case 3:
            BuscarLibro(biblioteca);
            break;
        case 4:
            UsarPila(biblioteca, pilaPrestamos);
            break;
        case 5:
            UsarColas(colaSolicitudes);
            break;
        case 6:
            return 0;
        default:
            std::cout << "Opción no válida. Intente de nuevo." << std::endl;
            break;
        }
    } while (opcion != 6);

    return 0;
}

void Menu() {
    std::cout << "1. Agregar Libro" << std::endl;
    std::cout << "2. Ordenar Libros" << std::endl;
    std::cout << "3. Buscar Libro" << std::endl;
    std::cout << "4. Usar Pila (Préstamo de Libro)" << std::endl;
    std::cout << "5. Usar Cola (Solicitudes de Libros)" << std::endl;
    std::cout << "6. Salir" << std::endl;
    std::cout << "Ingrese el número de la opción que quiere acceder: ";
}

void MostrarLibros(const std::list<Libro>& biblioteca) {
    for (const auto& libro : biblioteca) {
        std::cout << "Título: " << libro.Titulo << std::endl;
        std::cout << "Autor: " << libro.Autor << std::endl;
        std::cout << "Año: " << libro.Anio << std::endl;
    }
}

void AgregarLibro(std::list<Libro>& biblioteca) {
    Libro nuevoLibro;
    std::cout << "Ingrese el título del libro: ";
    std::cin >> nuevoLibro.Titulo;
    std::cout << "Ingrese el autor del libro: ";
    std::cin >> nuevoLibro.Autor;
    std::cout << "Ingrese el año del libro: ";
    std::cin >> nuevoLibro.Anio;

    biblioteca.push_back(nuevoLibro);
    std::cout << "Libro agregado con éxito." << std::endl;
}

void OrdenarLibro(std::list<Libro>& biblioteca) {
    biblioteca.sort([](const Libro& a, const Libro& b) {
        return a.Titulo < b.Titulo;
    });
    std::cout << "Libros ordenados por título." << std::endl;
}

void BuscarLibro(const std::list<Libro>& biblioteca) {
    std::string titulo;
    std::cout << "Ingrese el título del libro a buscar: ";
    std::cin >> titulo;

    auto it = std::find_if(biblioteca.begin(), biblioteca.end(), [&](const Libro& libro) {
        return libro.Titulo == titulo;
    });

    if (it != biblioteca.end()) {
        std::cout << "Libro encontrado:" << std::endl;
        std::cout << "Título: " << it->Titulo << std::endl;
        std::cout << "Autor: " << it->Autor << std::endl;
        std::cout << "Año: " << it->Anio << std::endl;
    } else {
        std::cout << "Libro no encontrado." << std::endl;
    }
}

void UsarPila(std::list<Libro>& biblioteca, std::stack<Libro>& pilaPrestamos) {
    std::string titulo;
    std::cout << "Ingrese el título del libro que desea prestar: ";
    std::cin >> titulo;

    auto it = std::find_if(biblioteca.begin(), biblioteca.end(), [&](const Libro& libro) {
        return libro.Titulo == titulo;
    });

    if (it != biblioteca.end()) {
        pilaPrestamos.push(*it);   // Añade el libro a la pila de préstamos
        biblioteca.erase(it);       // Remueve el libro de la biblioteca
        std::cout << "El libro '" << titulo << "' ha sido prestado temporalmente." << std::endl;
    } else {
        std::cout << "El libro no está disponible en la biblioteca." << std::endl;
    }
}

void UsarColas(std::queue<std::string>& colaSolicitudes) {
    std::string solicitud;
    std::cout << "Ingrese el título del libro solicitado: ";
    std::cin >> solicitud;

    colaSolicitudes.push(solicitud);
    std::cout << "Solicitud añadida a la cola." << std::endl;

    // Proceso de solicitudes
    while (!colaSolicitudes.empty()) {
        std::cout << "Procesando solicitud: " << colaSolicitudes.front() << std::endl;
        colaSolicitudes.pop();
    }
}



