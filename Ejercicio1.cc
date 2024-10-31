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

int main() {
  std::list<Libro> libreria;
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

//Funcion para comparar por nombre
bool CompararPorTitulo(const Libro& l1, const Libro& l2) {
    return l1.titulo < l2.titulo; // Comparar por nombre
}

// Función para ordenar los libros por titulo usando std::sort
void OrdenarLibrosPortitulo(std::list<Libro>& libreria) {
    libreria.sort(CompararPorTitulo); // Usar el método sort de std::list
}

// Funcion para Buscar un libro
void BuscarLibro(std::list<Libro> libreria, std::string libro_buscado)
{
      std::vector<Libro> vector_libros(libreria.begin(), libreria.end());

}