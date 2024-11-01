#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <stack>

struct Libro {
  std::string titulo;
  std::string autor;
  int year_publicacion;
};

void NuevoLibro(std::list<Libro>& libreria);
bool CompararPorTitulo(const Libro& l1, const Libro& l2);
void OrdenarLibrosPortitulo(std::list<Libro>& libreria);
bool BuscarLibro(std::list<Libro> libreria, std::string libro_titulo_buscado);
void MostrarLibros(std::list<Libro> libreria);

int main() {
  std::list<Libro> libreria;
  std::stack<Libro> pila_lectura;
  return 0;
}

void NuevoLibro(std::list<Libro>& libreria) {
  Libro libro;
  std::cout << "Ingresa el titulo del libro: ";
  std::cin >> libro.titulo;
  std::cout << "Ingresa el autor del libro: ";
  std::cin >> libro.autor;
  std::cout << "Ingresa el año de lanzamiento del libro: ";
  std::cin >> libro.year_publicacion;
  libreria.push_front(libro);
}

// Funcion para comparar por nombre
bool CompararPorTitulo(const Libro& l1, const Libro& l2) {
  return l1.titulo < l2.titulo;  // Comparar por nombre
}

// Función para ordenar los libros por titulo usando std::sort
void OrdenarLibrosPortitulo(std::list<Libro>& libreria) {
  libreria.sort(CompararPorTitulo);  // Usar el método sort de std::list
}

// Funcion para Buscar un libro
bool BuscarLibro(std::list<Libro> libreria, std::string libro_titulo_buscado) {
  // Ordenamos la lista
  OrdenarLibrosPortitulo(libreria);
  // Pasamos la lista a un vector
  std::vector<Libro> vector_libros(libreria.begin(), libreria.end());
  // Creamos temporalmente un objeto de tipo Libro para buscar en el vector
  Libro libroBuscado{libro_titulo_buscado, "", 0};
  // Aplicamos binary_search en el vector
  return std::binary_search(vector_libros.begin(), vector_libros.end(),
                            libroBuscado);
}

// Funcion para mostrar los libros
void MostrarLibros(std::list<Libro> libreria) {
  int i = 1;
  while (!libreria.empty()) {
    // Mostrar el titulo del elemento al frente de la lista
    std::cout << i << " Titulo : " << libreria.front().titulo << std::endl;
    // Eliminar el elemento al frente de la lista
    libreria.pop_front();
    i++;
  }
}

// Extraer los elementos de la pila y agregarlos al inicio del vector
    while (!pila.empty()) {
        vector.insert(vector.begin(), pila.top()); // Agrega el elemento al inicio del vector
        pila.pop(); // Elimina el elemento superior de la pila
    }


